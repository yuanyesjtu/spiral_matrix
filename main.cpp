#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	int row, col; //�������������������
	cin >> row >> col;

	int x, y; //����������λ��
	cin >> x >> y;


	int** m = new int* [row]; //��̬�����ά����
	for (int i = 0; i < row; i++)
		m[i] = new int[col];

	//��ʼ������ֵ��˳ʱ�룬�������ⷢɢ��
	//ÿ��ѭ������4�������Сѭ�������ҡ����¡���������
	//number��ʾ��ֵ��iter_idx��ʾ����������count��ʾ��ֵ����
	//ԭ�����ͼ
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