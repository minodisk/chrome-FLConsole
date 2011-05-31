var FLConsole = (function (window) {
  var chrome = window.chrome;
  var $ = window.jQuery;

  var R_ERROR = /^(?:\s*Error|エラー|\d+).*\:/;
  var R_WARN = /(?:^(?:(?:Warning|警告).*\:|SecurityDomain)|^\*{3}.*\*{3}$)/;

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

    var outputList = [];
    var rows = diff.split('\n');
    var i, len, row, methodName, xmlStr, j, $xml, k;
    for (i = 0,len = rows.length; i < len; i++) {
      row = rows[i];
      methodName = detectMethodName(row);
      if (methodName === 'log' && row.search('<') === 0) {
        xmlStr = '';
        for (j = i; j < len; j++) {
          xmlStr += rows[j];
          $xml = $($.parseXML(xmlStr));
          if ($xml.find('parsererror').size() === 0) {
            for (k = 0; k < $xml.length; k++) {
              outputList.push({
                methodName: methodName,
                data: $xml[k].firstChild
              });
            }
            i = j;
            break;
          }
        }
      } else if (methodName === 'error') {
        while ((i + 1) < len && rows[(i + 1)].indexOf('\t') === 0) {
          i++;
          row += '\n' + rows[i].replace(/\t/g, '  ');
        }
        outputList.push({
          methodName: methodName,
          data: row
        });
      } else {
        try {
          row = JSON.parse(row);
        } catch (err) {}
        outputList.push({
          methodName: methodName,
          data: row
        });
      }
    }

    response(sendResponse, tabID, outputList);
  }

  function response(sendResponse, tabID, outputList) {
    var i, len, output;
    var methodNameList = [];
    var dataList = [];
    for (i = 0, len = outputList.length; i < len; i++) {
      output = outputList[i];
      methodNameList[i] = output.methodName;
      dataList[i] = output.data;
    }
    var hash = (new Date()).getTime().toString() +
      (Math.random() * 10000 >> 0).toString();
    hashMap[hash] = dataList;
    sendResponse({
      tabID: tabID,
      methodNameList: methodNameList,
      hash: hash
    });
  }

  chrome.extension.onRequest.addListener(setOutput);

  return {
    getOutput: function (hash, index) {
      var dataList = hashMap[hash];
      var data = dataList[index];
      if (index === dataList.length - 1) {
        delete hashMap[hash];
      }
      return data;
    }
  };

}

  )
  (window);
