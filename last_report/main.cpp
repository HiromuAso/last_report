#include "last_report.h"

int main()
{
	while (1)
	{
		//���H�`��
		erase();

		//���H����������2���z��
		int maze_information[11][11];
		//��U�S��0�ŏ�����
		for (int x = 0; x < 11; x++)
		{
			for (int y = 0; y < 11; y++)
			{
				maze_information[x][y] = 0;
			}
		}

		create_maze(maze_information);
		draw_maze(maze_information);


		
	}

	return 0;
}