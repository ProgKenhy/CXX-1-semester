// Дан файл, содержащий русский текст.
//  Найти в тексте N<=2000 самых длинных слов, не содержащих одинаковых согласных.
//  Записать найденные слова в текстовый файл в порядке невозрастания длины.
//  Все найденные слова должны быть разными!
#include <iostream>
#include <fstream>

char tolowermy(char x)
{
	if ('А' <= x && x <= 'Я')
		return x += 32;
	return x;
}
int wordlength(char *x)
{
	int len = 0;
	while (x[len] != '\0')
	{
		len++;
	}
	return len;
}

bool is_rus_and_soglasnye_different(char *x, char *y)
{
	for (int i = 0; i < wordlength(x); i++)
	{
		int count = 0;
		for (int j = 0; j < wordlength(y); j++)
		{
			if (x[i] == y[j])
			{
				count++;
				if (count > 1)
					return false;
			}
			if (y[j] >= 'A' && y[j] <= 'z')
				return false;
		}
	}
	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int n = 2001;
	int vsego = 0;
	char word[100] = {0};
	char result[n][100] = {0};
	char soglasnye[43] = "бвгджзйклмнпрстфхцчшщ";
	std::ifstream infile;
	infile.open("C:\\Users\\Alexander\\.vscode\\Projects\\Files\\input.txt");
	if (!infile.is_open())
	{
		std::cout << "Input file dod not find!";
		return -1;
	}
	int lastpos = 0;
	std::cout << "Input value of numbers: ";
	int k, inminlen = 0;
	std::cin >> k;
	while (!infile.eof())
	{
		infile >> word;
		word[0] = tolowermy(word[0]);
		lastpos = wordlength(word) - 1;
		for (int i = lastpos; i >= 0; i--)
		{
			if (ispunct(word[i]) || isdigit(word[i]))
				word[i] = '\0';
			else if (ispunct(word[0]) || isdigit(word[0]))
				word[0] = '\0';
			else
				break;
		}

		if ((wordlength(word)) > wordlength(result[inminlen]))
		{
			int maxlen = 0;
			bool flag;
			if (is_rus_and_soglasnye_different(soglasnye, word))
			{
				for (int q = 0; q < k; q++)
				{
					flag = false;
					int countofequvalent = 0;
					if (wordlength(result[q]) < wordlength(word))
						maxlen = wordlength(word);
					else
						maxlen = wordlength(result[q]);
					for (int w = 0; w < maxlen; w++)
					{
						if (word[w] != result[q][w])
						{
							flag = true;
						}
					}
					if (!flag)
						break;
				}
				if (flag)
				{
					for (int b = 0; b < wordlength(word); b++)
					{
						result[inminlen][b] = word[b];
					}
					vsego++;
					for (int c = 0; c < k; c++)
						if (wordlength(result[inminlen]) > wordlength(result[c]))
						{
							inminlen = c;
						}
				}
			}
		}
	}
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
		{
			if (wordlength(result[i]) < wordlength(result[j]))
			{
				for (int b = 0; b < 100; b++)
				{
					char tmp;
					tmp = result[i][b];
					result[i][b] = result[j][b];
					result[j][b] = tmp;
				}
			}
		}
	std::ofstream outfile;
	outfile.open("C:\\Users\\Alexander\\.vscode\\Projects\\Files\\output.txt");
	if (vsego < k)
	{
		k = vsego;
		std::cout << "Number of needs words is smaller!" << std::endl;
	}
	for (int i = 0; i < k; i++)
	{
		std::cout << "TOP " << i + 1 << ": " << result[i] << std::endl;
	}
	for (int i = 0; i < k; i++)
	{
		if (infile.is_open())
		{
			outfile << "TOP " << i + 1 << ": " << result[i] << std::endl;
		}
		else
		{
			std::cout << "Output file did not find!";
			return -2;
		}
	}
	infile.close();
	outfile.close();
	return 0;
}
