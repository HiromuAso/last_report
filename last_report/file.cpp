//�t�@�C�����o�͊֘A��cpp�t�@�C��

#include "file.h"

//�Z�[�u�f�[�^(csv)�փN���A��(+�n�C�X�R�A)���A�E�g�v�b�g����
//�����͔�r�̂��߂̎b��n�C�X�R�A
bool fileoutput(int x)
{
	//�ǂ̃p�X�̂ǂ̃t�@�C����,�������������ݒ�
	char inputdata[_MAX_PATH];
	//�J�����g�f�B���N�g���̎擾�iexe�t�H���_�Ɠ���csv�t�@�C���͓����t�H���_�Ƃ���j
	char currentDir[_MAX_PATH];
	GetCurrentDirectory(sizeof(currentDir), currentDir);
	//�t�@�C���p�X�̍쐬
	sprintf_s(inputdata, "%s\\SaveData.csv", currentDir);

	//�N���A�񐔂ƃn�C�X�R�A
	int data[2];

	FILE* fp;
	char buf[BUFFSIZE];
	char s_delim[] = ",";  // ��؂蕶��
	char* s;

	//�ǂݍ��݊J�n
	errno_t error = fopen_s(&fp, inputdata, "r"); //�ǂݎ��Ƃ��ĊJ��
	if (error != 0)  return false;
	
	fgets(buf, BUFFSIZE, fp);
	char* p_work = strtok_s(buf, s_delim, &s); //�u�N���A�񐔁v
	p_work = strtok_s(NULL, s_delim, &s); //�u0�`�v
	
	data[0] = atoi(p_work) + 1;

	p_work = strtok_s(NULL, s_delim, &s); //�u�n�C�X�R�A�v
	p_work = strtok_s(NULL, s_delim, &s); //�u�`9999�v(�����������ǂ�)

	data[1] = atoi(p_work);

	fclose(fp);

	//�������݊J�n
	error = fopen_s(&fp, inputdata, "w"); //�������݂Ƃ��ĊJ��
	if (error != 0)  return false;

	//�N���A�񐔂� + 1 ���ăX�R�A���X�V�����Ƃ��͂�����X�V
	char s_buf[BUFFSIZE];
	if (x < data[1])
	{
		sprintf_s(s_buf, "Clear_count,%d,Highscore,%d", data[0], x);
		fputs(s_buf, fp);
	}
	else
	{
		sprintf_s(s_buf, "Clear_count,%d,Highscore,%d", data[0], data[1]);
		fputs(s_buf, fp);
	}

	//�t�@�C���N���[�Y
	fclose(fp);

	return true;
}