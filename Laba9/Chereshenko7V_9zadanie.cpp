// ���� ������������� ������� {Aij}i=1...n;j=1..n ,n<=100.
// ���� ����� ���� ������������ � ������������� ��������� ������� ���������,
// ����������� ������ ������� �� ���������� ����� ���������.

#include "functions.hpp"


int main()
{
	int n, m;
	int mmin = 9999, mmax = -9999;
	int matrix[N_Max][N_Max];

	// ���� �������
	ac::Read(matrix, n, m);

	//����� ����������� � ������������ �������
	ac::finding_elements(matrix, n, m, mmin, mmax);

	// ����������� ������ �� ����������, ���� ����� ����� ���� ��������� ���������
	if (ac::is_elements_equal(mmin, mmax))
		ac::sorting(matrix, n, m);

	// ����� �������
	ac::Write(matrix, n, m);

	return 0;
}