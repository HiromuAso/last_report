//迷路関連のcppファイル

#include "maze_and_character.h"

//迷路を自動生成
void create_maze(int** maze, int maze_size)
{ 
	//一旦全て属性0で初期化
	for (int x = 0; x < maze_size; x++)
	{
		for (int y = 0; y < maze_size; y++)
		{
			maze[x][y] = 0;
		}
	}

	//まず外枠を属性1で埋める
	for (int x = 0; x < maze_size; x++)
	{
		for (int y = 0; y < maze_size; y++)
		{
			if (x == 0 || x == maze_size - 1 || y == 0 || y == maze_size - 1) {
				maze[x][y] = 1;
			}
		}
	}

	//ゴール地点は属性を2にして属性1の壁と区別化しておく
	maze[maze_size - 2][maze_size - 2] = 2;

	//迷路自動生成アルゴリズム
	for (int y = 0; y < ((maze_size - 3) / 2); y++)
	{
		for (int x = 0; x < ((maze_size - 3) / 2); x++)
		{
			maze[2 + 2 * x][2 + 2 * y] = 1; //x,y座標を1つ飛ばしに1にする
			
			//1行目
			if (y == 0) 
			{
				while (1) {
					int random = rand() % 4; //0～3の乱数を生成

					if (random == 0)
					{
						if (maze[3 + 2 * x][2 + 2 * y] != 1) {
							maze[3 + 2 * x][2 + 2 * y] = 1; //右を1にする
							break;
						}
					}
					else if (random == 1)
					{
						if (maze[2 + 2 * x][3 + 2 * y] != 1) {
							maze[2 + 2 * x][3 + 2 * y] = 1; //下を1にする
							break;
						}
					}
					else if (random == 2)
					{
						if (maze[1 + 2 * x][2 + 2 * y] != 1) {
							maze[1 + 2 * x][2 + 2 * y] = 1; //左を1にする
							break;
						}
					}
					else if (random == 3)
					{
						if (maze[2 + 2 * x][1 + 2 * y] != 1) {
							maze[2 + 2 * x][1 + 2 * y] = 1; //上を1にする
							break;
						}
					}

				}
			}
			//2行目以降 (2行目以降は上にブロックを生成しない)
			else
			{
				while (1)
				{
					int random = rand() % 3; //0～2の乱数を生成

					if (random == 0)
					{
						if (maze[3 + 2 * x][2 + 2 * y] != 1) {
							maze[3 + 2 * x][2 + 2 * y] = 1; //右を1にする
							break;
						}
					}
					else if (random == 1)
					{
						if (maze[2 + 2 * x][3 + 2 * y] != 1) {
							maze[2 + 2 * x][3 + 2 * y] = 1; //下を1にする
							break;
						}
					}
					else if (random == 2)
					{
						if (maze[1 + 2 * x][2 + 2 * y] != 1) {
							maze[1 + 2 * x][2 + 2 * y] = 1; //左を1にする
							break;
						}
					}
		
				}

			}
		}
	}

}

//自動生成した迷路を描画
void draw_maze(int** maze, int maze_size)
{
	for (int y = 0; y < maze_size; y++)
	{
		for (int x = 0; x < maze_size; x++)
		{
			if (maze[x][y] == 1) {
				mvaddstr(y + 1, 2 * x + 2, "■");
			}
		}
	}

}
