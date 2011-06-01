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

#ifndef FLOBSERVER_H
#define FLOBSERVER_H

#include <string>

using namespace std;

class FLObserver {

public:
  class JSCallback {
  public:
    virtual void Run(const string& str) = 0;
  };

  FLObserver();
  void Init(JSCallback* onError, JSCallback* onChange);
  ~FLObserver();

  string GetLogPath();
  void Start();
  void Stop();

private:
  JSCallback *onError;
  JSCallback *onChange;
  
  bool running;
  string logPath;
  UINT_PTR timerID;
  FILETIME lastModTime;
  UINT lastModRow;

  static void CALLBACK OnTimer(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime);
  void DetectMod();
  FILETIME GetModTime(string path);
  string GetDiff(string path);
  string ConvertEncoding(string srcStr, string fromEnc, string toEnc);

};

#endif  // FLOBSERVER_H
