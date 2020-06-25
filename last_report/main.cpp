#include "last_report.h"
#include <time.h>

int main()
{
	// 端末の準備
	initscr();
	//カーソルを非表示
	curs_set(0);

	// 色の準備
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	// 色1に「白地に黒文字」をセット
	attrset(COLOR_PAIR(1));			// 色1 を使う

	//迷路自動生成の2次配列
	int maze_information[maze_size][maze_size];
	
	

	while (1)
	{
		//画面リセット
		erase();

		//現在時刻を乱数のシード値に設定
		srand((unsigned)time(NULL));

		create_maze(maze_information);
		draw_maze(maze_information);

		//迷路描画
		refresh();

		getch();
	}

	return 0;
}