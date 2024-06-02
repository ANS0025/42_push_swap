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

## 実装プロセス
1. スタックの実装方法を検討
2. 使用するアルゴリズムを検討（自分は基数ソートを使用）
3. スタックを実装（自分は双方向リストを使用して、スタックを実装）
4. 各コマンドの実装
5. アルゴリズムの実装
6. テスト&リファクタリング

## コンパイル方法
1. リポジトリをクローン： ```git clone https://github.com/your_username/42_push_swap.git```
2. プロジェクトディレクトリに移動: ```cd 42_push_swap```
3. コンパイル: ```make```

## 使用方法
./push_swap [数字の並び]  
例: ```./push_swap 3 1 4 2 5```  
プログラムは、与えられた数字の並びを昇順にソートするために必要な最小限の操作を標準出力に表示します。

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
