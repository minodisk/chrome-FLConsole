var FLConsole = (function (window) {
  var document = window.document;
  var chrome = window.chrome;
  var swfobject = window.swfobject;

  var extId, dlPageOpened, running, intervalId, flobserver, fpcapabilities;

  console.log('FLConsole Status Log');
  function init() {
    console.log('-init');
    extId = location.host;
    dlPageOpened = false;
    disabled();
    if (!swfobject.hasFlashPlayerVersion('9')) {
      openDLPage(getMSG('fp_lt9'));
    }
    window.addEventListener('DOMContentLoaded', function (e) {
      flobserver = document.getElementById('flobserver').FLObserver();
      console.log(flobserver.getMmcfgPath());
      console.log(flobserver.getTrustcfgPath());
      console.log(flobserver.getLogPath());
      var xhr = new XMLHttpRequest();
      xhr.addEventListener('readystatechange', function (e) {
        if (xhr.readyState === 4) {
          if (flobserver.init(onError, onChange, location.origin, xhr.responseText)) {
            location.reload();
          } else {
            swfobject.embedSWF('fpcapabilities.swf', 'fpcapabilities',
              '100', '100', '9', 'expressInstall.swf', {
                onReady: 'FLConsole.onFPCapabilitiesReady'
              }, {
                allowScriptAccess: 'always'
              }, {
              }, function (result) {
                if (!result.success) {
                  throw new Error('Fail to embed fpcapabilities.swf.');
                }
                fpcapabilities = result.ref;
              });
          }
        }
      }, false);
      xhr.open('GET', chrome.extension.getURL('resources/mm.cfg'), true);
      xhr.send();
    }, false);
  }

  function onFPCapabilitiesReady() {
    console.log('-ready');
    if (!fpcapabilities.isDebugger()) {
      openDLPage(getMSG('fp_notDebugger'));
    }
    start();
    chrome.browserAction.onClicked.addListener(onButtonClicked);
  }

  function openDLPage(msg) {
    console.log('-openDLPage');
    if (!dlPageOpened) {
      dlPageOpened = true;
      chrome.tabs.create({
          url: 'http://www.adobe.com/support/flashplayer/downloads.html'
        }, function (tab) {
          alert(msg + getMSG('fp_setting'));
        });
    }
    throw new Error(msg);
  }

  function start() {
    console.log('-start');
    running = true;
    if (intervalId) {
      clearInterval(intervalId);
    }
    flobserver.reset();
    intervalId = setInterval(onTick, 100);
    chrome.browserAction.setIcon({path: 'images/icon_19_active.png'});
    chrome.browserAction.setBadgeText({text: ''});
  }

  function onTick() {
    flobserver.tick();
  }

  function stop() {
    console.log('-stop');
    running = false;
    if (intervalId) {
      clearInterval(intervalId);
      intervalId = null;
    }
    chrome.browserAction.setIcon({path: 'images/icon_19_inactive.png'});
    chrome.browserAction.setBadgeText({text: ''});
  }

  function disabled() {
    if (running) {
      console.log('-disabled');
      stop();
    }
    chrome.browserAction.setIcon({path: 'images/icon_19_inactive.png'});
    chrome.browserAction.setBadgeText({text: 'x'});
  }

  function onButtonClicked(tab) {
    console.log('-buttonClicked');
    if (!running) {
      start();
    } else {
      stop();
    }
  }

  function onError(msg) {
    console.log('-error');
    disabled();
    alert(msg);
    throw new Error(msg);
  }

  function onChange(diff) {
    chrome.windows.getLastFocused(function (window) {
      chrome.tabs.getSelected(window.id, function (tab) {
        chrome.tabs.sendRequest(tab.id, {
          tabID: tab.id,
          diff: diff
        }, execOutput);
      });
    });
  }

  function execOutput(res) {
    var i, len;
    for (i = 0,len = res.methodNameList.length; i < len; i++) {
      chrome.tabs.executeScript(
        res.tabID,
        {
          code: 'console.' + res.methodNameList[i] + '(' +
            'FLOutput.find("' + res.hash + '", ' + i.toString() + ')' +
            ');'
        }
      );
    }
  }

  function getMSG(key) {
    return chrome.i18n.getMessage('bg_' + key);
  }

  init();

  return {
    onFPCapabilitiesReady: onFPCapabilitiesReady
  };

})(window);