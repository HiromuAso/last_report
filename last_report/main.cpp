#include "maze_and_character.h"
#include "ini_Setting.h"
#include "file.h"

#include <iostream>
#include <string>
#include <time.h>

int main()
{
	//タイトル
	SetConsoleTitle("迷路自動生成ゲーム");

	//ファイル入力のためにカレントディレクトリを取得
	char currentDirectory[CHARBUFF];
	getCurrentDirectory(currentDirectory);
	//iniファイル名を格納したchar型変数を用意
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\Setting.ini", currentDirectory);

	//迷路の一辺の長さ(必ず奇数にする必要あり,コンソールのデフォの大きさの都合上
	//29より大きくすると表示が乱れる)
	int maze_size_ini = readInt("maze_size", "size", -1, settingFile);

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
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	// 色1に「黒地に白文字」をセット
	init_pair(2, COLOR_RED, COLOR_BLACK);	// 色2に「黒地に赤文字」をセット
	init_pair(3, COLOR_GREEN, COLOR_BLACK);	// 色3に「黒地に緑文字」をセット
	attrset(COLOR_PAIR(1) | A_BOLD);	// 色1 を使う + 太字にする

	//迷路自動生成の2次配列 (動的メモリ確保)
	int** maze_information;
	maze_information = (int**)malloc(sizeof(int*) * maze_size_ini);
	for (int i = 0; i < maze_size_ini; i++)
	{
		maze_information[i] = (int*)malloc(sizeof(int) * maze_size_ini);
	}

	//現在時刻を基に乱数のシード値を設定 (randの値が固定されるのを防ぐため)
	srand((unsigned)time(NULL));
	//迷路ランダム生成
	create_maze(maze_information, maze_size_ini);

	//操作キャラクターの現在地を設定
	struct character my;
	int char_x = start_x;
	int char_y = start_y;

	int goal_x = maze_size_ini - 1;
	int goal_y = maze_size_ini - 1;

	int count = 0;

	while (1)
	{
		//画面リセット
		erase();

		//ランダム生成した迷路を表示
		draw_maze(maze_information, maze_size_ini);

		//簡易説明
		mvaddstr(2, 2 * maze_size_ini + 8, "You  = ○");
		mvaddstr(3, 2 * maze_size_ini + 8, "Goal = ");
		attrset(COLOR_PAIR(2) | A_BOLD);	// 色2 を使う + 太字にする
		mvaddstr(3, 2 * maze_size_ini + 15, "●");

		//ゴール地点を赤く表示
		mvaddstr(goal_y, 2 * goal_x, "●");
		attrset(COLOR_PAIR(1) | A_BOLD);

		//操作キャラクター描画
		mvaddstr(my.char_y + 1, 2 * my.char_x + 2, "○");
		//操作キャラクター移動 (この関数内のgetch()で一旦止まる)
		move_character(&my, maze_information);
		count++;

		//ゴールで終了
		if (maze_information[my.char_x][my.char_y] == 2) break;
	
		//全てを描画
		refresh();
	}
	erase();

	draw_maze(maze_information, maze_size_ini);
	mvaddstr(2, 2 * maze_size_ini + 8, "You  = ○");
	mvaddstr(3, 2 * maze_size_ini + 8, "Goal = ");

	attrset(COLOR_PAIR(3) | A_BOLD); // 色3 を使う + 太字にする
	mvaddstr(3, 2 * maze_size_ini + 15, "●");
	mvaddstr(my.char_y + 1, 2 * my.char_x + 8, "Goal!!");

	attrset(COLOR_PAIR(3) | A_BOLD | A_UNDERLINE);	// 色2 を使う + 太字にする + 下線を引く
	mvaddstr(my.char_y + 2, 2 * my.char_x + 8, "Please push 'q' key");

	//ゴール後,ゴール表示をなんとなく緑色に変更
	attrset(COLOR_PAIR(3) | A_BOLD);
	mvaddstr(goal_y, 2 * goal_x , "●");

	refresh();

	while (1)
	{
		int end_key = getch();
		if (end_key == 'q') break; //'q'キーを押したら終了
	}

	//csvファイルを開いて,クリア回数とスコアを更新
	if (fileoutput(count) == false)
	{
		MessageBox(NULL, _T("csvファイル読み込みに失敗しました"), _T("エラー"), MB_OK | MB_TOPMOST);
		return 0;
	}

	free(maze_information); //動的メモリ解放
	endwin(); //端末制御終了
	return 0;
}