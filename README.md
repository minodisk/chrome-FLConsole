# FLConsole

Chrome のコンソールに Flash Player からの出力を表示する拡張機能。

## 特徴
* log/error/warning の切り分け
* 文字化け防止
* XML のツリー表示
* JSON のパース

## 意図した出力がされない可能性のあるケース
* String で数字を出力する場合
* String 内に改行がある場合

## 使用しているライブラリ
* [boost](http://www.boost.org/) : 主に filesystem
* [nixysa](http://code.google.com/p/nixysa/) : NPAPI コード生成
* [babel](http://tricklib.com/cxx/ex/babel/) : 文字コード判定・自動変換

## 参考にしたサイト
* [C++でGoogle Chromeのプラグインを書いてみた - おし、プログラミング](http://d.hatena.ne.jp/ichhi/20110306/1299434439")
