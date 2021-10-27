#include<iostream>
#include<Windows.h>
using namespace std;

int StringLength(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);
bool is_int_number(char str[]);
bool is_bin_number(char str[]);
bool is_hex_number(char str[]);
int string_to_int(char str[]);
int bin_to_int(char str[]);
int hex_to_int(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);			//кодировка на ввод с консоли
	SetConsoleOutputCP(866);	//кодировка на вывод в консоле
	//char str[] = {'H','e','l','l','o',0};
	//char str[] = "Hello";

	const int n = 20;
	char str[n] = {};
	cout << "Введите строку: ";
	//cin >> str;
	cin.getline(str, n);
	cout << str << endl;
	cout << StringLength(str) << endl;
	//to_upper(str);
	//cout << str << endl;
	//to_lower(str);
	//cout << str << endl;
	//shrink(str);
	//cout << str << endl;
	//cout << is_palindrome(str);
	//cout << is_int_number(str);
	//cout << is_bin_number(str);
	//cout << is_hex_number(str);
	//cout << string_to_int(str);
	//cout << bin_to_int(str);
	cout << hex_to_int(str);
}

int StringLength(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_upper(char str[])
{
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		if (str[i] >= 'а' && str[i] <= 'я')
			str[i] -= 32;
	}
}

void to_lower(char str[])
{
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if (str[i] >= 'А' && str[i] <= 'Я')
			str[i] += 32;
	}
}

void shrink(char str[])
{
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			int cut = i + 1;
			i--;
			for (; cut < n; ++cut) str[cut] = str[cut + 1];
		}
	}
}

bool is_palindrome(char str[])
{
	bool palindrome = 1;
	int n = StringLength(str);
	for (int i = 0; i <= n; i++,n--)
	{
		if (str[i] != str[n-1])
		{
			palindrome = 0;
			break;
		}
	}
	return palindrome;
}

bool is_int_number(char str[])
{
	bool int_number = 1;
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if (str[0] == '0')
		{
			int_number = 0;
			break;
		}
		if (str[i] > '9' || str[i] < '0')
		{
			int_number = 0;
			break;
		}
	}
	return int_number;
}

bool is_bin_number(char str[])
{
	bool bin_number = 1;
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] != '1' && str[i] != '0')
		{
			bin_number = 0;
			break;
		}
	}
	return bin_number;
}

bool is_hex_number(char str[])
{
	bool hex_number = 1;
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if ((str[i] > '9' || str[i] < '0') && (str[i] < 'A' || str[i] > 'F') && (str[i] < 'a' || str[i] > 'f'))
		{
			hex_number = 0;
			break;
		}
	}
	return hex_number;
}

int string_to_int(char str[])
{
	int n = StringLength(str);
	int chislo = 0;
	if (!is_int_number(str))
	{
		cout << "Данная строка не является целым десятичным числом" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			chislo = chislo * 10 + (str[i] - '0');
		}
		return chislo;
	}
}

int bin_to_int(char str[])
{
	int n = StringLength(str);
	int chislo = 0;
	if (!is_bin_number(str))
	{
		cout << "Данная строка не является двоичным числом" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			chislo += (str[i] - 48) * pow(2.0, double(n - i - 1));
		}
		return chislo;
	}
}

int hex_to_int(char str[])
{
	int n = StringLength(str);
	int chislo = 0;
	if (!is_hex_number(str))
	{
		cout << "Данная строка не является шестнадцатеричным числом" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (str[i] >= 48 && str[i] <= 57)
			{
				chislo += (str[i] - '0') * pow(16, n - i - 1);
			}
			else if (str[i] >= 65 && str[i] <= 70) {
				chislo += (str[i] - 55) * pow(16, n - i - 1);
			}
			else if (str[i] >= 97 && str[i] <= 102) {
				chislo += (str[i] - 87) * pow(16, n - i - 1);
			}
		}
		return chislo;
	}
}

/*
	Строка в языке С предстовляет собой массив элементов типа char, последним элементов этого массива обязательно должен быть ASCi символ с кодом 0 - ('\0')
	именно по этому строки в языке С называют NULL Terminated Lines(строки заканчивающиеся на ноль) ноль на конце являеться признаком конца строки и даже если строка содержит символы после нуля эти символы будут проигнорированы
*/