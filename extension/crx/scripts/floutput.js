var FLOutput = (function (chrome) {
  var ERROR = 'error';
  var WARN = 'warn';
  var LOG = 'log';
  var R_ERROR = /^(?:\s*Error|エラー|\d+).*\:/;
  var R_WARN = /(?:^(?:(?:Warning|警告).*\:|SecurityDomain)|^\*{3}.*\*{3}$|で許可されません$)/;

  var db = {};

  function _save(request, sender, sendResponse) {
    var tabID = request.tabID;
    var outputList = _parse(request.diff);

    var i, len, output;
    var methodNameList = [];
    var dataList = [];
    for (i = 0,len = outputList.length; i < len; i++) {
      output = outputList[i];
      methodNameList[i] = output.methodName;
      dataList[i] = output.data;
    }
    var hash = (new Date()).getTime().toString() +
      (Math.random() * 10000 >> 0).toString();
    db[hash] = dataList;
    sendResponse({
      tabID: tabID,
      hash: hash,
      methodNameList: methodNameList
    });
  }

  function _find(hash, index) {
    var dataList = db[hash];
    var data = dataList[index];
    if (index === dataList.length - 1) {
      delete db[hash];
    }
    return data;
  }

  function _parse(diff) {
    var outputs = [];
    var rows = diff.split('\n');
    var i, len, row, methodName, xmlStr, j, $xml, k;
    for (i = 0,len = rows.length; i < len; i++) {
      row = rows[i];
      methodName = _detectMethodName(row);
      if (methodName === LOG && row.search('<') === 0) {
        xmlStr = '';
        for (j = i; j < len; j++) {
          xmlStr += rows[j];
          $xml = $($.parseXML(xmlStr));
          if ($xml.find('parsererror').size() === 0) {
            for (k = 0; k < $xml.length; k++) {
              outputs.push({
                methodName: methodName,
                data: $xml[k].firstChild
              });
            }
            i = j;
            break;
          }
        }
      } else if (methodName === ERROR) {
        while ((i + 1) < len && rows[(i + 1)].indexOf('\t') === 0) {
          i++;
          row += '\n' + rows[i].replace(/\t/g, '    ');
        }
        outputs.push({
          methodName: methodName,
          data: row
        });
      } else {
        try {
          row = JSON.parse(row);
        } catch (err) {
        }
        outputs.push({
          methodName: methodName,
          data: row
        });
      }
    }
    return outputs;
  }

  function _detectMethodName(row) {
    if (row.search(R_ERROR) !== -1) {
      return ERROR;
    } else if (row.search(R_WARN) !== -1) {
      return WARN;
    }
    return LOG;
  }

  chrome.extension.onRequest.addListener(_save);

  return {
    find: _find
  };

})(chrome);
