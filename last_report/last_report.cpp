#include "last_report.h"

int main()
{
    
	//端末制御開始
	initscr();
	//カーソルを非表示
	curs_set(0);
	//キーを押したらすぐにその文字がプログラムから読み取れるようにする
	cbreak();
	//入力したキーを画面に表示しないようにする
	noecho();
	//矢印キーやファンクションキーなどの特殊キーを利用可能にする
	keypad(stdscr, TRUE);





}
