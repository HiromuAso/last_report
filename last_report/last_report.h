#pragma once

//�Q�ƃ��C�u����
#pragma once

//�Q�ƃ��C�u����
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#define maze_size 29	//���H(�����`)�̈�ӂ̒���(�K����ɂ���K�v����)

//�֐��v���g�^�C�v�錾
void create_maze(int maze[maze_size][maze_size]);
void draw_maze(int maze[maze_size][maze_size]);