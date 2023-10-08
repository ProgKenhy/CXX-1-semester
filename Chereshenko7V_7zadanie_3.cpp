// 	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). Найти строку с наибольшей суммой элементов и увеличить все элементы этой строки на 1.

#include <iostream>
using namespace std;

int main()
{
	int a, b, summ, maxsumm;
	short needstr, count = 0;
	maxsumm = 0;
	cout << "Input number of strings and columns of matrix" << endl;
	cin >> a >> b;
	cout << endl;
	int matrix[100][100];
	for (int i = 0; i < a; i++)
	{
		summ = 0;
		for (int j = 0; j < b; j++)
		{
			cin >> matrix[i][j];
			summ += matrix[i][j];
		}
		if (maxsumm < summ)
		{
			maxsumm = summ;
			needstr = i;
		}
	}
	for (int f = 0; f < a; f++)
		matrix[needstr][f] += 1;
	cout << endl;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			count += 1;
			if (count % b == 0)
			{
				cout << matrix[i][j] << endl;
			}
			else
			{
				cout << matrix[i][j] << " ";
			}
		}
	}
	return 0;
}