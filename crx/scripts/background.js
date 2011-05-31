var FLConsole = (function (window) {
  var document = window.document;
  var console = window.console;
  var chrome = window.chrome;
  var swfobject = window.swfobject;

  var isDebugMode = true;

  var isDebugger, isNavigatedToDL, active, flconsole, fpcapabilities;

  function init() {
    isDebugger = false;
    isNavigatedToDL = false;
    active = false;
    chrome.browserAction.setIcon({path: 'images/icon_48_disabled.png'});
    window.addEventListener('DOMContentLoaded', onDomContentLoaded, false);
    if (!checkVersion()) {
      openDownloadTab();
    }
    log('init', 'checkVersion()', '=', checkVersion());

    chrome.browserAction.onClicked.addListener(onButtonClicked);
  }

  function onDomContentLoaded() {
    var plugin = document.getElementById('plugin');
    log('onDomContentLoaded',
      'plugin.FLConsole', '=', plugin.FLConsole);
    flconsole = plugin.FLConsole();
  }

  function onFPCapabilitiesReady() {
    fpcapabilities = document['fpcapabilities'];
    if (!fpcapabilities.isDebugger()) {
      openDownloadTab();
    } else {
      if (checkVersion()) {
        chrome.browserAction.setIcon({path: 'images/icon_48_inactive.png'});
      }
    }
    log('onFPCapabilitiesReady',
      'fpcapabilities.isDebugger()', '=', fpcapabilities.isDebugger());
  }

  function onButtonClicked(tab) {
    if (checkVersion() && fpcapabilities.isDebugger()) {
      if (!active) {
        var result = flconsole.listen(onFlashLogChanged);
        log('onButtonClicked', 'flconsole.listen()', '=', result);
        if (result !== 'SUCCESS') {
          alert(result);
          return;
        }
        active = true;
        chrome.browserAction.setIcon({path: 'images/icon_48_active.png'});
      } else {
        flconsole.close();
        active = false;
        chrome.browserAction.setIcon({path: 'images/icon_48_inactive.png'});
      }
    } else {
      active = false;
      chrome.browserAction.setIcon({path: 'images/icon_48_disable.png'});
    }
    log('onButtonClicked', 'checkVersion()', '=', checkVersion(),
      'fpcapabilities.isDebugger()', '=', fpcapabilities.isDebugger(),
      'active', '=', active);
  }

  function onFlashLogChanged(diff) {
    chrome.windows.getLastFocused(function (window) {
      chrome.tabs.getSelected(window.id, function (tab) {
        sendDiff({
          tabID: tab.id,
          diff: diff
        });
      });
    });
  }

  function sendDiff(req) {
    chrome.tabs.sendRequest(req.tabID, req, execOutput);
    log('sendDiff', 'request', '=', req);
  }

  function execOutput(res) {
    var i, len;
    for (i = 0,len = res.methodNameList.length; i < len; i++) {
      chrome.tabs.executeScript(
        res.tabID,
        {
          code: 'console.' + res.methodNameList[i] + '(' +
            'FLConsole.getOutput("' + res.hash + '", ' + i.toString() + ')' +
            ');'
        }
      );
    }
    log('execOutput', 'response', '=', res);
  }

  function checkVersion() {
    var version = swfobject.getFlashPlayerVersion();
    return version && version.major >= 9;
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

  function log() {
    if (isDebugMode) {
      console.log.apply(console, arguments);
    }
  }

  init();

  return {
    onFPCapabilitiesReady: onFPCapabilitiesReady
  };

})(window);
