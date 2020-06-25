#include "last_report.h"
#include <time.h>

int main()
{
	// �[���̏���
	initscr();
	//�J�[�\�����\��
	curs_set(0);

	// �F�̏���
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	// �F1�Ɂu���n�ɍ������v���Z�b�g
	attrset(COLOR_PAIR(1));			// �F1 ���g��

	//���H����������2���z��
	int maze_information[maze_size][maze_size];
	
	

	while (1)
	{
		//��ʃ��Z�b�g
		erase();

		//���ݎ����𗐐��̃V�[�h�l�ɐݒ�
		srand((unsigned)time(NULL));

		create_maze(maze_information);
		draw_maze(maze_information);

		//���H�`��
		refresh();

		getch();
	}

	return 0;
}