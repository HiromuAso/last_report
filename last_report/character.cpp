//操作キャラクター関連のcppファイル

#include "maze_and_character.h"

//操作キャラクターを移動
void move_character(character* my, int maze[maze_size][maze_size])
{
	int key = getch(); //文字入力受付

	if (key == KEY_RIGHT)
	{
		if (maze[my->char_x + 1][my->char_y] != 1) my->char_x++; //移動先に壁がなければ右移動
	}
	if (key == KEY_LEFT)
	{
		if (maze[my->char_x - 1][my->char_y] != 1) my->char_x--; //左移動
	}
	if (key == KEY_DOWN)
	{
		if (maze[my->char_x][my->char_y + 1] != 1) my->char_y++; //下移動
	}
	if (key == KEY_UP)
	{
		if (maze[my->char_x][my->char_y - 1] != 1) my->char_y--; //上移動
	}

}