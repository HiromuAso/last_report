//ini�t�@�C�����o�͂�cpp�t�@�C��

#include "ini_Setting.h"

//ini�t�@�C������int�^�ϐ����Q��
int readInt(const char* section, const char* keyword, int defaultValue, const char* filePath)
{
	return GetPrivateProfileInt(section, keyword, defaultValue, filePath);
}

//���݂̃f�B���N�g�����擾
void getCurrentDirectory(char* currentDirectory)
{
	GetCurrentDirectory(CHARBUFF, currentDirectory);
}

//ini�t�@�C����int�^�ϐ����o��
bool writeInt(const char* section, const char* keyword, int value, const char* filePath)
{
	char c_value[CHARBUFF];
	sprintf_s(c_value, "%d", value);
	return WritePrivateProfileString(section, keyword, c_value, filePath) != 0;
}