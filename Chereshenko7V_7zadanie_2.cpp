// Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). Упорядочить последовательность по неубыванию суммы цифр числа, числа с одинаковыми суммами цифр дополнительно упорядочить по неубыванию наибольшей цифры числа, числа с одинаковыми суммами цифр и одинаковыми наибольшими цифрами дополнительно упорядочить по неубыванию самого числа.
#include <iostream>
using namespace std;
int sumdigit(int f)
{
	int summa = 0;
	while (f)
	{
		summa += f % 10;
		f /= 10;
	}
	return summa;
}
int maxdigit(int f)
{
	int digit = 0;
	while (f)
	{
		if (f % 10 > digit)
		{
			digit = f % 10;
		}
		return digit;
	}
}

int main()
{
	int array[1000], n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (sumdigit(array[i]) > sumdigit(array[j]))
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
			}
			else if (sumdigit(array[i]) == sumdigit(array[j]))
			{
				if (maxdigit(array[i]) > maxdigit(array[j]))
				{
					tmp = array[j];
					array[j] = array[i];
					array[i] = tmp;
				}
				else if (array[i] > array[j])
				{
					tmp = array[j];
					array[j] = array[i];
					array[i] = tmp;
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
	return 0;
}