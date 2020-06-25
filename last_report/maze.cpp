#include "last_report.h"

//迷路を自動生成
void create_maze(int maze[11][11])
{
	//まず外枠を1で埋める
	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 11; y++)
		{
			if (x == 0 || x == 9 || y == 0 || y == 9) {
				maze[x][y] = 1;
			}
		}
	}


}

//自動生成した迷路を描画
void draw_maze(int maze[11][11])
{
	// 端末の準備
	initscr();
	//カーソルを非表示
	curs_set(0);

	// 色の準備
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	// 色1に「白地に黒文字」をセット
	attrset(COLOR_PAIR(1));			// 色1 を使う

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (maze[x][y] == 1) {
				mvaddstr(y + 10, 2 * x + 10, "■");
			}
		}
	}

	//迷路描画
	refresh();
}
