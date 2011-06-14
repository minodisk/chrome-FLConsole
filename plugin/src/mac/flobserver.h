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
  
  string GetMmcfgPath();
  string GetTrustcfgPath();
  string GetLogPath();

  bool Init(JSCallback* onError, JSCallback* onChange, string url, string mmcfg);
  void Reset();
  void Tick();

private:
  fs::path mmcfgPath;
  fs::path trustcfgPath;
  fs::path logPath;
  JSCallback *jsOnError;
  JSCallback *jsOnChange;
  
  uintmax_t lastFileSize;
  unsigned int lastRow;

  bool GenerateFile(fs::path path, string text);

};

#endif  // FLOBSERVER_H
