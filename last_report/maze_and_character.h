//���H�Ƒ���L�����N�^�[�֘A�̃w�b�_�[�t�@�C��

#pragma once

#include "ini_Setting.h"

//�Q�ƃ��C�u����
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define start_x 1		//�X�^�[�g�n�_
#define start_y 1

//����L�����N�^�[�̌��݈ʒu���i�[����\����
typedef struct character {
	int char_x = start_x;
	int char_y = start_y;
};

//���H�̈�ӂ̒���(�K����ɂ���K�v����,�R���\�[���f�t�H���g�̑傫���̓s����
//29���傫������ƕ\���������)
//const int maze_size = 5; //�f�t�H���g�l

//�֐��v���g�^�C�v�錾
void create_maze(int** maze, int maze_size);
void draw_maze(int** maze, int maze_size);

void move_character(character* my, int** maze);

