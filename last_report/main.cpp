#include "maze_and_character.h"
#include "ini_Setting.h"
#include "file.h"

#include <iostream>
#include <string>
#include <time.h>

int main()
{
	//�^�C�g��
	SetConsoleTitle("���H���������Q�[��");

	//�t�@�C�����͂̂��߂ɃJ�����g�f�B���N�g�����擾
	char currentDirectory[CHARBUFF];
	getCurrentDirectory(currentDirectory);
	//ini�t�@�C�������i�[����char�^�ϐ���p��
	char settingFile[CHARBUFF];
	sprintf_s(settingFile, "%s\\Setting.ini", currentDirectory);

	//���H�̈�ӂ̒���(�K����ɂ���K�v����,�R���\�[���̃f�t�H�̑傫���̓s����
	//29���傫������ƕ\���������)
	int maze_size_ini = readInt("maze_size", "size", -1, settingFile);

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
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	// �F1�Ɂu���n�ɔ������v���Z�b�g
	init_pair(2, COLOR_RED, COLOR_BLACK);	// �F2�Ɂu���n�ɐԕ����v���Z�b�g
	init_pair(3, COLOR_GREEN, COLOR_BLACK);	// �F3�Ɂu���n�ɗΕ����v���Z�b�g
	attrset(COLOR_PAIR(1) | A_BOLD);	// �F1 ���g�� + �����ɂ���

	//���H����������2���z�� (���I�������m��)
	int** maze_information;
	maze_information = (int**)malloc(sizeof(int*) * maze_size_ini);
	for (int i = 0; i < maze_size_ini; i++)
	{
		maze_information[i] = (int*)malloc(sizeof(int) * maze_size_ini);
	}

	//���ݎ�������ɗ����̃V�[�h�l��ݒ� (rand�̒l���Œ肳���̂�h������)
	srand((unsigned)time(NULL));
	//���H�����_������
	create_maze(maze_information, maze_size_ini);

	//����L�����N�^�[�̌��ݒn��ݒ�
	struct character my;
	int char_x = start_x;
	int char_y = start_y;

	int goal_x = maze_size_ini - 1;
	int goal_y = maze_size_ini - 1;

	int count = 0;

	while (1)
	{
		//��ʃ��Z�b�g
		erase();

		//�����_�������������H��\��
		draw_maze(maze_information, maze_size_ini);

		//�ȈՐ���
		mvaddstr(2, 2 * maze_size_ini + 8, "You  = ��");
		mvaddstr(3, 2 * maze_size_ini + 8, "Goal = ");
		attrset(COLOR_PAIR(2) | A_BOLD);	// �F2 ���g�� + �����ɂ���
		mvaddstr(3, 2 * maze_size_ini + 15, "��");

		//�S�[���n�_��Ԃ��\��
		mvaddstr(goal_y, 2 * goal_x, "��");
		attrset(COLOR_PAIR(1) | A_BOLD);

		//����L�����N�^�[�`��
		mvaddstr(my.char_y + 1, 2 * my.char_x + 2, "��");
		//����L�����N�^�[�ړ� (���̊֐�����getch()�ň�U�~�܂�)
		move_character(&my, maze_information);
		count++;

		//�S�[���ŏI��
		if (maze_information[my.char_x][my.char_y] == 2) break;
	
		//�S�Ă�`��
		refresh();
	}
	erase();

	draw_maze(maze_information, maze_size_ini);
	mvaddstr(2, 2 * maze_size_ini + 8, "You  = ��");
	mvaddstr(3, 2 * maze_size_ini + 8, "Goal = ");

	attrset(COLOR_PAIR(3) | A_BOLD); // �F3 ���g�� + �����ɂ���
	mvaddstr(3, 2 * maze_size_ini + 15, "��");
	mvaddstr(my.char_y + 1, 2 * my.char_x + 8, "Goal!!");

	attrset(COLOR_PAIR(3) | A_BOLD | A_UNDERLINE);	// �F2 ���g�� + �����ɂ��� + ����������
	mvaddstr(my.char_y + 2, 2 * my.char_x + 8, "Please push 'q' key");

	//�S�[����,�S�[���\�����Ȃ�ƂȂ��ΐF�ɕύX
	attrset(COLOR_PAIR(3) | A_BOLD);
	mvaddstr(goal_y, 2 * goal_x , "��");

	refresh();

	while (1)
	{
		int end_key = getch();
		if (end_key == 'q') break; //'q'�L�[����������I��
	}

	//csv�t�@�C�����J����,�N���A�񐔂ƃX�R�A���X�V
	if (fileoutput(count) == false)
	{
		MessageBox(NULL, _T("csv�t�@�C���ǂݍ��݂Ɏ��s���܂���"), _T("�G���["), MB_OK | MB_TOPMOST);
		return 0;
	}

	free(maze_information); //���I���������
	endwin(); //�[������I��
	return 0;
}