// Сначала введите последовательность. Затем удалите и продублируйте элементы. Затем выведите полученную последовательность (каждый элемент по одному разу). Используйте в программе только один массив.

// Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). Удалить из последовательности числа, сумма цифр которых равна 10, а среди оставшихся продублировать числа-палиндромы.

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, array[1000], tmp, p = 0;
	short summ, digit, d, x;

	cout << "Input lenght of massive" << endl;
	cin >> n;
	cout << "Input elements of massive:" << endl;
	for (int i = 0; i < n; i++)	//creation of massive
	{
		cin >> array[i];
	}
	for (int i = 0; i < n; i++)	//delete elements
	{
		tmp = array[i];
		summ = 0;
		while (tmp)
		{
			summ += tmp % 10;
			tmp /= 10;
		}
		if (summ == 10)
		{
			for (x=i; x < n; x++)
			{
				array[x] = array[x + 1];
			}
			n--;
			i--;
			
		}
	}
	for (int i = 0; i < n; i++) //duble elements
	{
		tmp = array[i];
		d = -1;
		p = 0;
		while (tmp)
		{
			d += 1;
			tmp /= 10;
		}
		tmp = array[i];
		double m = 0;
		while (tmp)
		{
			m = pow(10, d);
			p += (tmp % 10) * m;
			tmp /= 10;
			d -= 1;
		}
		if (array[i] == p)
		{
			for (int x = n; x > i; x--)
			{
				array[x] = array[x - 1];
			}
			n++;
			i++;
		}
	}
	for (int i = 0; i < n; i++) //output
	{
		cout << array[i] << " ";
	}
	return 0;
}