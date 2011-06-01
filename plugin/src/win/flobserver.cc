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
#include "flobserver.h"

FLObserver::FLObserver() {
  this->running = false;
  char currentDirName[MAX_PATH];
  GetCurrentDirectory(sizeof(currentDirName) / sizeof(currentDirName[0]), currentDirName);
  string userDir = currentDirName;
  int i = userDir.find("\\Local Settings\\Application Data\\Google\\Chrome\\");
  userDir.replace(i, MAX_PATH, "");
  this->logPath = userDir + "\\Application Data\\Macromedia\\Flash Player\\Logs\\flashlog.txt";

  babel::init_babel();
}

void FLObserver::Init(JSCallback* onError, JSCallback* onChange) {
  FLObserver::OnTimer((HWND)(-1), 0, (UINT_PTR)this, 0);
  this->onError = onError;
  this->onChange = onChange;
}

FLObserver::~FLObserver() {
  this->Stop();
}

string FLObserver::GetLogPath() {
  return this->logPath;
}

void FLObserver::Start() {
  WIN32_FIND_DATA wfd;
  HANDLE h = ::FindFirstFile(this->logPath.c_str(), &wfd);
  if (h == INVALID_HANDLE_VALUE) {
    this->onError->Run("NOT FOUND\n" + this->logPath);
    return;
  }
  ::FindClose(h);

  if (!this->running) {
    this->running = true;
    this->lastModTime = this->GetModTime(this->logPath);
    this->GetDiff(this->logPath);
    this->timerID = ::SetTimer(NULL, 0, 100, OnTimer);
  }
}

void FLObserver::Stop() {
  if (this->running) {
    this->running = false;
    KillTimer(NULL, this->timerID);
  }
}

void CALLBACK FLObserver::OnTimer(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime) {
  static FLObserver* flobserver;
  if ((int)hwnd == -1 && flobserver == NULL) {
    flobserver = (FLObserver *)idEvent;
    return;
  }
  flobserver->DetectMod();
}

void FLObserver::DetectMod() {
  FILETIME modTime = this->GetModTime(this->logPath);
  if (::CompareFileTime(&this->lastModTime, &modTime) != 0) {
    this->lastModTime = modTime;
    this->onChange->Run(this->GetDiff(this->logPath));
  }
}

FILETIME FLObserver::GetModTime(string path) {
  WIN32_FIND_DATA wfd;
  HANDLE h = ::FindFirstFile(path.c_str(), &wfd);
  if (h == INVALID_HANDLE_VALUE) {
    this->onError->Run("NOT FOUND\n" + this->logPath);
    FILETIME time;
    SYSTEMTIME st;
    GetLocalTime(&st);
    SystemTimeToFileTime(&st, &time);
    return time;
  }
  ::FindClose(h);
  return wfd.ftLastWriteTime;
}

string FLObserver::GetDiff(string path) {
  UINT row = 0;
  ifstream ifs(path);
  string diff = "";
  string buf;
  if (ifs.fail()) {
    this->onError->Run("NOT FOUND\n" + this->logPath);
    return "";
  }
  while (getline(ifs, buf)) {
    row++;
    if (row != lastModRow) {
      diff += (string)(babel::auto_translate<>(buf, babel::base_encoding::utf8)) + "\n";
    } else {
      diff = "";
    }
  }
  lastModRow = row;
  if (diff.length() > 0) {
    diff.erase(diff.length() - 1);
  }
  return diff;
}
