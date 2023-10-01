#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int array[150];
	int i;
	int dlina = 20; // Выбираем длину массива
	int suma = 0;
	int minimum = 1000;
	for (i = 0; i < dlina; i++) // Блок генерации массива (в данном написании кода можно менять способы генерации массива)
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
	cout << "Сумма таких чисел равна: " << suma << endl;
	cout << "Минимальное из таких чисел равно: " << minimum;
	return 0;
}