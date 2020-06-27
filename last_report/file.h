//ファイル入出力関連のヘッダーファイル

#pragma once

#include <stdio.h>
#include <tchar.h>
#include <stdlib.h>
#include <windows.h> 

#define BUFFSIZE 1024

//ファイル取得に失敗した時にエラーメッセージを返したいので,bool型で定義
bool fileoutput(int x);