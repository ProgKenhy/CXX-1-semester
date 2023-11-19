#include "functions.hpp"
#include <iostream>

namespace ac
{
	void Read(int matrix[N_Max][N_Max], int &n, int &m)
	{
		std::cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				std::cin >> matrix[i][j];
	}

	void Write(int matrix[N_Max][N_Max], int n, int m)
	{
		std::cout << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
				std::cout << matrix[i][j] << " ";
			std::cout << std::endl;
		}
	}

	void finding_elements(int matrix[N_Max][N_Max], int n, int m, int &mmin, int &mmax)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (matrix[i][j] < mmin)
					mmin = matrix[i][j];
				if (matrix[i][j] > mmax)
					mmax = matrix[i][j];
			}
	}

	bool is_elements_equal(int mmin, int mmax)
	{
		int summa1 = 0, summa2 = 0;
		while (mmin)
		{
			summa1 += mmin % 10;
			mmin /= 10;
		}
		while (mmax)
		{
			summa2 += mmax % 10;
			mmax /= 10;
		}
		if (summa1 == summa2)
			return true;
		return false;
	}

	bool is_string_more(int matrix1[N_Max], int matrix2[N_Max], int m)
	{
		int summa1 = 0, summa2 = 0;
		for (int i = 0; i < m; i++)
		{
			summa1 += matrix1[i];
			summa2 += matrix2[i];
		}
		if (summa1 > summa2)
			return true;
		return false;
	}

	void sorting(int matrix[N_Max][N_Max], int n, int m)
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (is_string_more(matrix[i], matrix[j], m))
					for (int k = 0; k < m; k++)
					{
						int tmp = matrix[i][k];
						matrix[i][k] = matrix[j][k];
						matrix[j][k] = tmp;
					}
	}
}
