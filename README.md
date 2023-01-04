# cub3D
## 目的
42Tokyoの課題の一つ。</br>
レイトレーシング[^1]の技術の練習として。</br>

[^1]:レイトレーシング：https://ja.scratch-wiki.info/wiki/%E3%83%AC%E3%82%A4%E3%82%AD%E3%83%A3%E3%82%B9%E3%83%86%E3%82%A3%E3%83%B3%E3%82%B0

## 概要
レイトレーシングの技術を用いて以下のような２次元のマップの入力から３次元のマップを出力する。（デモ参照）

```simple_map.cub
R 1920 1080
NO ./path_to_the_north_texture
SO ./path_to_the_sorth_texture
WE ./path_to_the_west_texture
EA ./path_to_the_east_texture
S ./path_to_the_sprite_texture
F 220,100,0
C 225,30,0 

111111
100101
102001
1100N1
111111
```
- R:レンダリングサイズ
- NO:北側の壁のテクスチャ
- SO:南側の壁のテクスチャ
- WE:西側の壁のテクスチャ
- EA:東側の壁のテクスチャ
- S:マップ内のアイテムのテクスチャ
- F:床の色（RGB)
- C:天井の色（RGB)
- マップ
  - 0:何もない空間
  - 1:壁
  - 2:アイテム
  - N,S,E,W：プレイヤーのスタート位置とスポ-ンの際の方向（それぞれNorth,South,East, Westのこと）
上記のフォーマットに従っていない場合は```Error\n```を出力。

## デモ
https://user-images.githubusercontent.com/57135683/210556251-60177ceb-103e-47d2-b809-eb800c08c5cb.mp4
今回、イルカ（友人作）がアイテム

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

## 自作テストツール
https://github.com/RIshimoto/cub3D-error_file_test
