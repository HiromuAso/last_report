#include "maze_and_character.h"
#include "ini_Setting.h"

#include <time.h>

int main()
{
	//ファイル入出力のためにカレントディレクトリを取得
	char currentDirectory[CHARBUFF];
	getCurrentDirectory(currentDirectory);
	//iniファイル名を格納したchar型変数を用意
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\Setting.ini", currentDirectory);
	//iniファイル読み込み
	int v_int =	readInt("maze_size", "size", -1, settingFile);

	// 端末の準備
	initscr();
	//カーソルを非表示
	curs_set(0);
	//キーを押したらすぐにその文字がプログラムから読み取れるようにする
	cbreak();
	//入力したキーを画面に表示しないようにする
	noecho();
	//矢印キーやファンクションキーなどの特殊キーを利用可能にする
	keypad(stdscr, TRUE);

	// 色の準備
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	// 色1に「白地に黒文字」をセット
	attrset(COLOR_PAIR(1));	// 色1 を使う

	//迷路自動生成の2次配列
	int maze_information[maze_size][maze_size];

	//現在時刻を基に乱数のシード値を設定 (randの値が固定されるのを防ぐため)
	srand((unsigned)time(NULL));
	//迷路ランダム生成
	create_maze(maze_information);

	//操作キャラクターの現在地を設定
	struct character my;
	int char_x = start_x;
	int char_y = start_y;

	while (1)
	{
		//画面リセット
		erase();

		//ランダム生成した迷路を表示
		draw_maze(maze_information);

		//操作キャラクター描画
		mvaddstr(my.char_y + 1, 2 * my.char_x + 2, "○");
		//操作キャラクター移動
		move_character(&my, maze_information);

		//ゴールで終了
		if (maze_information[my.char_x][my.char_y] == 2) break;
	
		//全てを描画
		refresh();
	}
	erase();
	draw_maze(maze_information);
	//操作キャラクター描画
	mvaddstr(my.char_y + 1, 2 * my.char_x + 2, "○");

	mvaddstr(my.char_y + 1, 2 * my.char_x + 8, "Goal!!");
	mvaddstr(my.char_y + 2, 2 * my.char_x + 8, "Please push 'q' key");
	refresh();

	while (1)
	{
		int end_key = getch();
		if (end_key == 'q') break; //'q'キーを押したら終了
	}

	return 0;
}