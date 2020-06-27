//ファイル入出力関連のcppファイル

#include "file.h"

//セーブデータ(csv)へクリア回数(+ハイスコア)をアウトプットする
//引数は比較のための暫定ハイスコア
bool fileoutput(int x)
{
	//どのパスのどのファイルか,を示す文字列を設定
	char inputdata[_MAX_PATH];
	//カレントディレクトリの取得（exeフォルダと入力csvファイルは同じフォルダとする）
	char currentDir[_MAX_PATH];
	GetCurrentDirectory(sizeof(currentDir), currentDir);
	//ファイルパスの作成
	sprintf_s(inputdata, "%s\\SaveData.csv", currentDir);

	//クリア回数とハイスコア
	int data[2];

	FILE* fp;
	char buf[BUFFSIZE];
	char s_delim[] = ",";  // 区切り文字
	char* s;

	//読み込み開始
	errno_t error = fopen_s(&fp, inputdata, "r"); //読み取りとして開く
	if (error != 0)  return false;
	
	fgets(buf, BUFFSIZE, fp);
	char* p_work = strtok_s(buf, s_delim, &s); //「クリア回数」
	p_work = strtok_s(NULL, s_delim, &s); //「0～」
	
	data[0] = atoi(p_work) + 1;

	p_work = strtok_s(NULL, s_delim, &s); //「ハイスコア」
	p_work = strtok_s(NULL, s_delim, &s); //「～9999」(小さい方が良い)

	data[1] = atoi(p_work);

	fclose(fp);

	//書き込み開始
	error = fopen_s(&fp, inputdata, "w"); //書き込みとして開く
	if (error != 0)  return false;

	//クリア回数を + 1 してスコアを更新したときはそれも更新
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

	//ファイルクローズ
	fclose(fp);

	return true;
}