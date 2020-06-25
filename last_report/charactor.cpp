#include "last_report.h"

void draw_charactor()
{
	struct charactor my;

	//操作キャラクター描画
	mvaddstr(my.char_y, 2 * my.char_x, "○");

	int key = getch(); //文字入力受付

	if (key == KEY_RIGHT)
	{
		if (my.char_x + 1 != 1) my.char_x++; //右移動
	}
	if (key == KEY_LEFT)
	{
		if (my.char_x - 1 != 1) my.char_x--; //左移動
	}
	if (key == KEY_DOWN)
	{
		if (my.char_y + 1 != 1) my.char_y++; //下移動
	}
	if (key == KEY_UP)
	{
		if (my.char_y - 1 != 1) my.char_y--; //上移動
	}

}