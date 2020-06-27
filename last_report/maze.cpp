//���H�֘A��cpp�t�@�C��

#include "maze_and_character.h"

//���H����������
void create_maze(int** maze, int maze_size)
{ 
	//��U�S�đ���0�ŏ�����
	for (int x = 0; x < maze_size; x++)
	{
		for (int y = 0; y < maze_size; y++)
		{
			maze[x][y] = 0;
		}
	}

	//�܂��O�g�𑮐�1�Ŗ��߂�
	for (int x = 0; x < maze_size; x++)
	{
		for (int y = 0; y < maze_size; y++)
		{
			if (x == 0 || x == maze_size - 1 || y == 0 || y == maze_size - 1) {
				maze[x][y] = 1;
			}
		}
	}

	//�S�[���n�_�͑�����2�ɂ��đ���1�̕ǂƋ�ʉ����Ă���
	maze[maze_size - 2][maze_size - 2] = 2;

	//���H���������A���S���Y��
	for (int y = 0; y < ((maze_size - 3) / 2); y++)
	{
		for (int x = 0; x < ((maze_size - 3) / 2); x++)
		{
			maze[2 + 2 * x][2 + 2 * y] = 1; //x,y���W��1��΂���1�ɂ���
			
			//1�s��
			if (y == 0) 
			{
				while (1) {
					int random = rand() % 4; //0�`3�̗����𐶐�

					if (random == 0)
					{
						if (maze[3 + 2 * x][2 + 2 * y] != 1) {
							maze[3 + 2 * x][2 + 2 * y] = 1; //�E��1�ɂ���
							break;
						}
					}
					else if (random == 1)
					{
						if (maze[2 + 2 * x][3 + 2 * y] != 1) {
							maze[2 + 2 * x][3 + 2 * y] = 1; //����1�ɂ���
							break;
						}
					}
					else if (random == 2)
					{
						if (maze[1 + 2 * x][2 + 2 * y] != 1) {
							maze[1 + 2 * x][2 + 2 * y] = 1; //����1�ɂ���
							break;
						}
					}
					else if (random == 3)
					{
						if (maze[2 + 2 * x][1 + 2 * y] != 1) {
							maze[2 + 2 * x][1 + 2 * y] = 1; //���1�ɂ���
							break;
						}
					}

				}
			}
			//2�s�ڈȍ~ (2�s�ڈȍ~�͏�Ƀu���b�N�𐶐����Ȃ�)
			else
			{
				while (1)
				{
					int random = rand() % 3; //0�`2�̗����𐶐�

					if (random == 0)
					{
						if (maze[3 + 2 * x][2 + 2 * y] != 1) {
							maze[3 + 2 * x][2 + 2 * y] = 1; //�E��1�ɂ���
							break;
						}
					}
					else if (random == 1)
					{
						if (maze[2 + 2 * x][3 + 2 * y] != 1) {
							maze[2 + 2 * x][3 + 2 * y] = 1; //����1�ɂ���
							break;
						}
					}
					else if (random == 2)
					{
						if (maze[1 + 2 * x][2 + 2 * y] != 1) {
							maze[1 + 2 * x][2 + 2 * y] = 1; //����1�ɂ���
							break;
						}
					}
		
				}

			}
		}
	}

}

//���������������H��`��
void draw_maze(int** maze, int maze_size)
{
	for (int y = 0; y < maze_size; y++)
	{
		for (int x = 0; x < maze_size; x++)
		{
			if (maze[x][y] == 1) {
				mvaddstr(y + 1, 2 * x + 2, "��");
			}
		}
	}

}
