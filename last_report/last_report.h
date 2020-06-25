#pragma once

//参照ライブラリ
#pragma once

//参照ライブラリ
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define maze_size 29	//迷路の一辺の長さ(必ず奇数にする必要あり,コンソールの都合上29より大きくすると表示が乱れる)
#define start_x 2		//スタート地点
#define start_y 2
#define goal_x maze_size - 1	//ゴール地点
#define goal_y maze_size - 1

//関数プロトタイプ宣言
void create_maze(int maze[maze_size][maze_size]);
void draw_maze(int maze[maze_size][maze_size]);

void draw_charactor();

//操作キャラクターの現在位置を格納する構造体
typedef struct charactor {
	int char_x = start_x;
	int char_y = start_y;
};