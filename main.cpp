#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int row, col; //螺旋矩阵的行数和列数
	cin >> row >> col;

	int x, y; //螺旋的中心位置
	cin >> x >> y;


	int** m = new int* [row]; //动态分配二维矩阵
	for (int i = 0; i < row; i++)
		m[i] = new int[col];

	//开始螺旋赋值（顺时针，由内向外发散）
	//每次循环包括4个方向的小循环：向右、向下、向左、向上
	//number表示数值、iter_idx表示迭代次数、count表示赋值次数
	//原理详见图
	int number = 1, iter_idx = 1, count = 1;
	m[x][y] = number;
	while (count < row * col)
	{
		
		for (size_t i = 0; i < 2 * iter_idx - 1 && count < row * col; i++)
		{
			if (y + 1 < col && y + 1 >= 0 && x >=0 && x < row)
			{ 
				m[x][++y] = ++number;
				count++;
			}	
			else
			{
				++number;
				++y;
			}	
		}
		
		for (size_t i = 0; i < 2 * iter_idx - 1 && count < row * col; i++)
		{
			if (x + 1 < row && x + 1 >= 0 && y >= 0 && y < col)
			{
				m[++x][y] = ++number;
				count++;
			}
			else
			{
				++x;
				++number;
			}
		}
		
		for (size_t i = 0; i < 2 * iter_idx && count < row * col; i++)
		{
			if (y - 1 >= 0 && y - 1 < col && x >= 0 && x < row)
			{
				m[x][--y] = ++number;
				count++;
			}
			else
			{
				--y;
				++number;
			}
		}
		
		for (size_t i = 0; i < 2 * iter_idx && count < row * col; i++)
		{
			if (x - 1 >= 0 && x - 1 < row && y >= 0 && y < col)
			{
				m[--x][y] = ++number;
				count++;
			}
			else
			{
				--x;
				++number;
			}
		}
		
		iter_idx++;
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << setw(3) << setfill(' ') << m[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}