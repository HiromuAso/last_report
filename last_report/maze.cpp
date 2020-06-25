#include "last_report.h"

//���H����������
void create_maze(int maze[11][11])
{
	//�܂��O�g��1�Ŗ��߂�
	for (int x = 0; x < 11; x++)
	{
		for (int y = 0; y < 11; y++)
		{
			if (x == 0 || x == 9 || y == 0 || y == 9) {
				maze[x][y] = 1;
			}
		}
	}


}

//���������������H��`��
void draw_maze(int maze[11][11])
{
	// �[���̏���
	initscr();
	//�J�[�\�����\��
	curs_set(0);

	// �F�̏���
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	// �F1�Ɂu���n�ɍ������v���Z�b�g
	attrset(COLOR_PAIR(1));			// �F1 ���g��

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			if (maze[x][y] == 1) {
				mvaddstr(y + 10, 2 * x + 10, "��");
			}
		}
	}

	//���H�`��
	refresh();
}
