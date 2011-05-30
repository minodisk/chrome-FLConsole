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

#include <Windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include "babel.h"
#include "flconsole.h"

FLConsole::FLConsole() {
  babel::init_babel();

  char currentDirName[MAX_PATH];
  GetCurrentDirectory(sizeof(currentDirName) / sizeof(currentDirName[0]),
                      currentDirName);
  
  string userDir = currentDirName;
  int i = userDir.find("\\Local Settings\\Application Data\\Google\\Chrome\\");
  userDir.replace(i, MAX_PATH, "");

  this->defaultLogPath = this->logPath = userDir + "\\Application Data\\Macromedia\\Flash Player\\Logs\\flashlog.txt";
  this->changeCallback = NULL;
}

FLConsole::~FLConsole() {
  this->Close();
}

string FLConsole::GetDefaultLogPath() {
  return this->defaultLogPath;
}

string FLConsole::GetLogPath() {
  return this->logPath;
}

void FLConsole::SetLogPath(string path) {
  this->logPath = path;
}

void FLConsole::Listen(ChangeCallback* changeCallback) {
  if (this->changeCallback == NULL) {
    this->GetLog(this->logPath);
    this->changeCallback = changeCallback;
    FLConsole::OnTimer((HWND)(-1), 0, (UINT_PTR)this, 0);
    this->timerID = ::SetTimer(NULL, 0, 100, OnTimer);
  }
}

void CALLBACK FLConsole::OnTimer(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime) {
  static FLConsole* flconsole;
  if ((int)hwnd == -1) {
    flconsole = (FLConsole *)idEvent;
    return;
  }
  flconsole->DetectMod();
}

void FLConsole::DetectMod() {
  FILETIME modTime = this->GetModTime(this->logPath);
  if (::CompareFileTime(&this->lastModTime, &modTime) != 0) {
    this->lastModTime = modTime;
    this->OnChange();
  }
}

void FLConsole::OnChange() {
  this->changeCallback->Run(this->GetLog(this->logPath));
}

void FLConsole::Close() {
  if (this->changeCallback != NULL) {
    KillTimer(NULL, this->timerID);
    this->changeCallback = NULL;
  }
}

FILETIME FLConsole::GetModTime(string path) {
  WIN32_FIND_DATA wfd;
  HANDLE h = ::FindFirstFile(path.c_str(), &wfd);
  if (h == INVALID_HANDLE_VALUE) {
    throw runtime_error("file not found");
  }
  ::FindClose(h);
  return wfd.ftLastWriteTime;
}

string FLConsole::GetLog(string path) {
  UINT row = 0;
  ifstream ifs(path);
  string str = "";
  string buf;
  if (ifs == NULL || ifs.fail()) {
    return "fail";
  }
  while (getline(ifs, buf)) {
    row++;
    if (row != lastModRow) {
      str += (string)(babel::auto_translate<>(buf, babel::base_encoding::utf8)) + "\n";
    } else {
      str = "";
    }
  }
  str.erase(str.length() - 1);
  lastModRow = row;
  return str;
}
