// Copyright 2009 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/range/algorithm/for_each.hpp>
#include "babel.h"
#include "flobserver.h"

FLObserver::FLObserver() {
  fs::path currentPath = fs::current_path();
  fs::path userPath = (currentPath / ".." / ".." / ".." / ".." / ".." / "..").normalize();
  cfgPath = (userPath / "mm.cfg").normalize();
  logPath = (userPath / "Application Data/Macromedia/Flash Player/Logs/flashlog.txt").normalize();
  babel::init_babel();
}

FLObserver::~FLObserver() {
}

string FLObserver::GetLogPath() {
  return logPath.string();
}

void FLObserver::Init(string mmcfg, JSCallback* onError, JSCallback* onChange) {
  CheckBlankAndWrite(cfgPath, mmcfg);
  CheckBlankAndWrite(logPath, "Generated by FLConsole");
  jsOnError = onError;
  jsOnChange = onChange;
  Reset();
}

void FLObserver::CheckBlankAndWrite(fs::path path, string text) {
  if (!fs::exists(path) ||  fs::file_size(path) == 0) {
    fs::ofstream ofs(path);
    ofs << text << endl;
    ofs.close();
  }
}

void FLObserver::Reset() {
  uintmax_t lastFileSize = fs::file_size(logPath);

  lastRow = 0;
  fs::ifstream ifs(logPath);
  if (ifs.fail()) {
    jsOnError->Run("Fail to open log file.");
    return;
  }
  string diff = "";
  string buf;
  while (getline(ifs, buf)) {
    lastRow++;
  }
  lastOff = ifs.tellg();
  ifs.close();
}

void FLObserver::Tick() {
  uintmax_t fileSize = fs::file_size(logPath);
  if (fileSize == lastFileSize) {
    return;
  }
  lastFileSize = fileSize;
  
  fs::ifstream ifs(logPath);
  if (ifs.fail()) {
    jsOnError->Run("Fail to open log file.");
    return;
  }
  string diff = "";
  string buf;
  ifs.seekg(lastOff, ios_base::beg);
  while (getline(ifs, buf)) {
    diff += (string)(babel::auto_translate<>(buf, babel::base_encoding::utf8)) + "\n";
    lastRow++;
  }
  lastOff = ifs.tellg();
  ifs.close();
  if (diff.length() > 0) {
    diff.erase(diff.length() - 1);
    jsOnChange->Run(diff);
  }
}
