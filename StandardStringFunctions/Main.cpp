#include<iostream>
#include<string.h>

using namespace std;

/*
	����������� ��������� ������� ���������� � ����������
	string.h - ���������� �������� ������� ��������� �� ����� �
	cstring - ���������� �������� ����� �� ������� ��������� �� ����� �++
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
	cout << "������� ������: ";
	cin.getline(str, SIZE);
	cout << str << endl;
	cout << "����� ��������� ������: " << strlen(str) << endl;

	//����������� �����:
	char dst[SIZE] = {};
	strcpy(dst, str);//string copy
	//strcpy(dst,src);
	//dst (destination) - ������-���������� � ������� ����������� ������ ������
	//src (source) - ������ �������� ���������� ������� ����� ����������
	cout << "����� ������: " << dst << endl;
#endif // COPY_AND_LENGHT

#ifdef COPY_MEMORY
	//memcpy - ������� ������� ������� �������� ���������� ����� ��� ������ � ������
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
	//������������ (�����������/�������) �����
	const size_t SIZE = 256;
	char str1[SIZE] = {};
	char str2[SIZE] = {};
	cout << "������� ������ ������: "; cin >> str1;
	cout << "������� ������ ������: "; cin >> str2;
	strcat(str1, str2);
	cout << str1 << endl;
	cout << str2 << endl;
#endif // CONCATENATION

#ifdef CONPARISON
	/*char str1[] = "Hello";
char str2[] = "hello";
cout << strcmp(str1, str2) << endl;*/
//strcmp - ������� ����� ������� 0, >0 ���� <0
//���� �������� 0 - ������ ���������
//���� <0 - ������ �� ����������� ������ � ������ ������ ������ ���� �� ������� �� ������ ������
//���� >0 - ������ �� ����������� ������ � ������ ������ ������ ���� �� ������� �� ������ ������
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