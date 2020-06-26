#include "maze_and_character.h"
#include "ini_Setting.h"

#include <iostream>
#include <string>
#include <time.h>

int main()
{
	//�t�@�C�����͂̂��߂ɃJ�����g�f�B���N�g�����擾
	char currentDirectory[CHARBUFF];
	getCurrentDirectory(currentDirectory);
	//ini�t�@�C�������i�[����char�^�ϐ���p��
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\Setting.ini", currentDirectory);
	//ini�t�@�C���ǂݍ���
	int maze_size_int =	readInt("maze_size", "size", -1, settingFile);
	int window_size_x = readInt("window_size", "size_x", -1, settingFile);
	int window_size_y = readInt("window_size", "size_y", -1, settingFile);

	// �[���̏���
	initscr();
	//�E�B���h�E�̑傫����ݒ�
	getmaxyx(stdscr, window_size_y, window_size_x);
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
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	// �F1�Ɂu���n�ɔ������v���Z�b�g
	init_pair(2, COLOR_RED, COLOR_BLACK);	// �F2�Ɂu���n�ɐԕ����v���Z�b�g
	attrset(COLOR_PAIR(1) | A_BOLD);	// �F1 ���g�� + �����ɂ���

	//���H����������2���z��
	int maze_information[maze_size][maze_size];

	//���ݎ�������ɗ����̃V�[�h�l��ݒ� (rand�̒l���Œ肳���̂�h������)
	srand((unsigned)time(NULL));
	//���H�����_������
	create_maze(maze_information);

	//����L�����N�^�[�̌��ݒn��ݒ�
	struct character my;
	int char_x = start_x;
	int char_y = start_y;

	//����ڂ����J�E���g
	int count = 0;

	while (1)
	{
		//��ʃ��Z�b�g
		erase();

		//�����_�������������H��\��
		draw_maze(maze_information);

		//�ȈՐ���
		mvaddstr(2, 2 * maze_size + 8, "You  = ��");
		mvaddstr(4, 2 * maze_size + 8, "Goal = ��");

		//����L�����N�^�[�`��
		mvaddstr(my.char_y + 1, 2 * my.char_x + 2, "��");
		//����L�����N�^�[�ړ�
		move_character(&my, maze_information);
		count++;

		//�S�[���ŏI��
		if (maze_information[my.char_x][my.char_y] == 2) break;
	
		//�S�Ă�`��
		refresh();
	}
	erase();

	draw_maze(maze_information);
	mvaddstr(2, 2 * maze_size + 8, "You  = ��");
	mvaddstr(4, 2 * maze_size + 8, "Goal = ��");

	attrset(COLOR_PAIR(2) | A_BOLD);	// �F2 ���g�� + �����ɂ���
	mvaddstr(my.char_y + 1, 2 * my.char_x + 8, "Goal!!");
	attrset(COLOR_PAIR(2) | A_BOLD | A_UNDERLINE);	// �F2 ���g�� + �����ɂ��� + ����������
	mvaddstr(my.char_y + 2, 2 * my.char_x + 8, "Please push 'q' key");

	//�|�������萔��\��
	//addstr(6, 2 * maze_size + 8, count, curses.A_BLINK);

	refresh();

	while (1)
	{
		int end_key = getch();
		if (end_key == 'q') break; //'q'�L�[����������I��
	}

	return 0;
}