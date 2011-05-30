var FLConsole = (function (window) {
  var chrome = window.chrome;
  var $ = window.jQuery;

  var R_ERROR = /^(?:\s*Error|エラー|\d+).*\:/;
  var R_WARN = /(?:^(?:(?:Warning|警告).*\:|SecurityDomain)|^\*{3}.*\*{3}$)/;
  var ZERO = Math.pow(10, 17);

  var hashMap = {};

  function setOutput(request, sender, sendResponse) {
    var tabID = request.tabID;
    var diff = request.diff;

    var detectMethodName = function (row) {
      if (row.search(R_ERROR) !== -1) {
        return 'error';
      } else if (row.search(R_WARN) !== -1) {
        return 'warn';
      }
      return 'log';
    };

    var rows = diff.split('\n');
    var i, len, row, methodName, xmlStr, j, $xml;
    for (i = 0,len = rows.length; i < len; i++) {
      row = rows[i];
      methodName = detectMethodName(row);
      if (methodName === 'log' && row.search('<') === 0) {
        xmlStr = '';
        for (j = i; j < len; j++) {
          xmlStr += rows[j];
          $xml = $($.parseXML(xmlStr));
          if ($xml.find('parsererror').size() === 0) {
            i = j;
            for (j = 0; j < $xml.length; j++) {
              response(sendResponse, tabID, methodName, $xml[j].firstChild);
            }
            break;
          }
        }
      } else if (methodName === 'error') {
        var error = row;
        while ((i + 1) < len && rows[(i + 1)].indexOf('\t') === 0) {
          i++;
          error += '\\n' + rows[i];
        }
        response(sendResponse, tabID, methodName, error);
      } else {
        response(sendResponse, tabID, methodName, row);
      }
    }
  }

  function response(sendResponse, tabID, methodName, data) {
    var hash = (new Date()).getTime().toString() + (Math.random() * ZERO).toString();
    hashMap[hash] = data;
    sendResponse({
      tabID: tabID,
      methodName: methodName,
      hash: hash
    });
  }

  chrome.extension.onRequest.addListener(setOutput);

  return {
    getOutput: function (hash) {
      var data = hashMap[hash];
      delete hashMap[hash];
      return data;
    }
  };

})(window);
