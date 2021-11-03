#include<iostream>
#include<string.h>

using namespace std;

/*
	Стандартные строковые функции находяться в библиотеки
	string.h - библиотека содержит функции написаные на языке С
	cstring - библиотека содержит такие же функции написаные на языке С++
*/

//#define COPY_AND_LENGHT
//#define COPY_MEMORY
//#define CONCATENATION
//#define CONPARISON

void main()
{
	setlocale(LC_ALL, "");
#ifdef COPY_AND_LENGHT
	const unsigned int SIZE = 256;
	char str[SIZE] = {};
	cout << "Введите строку: ";
	cin.getline(str, SIZE);
	cout << str << endl;
	cout << "Длина введенной строки: " << strlen(str) << endl;

	//Копирование строк:
	char dst[SIZE] = {};
	strcpy(dst, str);//string copy
	//strcpy(dst,src);
	//dst (destination) - строка-получатель в которую скопируется другая строка
	//src (source) - строка источник содержимое которой будем копировать
	cout << "Копия строки: " << dst << endl;
#endif // COPY_AND_LENGHT

#ifdef COPY_MEMORY
	//memcpy - похожая функция которая копирует содержимое одной обл памяти в другую
	const int SIZE = 5;
	int arr[SIZE] = { 3,5,8,13,21 };
	int brr[SIZE] = {};
	memcpy(brr, arr, SIZE * sizeof(int));
	for (int i = 0; i < SIZE; i++)
	{
		cout << brr[i] << "\t";
	}
	cout << endl;
#endif // COPY_MEMORY

#ifdef CONCATENATION
	//Конкатенация (объединение/слияние) строк
	const size_t SIZE = 256;
	char str1[SIZE] = {};
	char str2[SIZE] = {};
	cout << "Введите первую строку: "; cin >> str1;
	cout << "Введите вторую строку: "; cin >> str2;
	strcat(str1, str2);
	cout << str1 << endl;
	cout << str2 << endl;
#endif // CONCATENATION

#ifdef CONPARISON
	/*char str1[] = "Hello";
char str2[] = "hello";
cout << strcmp(str1, str2) << endl;*/
//strcmp - функция может вернуть 0, >0 либо <0
//если вернулся 0 - строки идентичны
//если <0 - первый не совпадающий символ в первой строке меньше того же символа во второй строке
//если >0 - первый не совпадающий символ в первой строке больше того же символа во второй строке
	const char* movie[] =
	{
		"Hello",
		"World",
		"Avatar",
		"Terminator",
		"Captain America",
		"Tor",
		"Loki"
	};
	for (int i = 0; i < sizeof(movie) / sizeof(const char*); i++)
	{
		cout << movie[i] << endl;
	}

	for (int i = 0; i < sizeof(movie) / sizeof(const char*); i++)
	{
		for (int j = i + 1; j < sizeof(movie) / sizeof(const char*); j++)
		{
			if (strcmp(movie[i], movie[j]) > 0)
			{
				const char* buffer = movie[i];
				movie[i] = movie[j];
				movie[j] = buffer;
			}
		}
	}

	cout << "\n-------------------------------------------------------------------------\n";

	for (int i = 0; i < sizeof(movie) / sizeof(const char*); i++)
	{
		cout << movie[i] << endl;
	}
#endif // CONPARISON

	const size_t n = 5;
	char arr[n];
	memset(arr, '3', n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}