#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int array[150];
	int i;
	int dlina = 20; // �������� ����� �������
	int suma = 0;
	int minimum = 1000;
	for (i = 0; i < dlina; i++) // ���� ��������� ������� (� ������ ��������� ���� ����� ������ ������� ��������� �������)
	{
		array[i] = i + 1;
	}
	for (i = 0; i < dlina; i++)
	{
		if ((array[i] % 3 == 0) || (array[i] % 7 == 0))
		{
			suma += int(array[i]);

			if (minimum > array[i])
			{
				minimum = array[i];
			}
		}
	}
	cout << "����� ����� ����� �����: " << suma << endl;
	cout << "����������� �� ����� ����� �����: " << minimum;
	return 0;
}