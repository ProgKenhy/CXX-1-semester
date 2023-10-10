//	ƒана последовательность натуральных чисел {aj}j=1...n (n<=10000). ≈сли в последовательности нет чисел, все цифры которых одинаковы, упор€дочить последовательность по невозрастанию
#include <iostream>
using namespace std;
int main()
{
	int array[10000], n, tmp;
	short digit, count, n1 = 0;
	bool flag;
	cout << "Input number of elements: ";
	cin >> n;
	cout << "Input elements of massive: ";
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
		tmp = array[i];
		while (tmp)
		{
			digit = tmp % 10;
			tmp /= 10;
			count = 0;
			while (tmp)
			{
				if (tmp % 10 != digit)
				{
					count++;
				}
				tmp /= 10;
			}
		}
		if (count != 0)
		{
			n1++;
		}
	}
	if (n == n1)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (array[i] < array[j])
				{
					tmp = array[i];
					array[i] = array[j];
					array[j] = tmp;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << array[i] << " ";
		}
	}
	else
	{
		cout << "Error";
	}
	return 0;
}
