#pragma once

//�Q�ƃ��C�u����
#pragma once

//�Q�ƃ��C�u����
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define maze_size 29	//���H�̈�ӂ̒���(�K����ɂ���K�v����,�R���\�[���̓s����29���傫������ƕ\���������)
#define start_x 2		//�X�^�[�g�n�_
#define start_y 2
#define goal_x maze_size - 1	//�S�[���n�_
#define goal_y maze_size - 1

//�֐��v���g�^�C�v�錾
void create_maze(int maze[maze_size][maze_size]);
void draw_maze(int maze[maze_size][maze_size]);

void draw_charactor();

//����L�����N�^�[�̌��݈ʒu���i�[����\����
typedef struct charactor {
	int char_x = start_x;
	int char_y = start_y;
};