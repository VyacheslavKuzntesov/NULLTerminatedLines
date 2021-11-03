#include<iostream>
#include<Windows.h>
#include<fstream>
using namespace std;

int StringLength(char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[], char symbol, int mode);
bool is_palindrome(char str[]);
bool is_int_number(char str[]);
bool is_bin_number(char str[]);
bool is_hex_number(char str[]);
int string_to_int(char str[]);
int bin_to_int(char str[]);
int hex_to_int(char str[]);
bool is_mac_address(char str[]);
bool is_ip_address(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);			//кодировка на ввод с консоли
	SetConsoleOutputCP(1251);	//кодировка на вывод в консоле
	//char str[] = {'H','e','l','l','o',0};
	//char str[] = "Hello";

	const int n = 1024;
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
	//cin >> str[n];
	cout << is_palindrome(str);
	cout << endl;
	cout << str << endl;
	//cout << is_int_number(str);
	//cout << is_bin_number(str);
	//cout << is_hex_number(str);
	//cout << string_to_int(str);
	//cout << bin_to_int(str);
	//cout << hex_to_int(str);
	if (is_palindrome)
	{
		cout << "true";
	}
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
		if (str[i] >= 'a' && str[i] <= 'z')str[i] -= 32;
		if (str[i] >= 'а' && str[i] <= 'я')str[i] -= 32;
	}
}

void to_lower(char str[])
{
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')str[i] += 32;
		if (str[i] >= 'А' && str[i] <= 'Я')str[i] += 32;
	}
}

void shrink(char str[],char symbol,int mode)
{
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if (mode == 0)
		{
			if (str[i] == symbol)
			{
				int cut = i;
				i--;
				for (; cut < n; ++cut) str[cut] = str[cut + 1];
				n--;
			}
		}
		if (mode == 1)
		{
			if (str[i] == symbol && str[i + 1] == symbol)
			{
				int cut = i + 1;
				i--;
				for (; cut < n; ++cut) str[cut] = str[cut + 1];
				n--;
			}
		}
	}
}

bool is_palindrome(char str[])
{
	bool palindrome = 1;
	int n = StringLength(str);
	for (int i = 0; i <= n; i++,n--)
	{
		if (str[i] == ' ')i++;
		if (str[n - 1] == ' ')n--;
		if (str[i] != str[n - 1] && str[i] != (str[n - 1] - 32) && str[i] != (str[n - 1] + 32))
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

bool is_mac_address(char str[])
{
	int n = StringLength(str);
	int length = 0;
	bool this_is_the_mac_address = 1;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == ':' || str[i] == '-' || str[i] == '.')
		{
			length = 0;
		}
		else if (str[i] > '9' && str[i] < '0' || str[i] < 'A' && str[i]>'F' || str[i] < 'a' && str[i]>'f')
		{
			this_is_the_mac_address = 0;
			break;
		}
		else
		{
			if (length>2)
			{
				this_is_the_mac_address = 0;
				break;
			}
		}
		length++;
	}
	return this_is_the_mac_address;
}

bool is_ip_address(char str[])
{
	int n = StringLength(str);
	int length = 0;
	bool this_is_the_ip_address = 1;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '.')
		{
			length = 0;
		}
		else if (str[i] > '9' && str[i] < '0')
		{
			this_is_the_ip_address = 0;
			break;
		}
		else
		{
			if (length > 3)
			{
				this_is_the_ip_address = 0;
				break;
			}
		}
		length++;
	}
	return this_is_the_ip_address;
}

/*
	Строка в языке С предстовляет собой массив элементов типа char, последним элементов этого массива обязательно должен быть ASCi символ с кодом 0 - ('\0')
	именно по этому строки в языке С называют NULL Terminated Lines(строки заканчивающиеся на ноль) ноль на конце являеться признаком конца строки и даже если строка содержит символы после нуля эти символы будут проигнорированы
*/