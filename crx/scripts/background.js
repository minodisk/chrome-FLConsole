(function (window) {
  var document = window.document;
  var chrome = window.chrome;

  var active, flconsole;

  function init() {
    active = false;
    chrome.browserAction.setIcon({path: 'images/icon_48_inactive.png'});
    window.addEventListener('DOMContentLoaded', onDomContentLoaded, false);
    chrome.browserAction.onClicked.addListener(onButtonClicked);
  }

  function onDomContentLoaded() {
    var plugin = document.getElementById('plugin');
    flconsole = plugin.FLConsole();
  }

  function onButtonClicked(tab) {
    active = !active;
    if (active) {
      chrome.browserAction.setIcon({path: 'images/icon_48_active.png'});
      flconsole.listen(onFlashLogChanged);
    } else {
      chrome.browserAction.setIcon({path: 'images/icon_48_inactive.png'});
      flconsole.close();
    }
  }

  function onFlashLogChanged(diff) {
    diff = diff.replace(/\\/g, '\\\\').replace(/'/g, '\\\'');
    chrome.windows.getLastFocused(function (window) {
      chrome.tabs.getSelected(window.id, function (tab) {
        sendDiff({
          tabID: tab.id,
          diff: diff
        });
      });
    });
  }

  function sendDiff(request) {
    chrome.tabs.sendRequest(request.tabID, request, execOutput);
  }

  function execOutput(response) {
    chrome.tabs.executeScript(
      response.tabID,
      {
        code: 'console.' + response.methodName + '(' +
          'FLConsole.getOutput("' + response.hash + '")' +
          ');'
      }
    );
  }

  init();

})(window);
