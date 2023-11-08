// Дана строка, содержащая русский текст.
// Если в тексте нет слов-палиндромов длиной более 1-й буквы,
// то вывести слова текста в соответствии с убыванием количества звонких согласных,
// в противном случае удалить из слов текста гласные буквы
// и вывести полученные слова в поpядке, обpатном к алфавитному.
//( Звонкие согласные:   бвгжздйлмнр )

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

int zvonk_number(std::string zvonk, std::string word)
{
	int count = 0;
	for (int i = 0; i < zvonk.length(); i++)
		for (int j = 0; j < word.length(); j++)
		{
			if (word[j] == zvonk[i])
				count++;
		}
	return count;
}

int words_compare(std::string a, std::string b)
{
	int i = 0;
	for (i; a[i] == b[i]; i++)
	{
	}
	if (a[i] > b[i])
	{
		return true;
	}
	else
		return false;
}

void glasnye_delete(std::string &str, std::string glas)
{
	for (int i = 0; i < glas.length(); i++)
		for (int j = 0; j < str.length(); j++)
			if (glas[i] == str[j])
				str.erase(j, 1);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	std::string word;
	std::string *words;
	bool havingpalindrom = false;
	bool srabotal = false;
	std::string palindrom;
	std::string glasnye = "ёуеыаоэяию";
	std::string zvonk = "бвгжздйлмнр";

	std::ifstream file;
	file.open("C:\\Users\\Alexander\\.vscode\\Projects\\Files\\input2.txt");
	if (!file.is_open())
	{
		std::cout << "File isn't open! ";
		return -1;
	}
	int index = 0;
	int n = 0;

	for (n; file >> word; n++)
	{
	}
	words = new std::string[n];

	std::ifstream filee;
	filee.open("C:\\Users\\Alexander\\.vscode\\Projects\\Files\\input2.txt");
	for (index; filee >> word; index++)
	{
		word[0] = std::tolower(word[0]);
		int lastpos = word.length() - 1;
		for (int i = lastpos; i >= 0; i--)
		{
			if (ispunct(word[i]) || isdigit(word[i]))
				word[i] = '\0';
			else if (ispunct(word[0]) || isdigit(word[0]))
				word[0] = '\0';
			else
				break;
		}
		int dlina = word.length();
		int count = 0;
		if (!havingpalindrom && dlina > 1)
		{
			for (int i = 0; i < dlina - i - 1; i++)
			{
				if (word[i] != word[dlina - i - 1])
				{
					count++;
				}
			}
			if (count == 0)
			{
				palindrom = word;
				havingpalindrom = true;
			}
		}
		words[index] = word;
	}

	std::string tmp;
	if (havingpalindrom)
	{
		if (!srabotal)
		{
			std::cout << "The text have a palindrom! " << palindrom << std::endl;
			srabotal = true;
		}
		for (int m = 0; m < index; m++)
		{
			glasnye_delete(words[m], glasnye);
		}
		for (int i = 0; i < index - 1; i++)
		{

			for (int j = i + 1; j < index; j++)
			{
				if (!words_compare(words[i], words[j]))
				{
					tmp = words[i];
					words[i] = words[j];
					words[j] = tmp;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < index - 1; i++)
			for (int j = i + 1; j < index; j++)
			{
				if (zvonk_number(zvonk, words[i]) < zvonk_number(zvonk, words[j]))
				{
					tmp = words[i];
					words[i] = words[j];
					words[j] = tmp;
				}
			}
	}
	for (int i = 1; i < index; i++)
		std::cout << words[i] << " ";
	return 0;
}