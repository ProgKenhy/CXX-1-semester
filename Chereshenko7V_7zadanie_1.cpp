//	ƒана последовательность натуральных чисел {aj}j=1...n (n<=10000). ≈сли в последовательности нет чисел, все цифры которых одинаковы, упор€дочить последовательность по невозрастанию
#include <iostream>
using namespace std;
int main()
{
	int array[10000], n, tmp;
	short digit;
	bool flag;
	cin >> n;
	flag = true;
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
		tmp = array[i];
		while (tmp)
		{
			digit = tmp % 10;
			tmp /= 10;
			while (tmp)
			{
				if (tmp % 10 == digit)
				{
					flag = false;
					break;
				}
				tmp /= 10;
			}
			if (flag == false)
			{
				break;
			}
		}
		if (flag == false)
		{
		cout << "False number" << endl;
		break;
		}
	}
	if (flag)
	{
		for (int i = 0; i < n-1; i++)
		{
			for (int j = i+1; j < n; j++)
			{
				if (array [i] < array [j])
				{
					tmp=array[i];
					array[i]=array[j];
					array[j]=tmp;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout<<array[i]<< " ";
		}
	}
	return 0;
}
