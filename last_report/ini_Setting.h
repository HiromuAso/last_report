//ini�t�@�C�����o�͂̃w�b�_�[�t�@�C��

#pragma once

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

#define CHARBUFF 124

int readInt(const char* section, const char* keyword, int defaultValue, const char* filePath);
void getCurrentDirectory(char* currentDirectory);
bool writeInt(const char* section, const char* keyword, int value, const char* filePath);