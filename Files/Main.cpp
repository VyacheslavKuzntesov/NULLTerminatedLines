#include<iostream>
#include<fstream>		//File stream (�������� ������)
using namespace std;

//#define WRITE_TOFILE
//#define READ_FROM_FILE
//#define work201
#define DZ

int StringLength(char str[]);
void Proverka(char str[]);
void Zamena(char str[]);

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//cout << "Hello World" << endl;
	ofstream fout("file.txt", ios::app); //������� � ��������� �����
	fout << "Hello World" << endl;
	fout.close(); //������ ����������� ����� ���������
	system("more file.txt");
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	ifstream fin; //������� �����
	fin.open("file.txt");
	const unsigned int SIZE = 1024;
	char sz_buffer[SIZE]{};//� ��� ������ ����� ������ �� ����� sz_ - String Zero(������ ��������������� �����) 
	if (fin.is_open()) // ���������, ������ �� ����
	{
		//TODO:���� ������ ����� ������ ����
		while (!fin.eof())
		{
			//eof() - end of file
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
	}
	else
	{
		cerr << "Error: file not found" << endl;
	}
	fin.close();
#endif // READ_FROM_FILE

	//� ����� 201 RAW.txt �������� ������� �������� � ���-�������, � IP-�������
	//�������� ���� ������ �������� ����������, ��������� ������ ������� ����� ���������� ����
	//201 ready.txt

#ifdef work201
	ifstream fin;
	fin.open("201 RAW.txt");
	ofstream fout("201 ready.txt");
	const unsigned int IP_SIZE = 16;
	const unsigned int MAC_SIZE = 18;
	char sz_ip_buffer[IP_SIZE]{};
	char sz_mac_buffer[MAC_SIZE]{};
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;
			//cout << sz_ip_buffer << '\t';
			//cout << sz_mac_buffer << '\n';
			fout << sz_mac_buffer << '\t';
			fout << sz_ip_buffer << '\n';
		}
	}
	else
	{
		cerr << "Error: file not found" << endl;
	}
	fout.close();
	fin.close();
#endif // work201

#ifdef DZ
	ifstream fin;
	char OpenFileName[256] = {};
	char NewFileName[256] = {};
	cout << "������� ��� ������������ �����: "; cin.getline(OpenFileName, 100);
	cout << "������� ��� ������������ �����: "; cin.getline(NewFileName, 100);
	Proverka(OpenFileName);
	Proverka(NewFileName);
	fin.open(OpenFileName);
	ofstream fout(NewFileName);

	const unsigned int IP_SIZE = 16;
	const unsigned int MAC_SIZE = 18;
	char sz_ip_buffer[IP_SIZE]{};
	char sz_mac_buffer[MAC_SIZE]{};

	int i = 1;
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin >> sz_ip_buffer;
			fin >> sz_mac_buffer;
			Zamena(sz_mac_buffer);
			if (i != 5)
			{
				fout << "host 201-" << i << '\n';
				fout << "{" << '\n';
				fout << '\t' << "hardware ethernet" << '\t' << sz_mac_buffer << ";" << '\n';
				fout << '\t' << "fixed-address" << '\t' << '\t' << sz_ip_buffer << ";" << '\n';
				fout << "}" << '\n';
				fout << '\n';
			}
			else
			{
				fout << "host 201-" << i << '\n';
				fout << "#{" << '\n';
				fout << "#" << '\t' << "hardware ethernet" << '\t' << sz_mac_buffer << ";" << '\n';
				fout << "#" << '\t' << "fixed-address" << '\t' << '\t' << sz_ip_buffer << ";" << '\n';
				fout << "#}" << '\n';
				fout << '\n';
			}
			i++;
		}
	}
	else
	{
		cerr << "Error: file not found" << endl;
	}

	fout.close();
	fin.close();

	char sz_cmd[256] = "notepad ";
	strcat(sz_cmd, NewFileName);

	//strcat(sz_dst,sz_src);//strcat ��������� ������������(�������) �����
	//��������, "Hello"+"World" = "HelloWorld";
	//sz_dst - ������ ����������, � ������� ����� �������� ��������� ������������
	//Source - ��������, ��������.
	//Destination - ����� ����������, ����������.
	//sz_src - ������ ��������, ������� ����� ��������� � ����������
	
	// char* extension = strrchr(sz_OpenFileName,'.');
	// cout <<(extension ? extension : "� ����� ��� ����������")<<endl;
	// if(extension == nullptr || strcmp(extension))
	//char* strchr(char* str, char symbol); - ������� �������� ������(symbol) � �������� ������(str) � ���������� ��������� �� ��������� ������. ���� ��������� ������(symbol) � ��������� ������(str) �� ������ �� ������� strchr ���������� ��������� �� ����(nullptr)
	//������� strrchr(char* str) - ������ ���� ����� �� ������� � ����� ������

	system(sz_cmd);
#endif // DZ

	/*const unsigned int SIZE = 256;
	char sz_filename[SIZE] = {};
	cout << "������� ��� �����: "; cin.getline(sz_filename, SIZE);
	ifstream fin(sz_filename);*/

}

int StringLength(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void Proverka(char str[])
{
	int n = StringLength(str);
	if (str[n - 4] != '.' || str[n - 3] != 't' || str[n - 2] != 'x' || str[n - 1] != 't')
	{
		str[n] = '.';
		str[n + 1] = 't';
		str[n + 2] = 'x';
		str[n + 3] = 't';
	}
}

void Zamena(char str[])
{
	int n = StringLength(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] == '-')str[i] = ':';
	}
}


/*
	������ � �������
	������ � ������� � ����� �++ ����� ������ �� ����� �� ����� � ���� � ����������
	��� ������ �� ����� �� ���������� ����� cout � ��� ����� � ���������� ����� cin
	���������� ��� ������ ���������� � ���� ������������ ����� fout ��� ������ ����� ������������ ����� fin
	cout �������� �������� ������ (ostream - ����� ������) � cin ������ (istream - ����� �����)
	fout �������� �������� ������ (ofstream - output file stream(����� ������ � ����)) � fin ������ (ifstream - Input file stream(����� ����� � ����))
	������������ ��������� ������� ����� ������ � ���������� � �� �����(cin cout) � �������� ����� ������ �� ����� � ���� �������� �� ��� cin/cout ��� ���������� � fin/fout ����� ��������� ��������������� ����� �������/������� �����.
	������ cin/cout ��������� � ���������� iostream
	������ fin/fout ��������� � ���������� fstream
*/
