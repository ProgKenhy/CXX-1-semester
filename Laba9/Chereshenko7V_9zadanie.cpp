// Дана целочисленная матрица {Aij}i=1...n;j=1..n ,n<=100.
// Если суммы цифр минимального и максимального элементов матрицы одинаковы,
// упорядочить строки матрицы по неубыванию суммы элементов.

#include "functions.hpp"


int main()
{
	int n, m;
	int mmin = 9999, mmax = -9999;
	int matrix[N_Max][N_Max];

	// Ввод матрицы
	ac::Read(matrix, n, m);

	//Найти минимальный и максимальный элемент
	ac::finding_elements(matrix, n, m, mmin, mmax);

	// Упорядочить строки по неубыванию, если равны суммы цифр найденных элементов
	if (ac::is_elements_equal(mmin, mmax))
		ac::sorting(matrix, n, m);

	// Вывод матрицы
	ac::Write(matrix, n, m);

	return 0;
}