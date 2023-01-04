# cub3D
## 目的
42Tokyoの課題の一つ。</br>
レイトレーシングの技術を使用。</br>

## デモ
https://user-images.githubusercontent.com/57135683/210556251-60177ceb-103e-47d2-b809-eb800c08c5cb.mp4

## 概要
以下のような２次元のマップ（以下cubファイル）の入力から３次元のマップを出力する。

- 壁の向き（北、南、東、西）によって異なる壁の質感を表示（選択可能）。
- 壁の向き（北、南、東、西）に応じて異なるテクスチャーを表示します。

## インストールと起動方法
```
$ git clone https://github.com/RIshimoto/cub3D
$ cd cub3D
$ make
$ ./cub3D Correct/correct2.cub
```

## 操作方法
- 左右の矢印キーで、迷路を左右に見ることができる。
- W、A、S、および D キーを使用して、迷路内で視点を移動できる。
- ESCでウィンドウを閉じる。
- 実行時に--saveオプションを付けると最初のレンダリングイメージを bmp フォーマットで保存できる。

## テストツール
https://github.com/RIshimoto/cub3D-error_file_test
