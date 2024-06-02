## 概要
push_swapは、2つのスタックを使用して与えられた整数を効率的にソートするアルゴリズムを実装するプロジェクト。  
このプロジェクトは、42東京のカリキュラムの一部であり、学生がアルゴリズムとデータ構造の理解を深めることを目的としている。

## プロジェクトの目的
このプロジェクトの主な目的：
- スタックを使ったソートアルゴリズムの実装方法を学ぶ
- 効率的なソートアルゴリズムを設計する
- C言語でのプログラミングスキルを向上させる

このプロジェクトを通して、身につけられるスキル：
- 基本的なアルゴリズムの理解と実装
- 様々なデータ構造の理解と活用
- アルゴリズムの計算量

## プロジェクトを解くための前提知識
- 構造体について
- データ構造の理解（時にスタックとリスト構造）
- 基本的なアルゴリズム

## 実装プロセス
1. スタックの実装方法を検討
2. 使用するアルゴリズムを検討（今回は基数ソートを使用）
3. スタックを実装（今回は双方向リストを使用して、スタックを実装）
4. 各コマンドの実装
5. アルゴリズムの実装
6. テスト&リファクタリング

## コンパイル方法
1. リポジトリをクローン： ```git clone git@github.com:ANS0025/42_push_swap.git```
2. プロジェクトディレクトリに移動: ```cd 42_push_swap```
3. コンパイル: ```make```

## 使用方法
- ```./push_swap 3 1 4 2 5```
  与えられた数字の並びを昇順にソートするために必要な最小限のコマンドを標準出力します。
- ```ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l```
  与えられた数字の並びを昇順にソートするために必要なコマンド数を標準出力します。

## テスト方法
https://github.com/nafuka11/push_swap_tester  
これらのテスターを使用する場合は、それぞれのREADMEファイルに従ってセットアップとテストを行ってください。

## コマンド一覧
- sa : スタックaの先頭の2つの要素を入れ替える
- sb : スタックbの先頭の2つの要素を入れ替える
- ss : saとsbを同時に行う
- pa : スタックbの先頭の要素をスタックaに移動する
- pb : スタックaの先頭の要素をスタックbに移動する
- ra : スタックaの要素を1つ上にずらす（先頭の要素は最後尾に移動）
- rb : スタックbの要素を1つ上にずらす（先頭の要素は最後尾に移動）
- rr : raとrbを同時に行う
- rra : スタックaの要素を1つ下にずらす（最後尾の要素は先頭に移動）
- rrb : スタックbの要素を1つ下にずらす（最後尾の要素は先頭に移動）
- rrr : rraとrrbを同時に行う

## 参考資料
- [Push Swap — A journey to find most efficient sorting algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [やさしいC アルゴリズム編](https://www.amazon.co.jp/%E3%82%84%E3%81%95%E3%81%97%E3%81%84C-%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E7%B7%A8-%E3%82%84%E3%81%95%E3%81%97%E3%81%84%E3%82%B7%E3%83%AA%E3%83%BC%E3%82%BA-%E9%AB%98%E6%A9%8B-%E9%BA%BB%E5%A5%88/dp/4797368543)
- [新・明解C言語で学ぶアルゴリズムとデータ構造](https://www.amazon.co.jp/%E6%96%B0%E3%83%BB%E6%98%8E%E8%A7%A3C%E8%A8%80%E8%AA%9E%E3%81%A7%E5%AD%A6%E3%81%B6%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E3%81%A8%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0%E7%AC%AC2%E7%89%88-%E6%9F%B4%E7%94%B0%E6%9C%9B%E6%B4%8B/dp/4815609780/ref=sr_1_1?__mk_ja_JP=%E3%82%AB%E3%82%BF%E3%82%AB%E3%83%8A&crid=29INJZUHDDRC&dib=eyJ2IjoiMSJ9._sfevAzFszNhR2OZt5rWtykVUbZ2bblonv34U4YtYxC6rBoRv25SsVrQ3hwvGq5wX107CO9FJ1CZrVTaOcKcgnr_Vnc5nMKZy9Rp41UVJcXXo2BowBdzQGy5cnVlbbYg7HqzhgpZ7YUy8dE2A4ozWGqwyLl8tQzxuCxgd7fHH5qrGUIC2zlbyKbF0BJ213959Pi-JySi3Z3XbM6MMwMGDBIKNrkFLRGDzuzx6Vpzw3c.ova7XjIYsfs0uoM94ZJ99VVWi-DA6-AueK0phvd0wDs&dib_tag=se&keywords=C%E8%A8%80%E8%AA%9E%E3%81%A7%E5%AD%A6%E3%81%B6%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E3%81%A8%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0&qid=1717338375&s=books&sprefix=c%E8%A8%80%E8%AA%9E%E3%81%A7%E5%AD%A6%E3%81%B6%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0%E3%81%A8%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0%2Cstripbooks%2C145&sr=1-1)
