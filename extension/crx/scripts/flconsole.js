var FLConsole = (function (window, document, chrome, swfobject) {
  var dlPageOpened, running, intervalId, flobserver, fpcapabilities;

  console.log('FLConsole Status Log');

  function init() {
    console.log('-init');
    dlPageOpened = false;
    disabled();
    if (!swfobject.hasFlashPlayerVersion('9')) {
      openDLPage('The version of active Flash Player is less than 9.');
    }
    window.addEventListener('DOMContentLoaded', function (e) {
      flobserver = document.getElementById('flobserver').FLObserver();
      console.log(flobserver.getLogPath())
      var xhr = new XMLHttpRequest();
      xhr.addEventListener('readystatechange', function (e) {
        if (xhr.readyState === 4) {
          flobserver.init(xhr.responseText, onError, onChange);
          swfobject.embedSWF('fpcapabilities.swf', 'fpcapabilities',
            '0', '0', '9', 'expressInstall.swf', {
              onReady: 'FLConsole.onFPCapabilitiesReady'
            }, {
              allowScriptAccess: 'always'
            }, {}, function (result) {
              if (!result.success) {
                throw new Error('Fail to embed fpcapabilities.swf.');
              }
              fpcapabilities = result.ref;
            });
        }
      }, false);
      xhr.open('GET', chrome.extension.getURL('resources/mm.cfg'), true);
      xhr.send();
    }, false);
  }

  function onFPCapabilitiesReady() {
    console.log('-ready');
    if (!fpcapabilities.isDebugger()) {
      openDLPage('Active Flash Player is not debugger.');
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
          alert(msg + '\n' +
            'Download and install version9 or above debugger from this page.');
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
    chrome.browserAction.setIcon({path: 'images/icon_48_active.png'});
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
    chrome.browserAction.setIcon({path: 'images/icon_48_inactive.png'});
  }

  function disabled() {
    if (running) {
      console.log('-disabled');
      stop();
    }
    chrome.browserAction.setIcon({path: 'images/icon_48_disable.png'});
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
    alert(msg);
    disabled();
  }

  function onChange(diff) {
    console.log(diff);
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

  init();

  return {
    onFPCapabilitiesReady: onFPCapabilitiesReady
  };

})(window, document, chrome, swfobject);
