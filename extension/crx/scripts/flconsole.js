var FLConsole = (function (window, document, chrome, swfobject) {
  var isDebugger, isNavigatedToDL, active, flobserver, fpcapabilities;

  function init() {
    isDebugger = false;
    isNavigatedToDL = false;
    active = false;
    disabled();
    window.addEventListener('DOMContentLoaded', onDomContentLoaded, false);
    if (!checkVersion()) {
      openDownloadTab();
    }
    chrome.browserAction.onClicked.addListener(onButtonClicked);
  }

  function onDomContentLoaded() {
    var plugin = document.getElementById('flobserver');
    flobserver = plugin.FLObserver();
    console.log(flobserver.init(onError, onChange));
    autoStart();
  }

  function onFPCapabilitiesReady() {
    fpcapabilities = document.getElementById('fpcapabilities');
    if (!fpcapabilities.isDebugger()) {
      openDownloadTab();
    } else {
      if (checkVersion()) {
        autoStart();
      }
    }
  }

  function autoStart() {
    if (checkRequirement()) {
      start();
    }
  }

  function start() {
    active = true;
    flobserver.start();
    chrome.browserAction.setIcon({path: 'images/icon_48_active.png'});
  }

  function stop() {
    active = false;
    flobserver.stop();
    chrome.browserAction.setIcon({path: 'images/icon_48_inactive.png'});
  }

  function disabled() {
    if (active) {
      stop();
    }
    chrome.browserAction.setIcon({path: 'images/icon_48_disable.png'});
  }

  function onButtonClicked(tab) {
    if (checkRequirement()) {
      if (!active) {
        start();
      } else {
        stop();
      }
    } else {
      disabled();
    }
  }

  function onError(msg) {
    alert(msg);
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

  function checkRequirement() {
    return flobserver && checkVersion() &&
      fpcapabilities && fpcapabilities.isDebugger();
  }

  function checkVersion() {
    return swfobject.getFlashPlayerVersion().major >= 9;
  }

  function openDownloadTab() {
    if (!isNavigatedToDL) {
      isNavigatedToDL = true;
      chrome.tabs.create({
          url: 'http://www.adobe.com/support/flashplayer/downloads.html'
        }, function (tab) {
          alert('FPConsole needs Flash Debugger Player (version9 or above).\n' +
            'Download installer from this page.');
        });
    }
  }

  init();

  return {
    onFPCapabilitiesReady: onFPCapabilitiesReady
  };

})(window, document, chrome, swfobject);
