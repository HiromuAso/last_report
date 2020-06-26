//���H�Ƒ���L�����N�^�[�֘A�̃w�b�_�[�t�@�C��

#pragma once

#include "ini_Setting.h"

//�Q�ƃ��C�u����
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define start_x 1		//�X�^�[�g�n�_
#define start_y 1
#define goal_x maze_size - 1	//�S�[���n�_
#define goal_y maze_size - 1

//����L�����N�^�[�̌��݈ʒu���i�[����\����
typedef struct character {
	int char_x = start_x;
	int char_y = start_y;
};

//���H�̈�ӂ̒���(�K����ɂ���K�v����,�R���\�[���̓s����29���傫������ƕ\���������)�̃f�t�H���g�l
const int maze_size = 11;


//�֐��v���g�^�C�v�錾
void create_maze(int maze[maze_size][maze_size]);
void draw_maze(int maze[maze_size][maze_size]);

void move_character(character* my, int maze[maze_size][maze_size]);

