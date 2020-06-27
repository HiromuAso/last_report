//迷路と操作キャラクター関連のヘッダーファイル

#pragma once

#include "ini_Setting.h"

//参照ライブラリ
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define start_x 1		//スタート地点
#define start_y 1

//操作キャラクターの現在位置を格納する構造体
typedef struct character {
	int char_x = start_x;
	int char_y = start_y;
};

//迷路の一辺の長さ(必ず奇数にする必要あり,コンソールデフォルトの大きさの都合上
//29より大きくすると表示が乱れる)
//const int maze_size = 5; //デフォルト値

//関数プロトタイプ宣言
void create_maze(int** maze, int maze_size);
void draw_maze(int** maze, int maze_size);

void move_character(character* my, int** maze);

