#include "maze_and_character.h"
#include "ini_Setting.h"

#include <iostream>
#include <string>
#include <time.h>

int main()
{
	//ファイル入力のためにカレントディレクトリを取得
	char currentDirectory[CHARBUFF];
	getCurrentDirectory(currentDirectory);
	//iniファイル名を格納したchar型変数を用意
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\Setting.ini", currentDirectory);
	//iniファイル読み込み
	int maze_size_int =	readInt("maze_size", "size", -1, settingFile);
	int window_size_x = readInt("window_size", "size_x", -1, settingFile);
	int window_size_y = readInt("window_size", "size_y", -1, settingFile);

	// 端末の準備
	initscr();
	//ウィンドウの大きさを設定
	getmaxyx(stdscr, window_size_y, window_size_x);
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
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	// 色1に「黒地に白文字」をセット
	init_pair(2, COLOR_RED, COLOR_BLACK);	// 色2に「黒地に赤文字」をセット
	attrset(COLOR_PAIR(1) | A_BOLD);	// 色1 を使う + 太字にする

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

	//何手目かをカウント
	int count = 0;

	while (1)
	{
		//画面リセット
		erase();

		//ランダム生成した迷路を表示
		draw_maze(maze_information);

		//簡易説明
		mvaddstr(2, 2 * maze_size + 8, "You  = ○");
		mvaddstr(4, 2 * maze_size + 8, "Goal = ●");

		//操作キャラクター描画
		mvaddstr(my.char_y + 1, 2 * my.char_x + 2, "○");
		//操作キャラクター移動
		move_character(&my, maze_information);
		count++;

		//ゴールで終了
		if (maze_information[my.char_x][my.char_y] == 2) break;
	
		//全てを描画
		refresh();
	}
	erase();

	draw_maze(maze_information);
	mvaddstr(2, 2 * maze_size + 8, "You  = ○");
	mvaddstr(4, 2 * maze_size + 8, "Goal = ●");

	attrset(COLOR_PAIR(2) | A_BOLD);	// 色2 を使う + 太字にする
	mvaddstr(my.char_y + 1, 2 * my.char_x + 8, "Goal!!");
	attrset(COLOR_PAIR(2) | A_BOLD | A_UNDERLINE);	// 色2 を使う + 太字にする + 下線を引く
	mvaddstr(my.char_y + 2, 2 * my.char_x + 8, "Please push 'q' key");

	//掛かった手数を表示
	//addstr(6, 2 * maze_size + 8, count, curses.A_BLINK);

	refresh();

	while (1)
	{
		int end_key = getch();
		if (end_key == 'q') break; //'q'キーを押したら終了
	}

	return 0;
}