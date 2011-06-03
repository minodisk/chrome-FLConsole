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
#include <boost/filesystem/path.hpp>

using namespace std;
namespace fs = boost::filesystem;

class FLObserver {

public:
  class JSCallback {
  public:
    virtual void Run(const string& str) = 0;
  };

  FLObserver();
  ~FLObserver();

  string GetLogPath();

  void Init(string mmcfg, JSCallback* onError, JSCallback* onChange);
  void Reset();
  void Tick();

private:
  fs::path cfgPath;
  fs::path logPath;
  JSCallback *jsOnError;
  JSCallback *jsOnChange;
  
  uintmax_t lastFileSize;
  unsigned int lastRow;
  streamoff lastOff;
  void CheckBlankAndWrite(fs::path path, string text);

};

#endif  // FLOBSERVER_H
