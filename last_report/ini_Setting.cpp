//iniファイル入出力のcppファイル

#include "ini_Setting.h"

//iniファイルからint型変数を参照
int readInt(const char* section, const char* keyword, int defaultValue, const char* filePath)
{
	return GetPrivateProfileInt(section, keyword, defaultValue, filePath);
}

//現在のディレクトリを取得
void getCurrentDirectory(char* currentDirectory)
{
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

//iniファイルへint型変数を出力
bool writeInt(const char* section, const char* keyword, int value, const char* filePath)
{
	char c_value[CHARBUFF];
	sprintf_s(c_value, "%d", value);
	return WritePrivateProfileString(section, keyword, c_value, filePath) != 0;
}