#pragma once
#define N_Max 100



namespace ac
{
	void Read(int matrix[N_Max][N_Max], int &n, int &m);
	void Write(int matrix[N_Max][N_Max], int n, int m);
	void finding_elements(int matrix[N_Max][N_Max], int n, int m, int &mmin, int &mmax);
	bool is_elements_equal(int mmin, int mmax);
	bool is_string_more(int matrix1[N_Max], int matrix2[N_Max], int m);
	void sorting(int matrix[N_Max][N_Max], int n, int m);
}
