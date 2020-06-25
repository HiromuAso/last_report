#include "last_report.h"
#include <time.h>

int main()
{
	// �[���̏���
	initscr();
	//�J�[�\�����\��
	curs_set(0);
	//�L�[���������炷���ɂ��̕������v���O��������ǂݎ���悤�ɂ���
	cbreak();
	//���͂����L�[����ʂɕ\�����Ȃ��悤�ɂ���
	noecho();
	//���L�[��t�@���N�V�����L�[�Ȃǂ̓���L�[�𗘗p�\�ɂ���
	keypad(stdscr, TRUE);

	// �F�̏���
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	// �F1�Ɂu���n�ɍ������v���Z�b�g
	attrset(COLOR_PAIR(1));	// �F1 ���g��

	//���H����������2���z��
	int maze_information[maze_size][maze_size];

	//���ݎ����𗐐��̃V�[�h�l�ɐݒ� (rand�̒l���Œ肳���̂�h������)
	srand((unsigned)time(NULL));
	//���H�����_������
	create_maze(maze_information);

	//����L�����N�^�[�̌��ݒn��ݒ�
	struct charactor my;
	int char_x = start_x;
	int char_y = start_y;

	while (1)
	{
		//��ʃ��Z�b�g
		erase();
		
		//�����_�������������H��\��
		draw_maze(maze_information);

		//����L�����N�^�[�`��
		mvaddstr(my.char_y + 1, 2 * my.char_x + 2, "��");
		//����L�����N�^�[�ړ�
		move_charactor(&my, maze_information);

		//�S�[���ŏI��
		if (maze_information[my.char_x][my.char_y] == 2) break;
	
		//�S�Ă�`��
		refresh();
	}
	return 0;
}