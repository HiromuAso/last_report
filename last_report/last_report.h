#pragma once

//参照ライブラリ
#pragma once

//参照ライブラリ
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define maze_size 29	//迷路(正方形)の一辺の長さ(必ず奇数にする必要あり)

//関数プロトタイプ宣言
void create_maze(int maze[maze_size][maze_size]);
void draw_maze(int maze[maze_size][maze_size]);