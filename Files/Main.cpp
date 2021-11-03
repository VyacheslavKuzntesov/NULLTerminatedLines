#include<iostream>
#include<fstream>		//File stream (файловые потоки)
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
	ofstream fout("file.txt", ios::app); //Создаем и открываем поток
	fout << "Hello World" << endl;
	fout.close(); //Потоки обязательно нужно закрывать
	system("more file.txt");
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	ifstream fin; //создаем поток
	fin.open("file.txt");
	const unsigned int SIZE = 1024;
	char sz_buffer[SIZE]{};//в эту строку будем читать из файла sz_ - String Zero(строка заканчивающаяся нулем) 
	if (fin.is_open()) // проверяем, открыт ли файл
	{
		//TODO:если открыт будем читать файл
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

	//В файле 201 RAW.txt поменять местами столбики с МАС-адресом, и IP-адресом
	//Исходный файл должен остаться неизменным, программа должна создать новый измененный файл
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
	cout << "Введите имя открываемого файла: "; cin.getline(OpenFileName, 100);
	cout << "Введите имя сохраняемого файла: "; cin.getline(NewFileName, 100);
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

	//strcat(sz_dst,sz_src);//strcat выполняет конкатенацию(слияние) строк
	//например, "Hello"+"World" = "HelloWorld";
	//sz_dst - строка получатель, в которую будет сохранен результат конкатенации
	//Source - исходник, источник.
	//Destination - пункт назначения, получатель.
	//sz_src - строка источник, которая будет добавлена к получателю
	
	// char* extension = strrchr(sz_OpenFileName,'.');
	// cout <<(extension ? extension : "У файла нет расширения")<<endl;
	// if(extension == nullptr || strcmp(extension))
	//char* strchr(char* str, char symbol); - находит указаный символ(symbol) в указаной строке(str) и возвращает указатель на найденный символ. Если указанный символ(symbol) в указанной строке(str) не найден то функция strchr возвращает указатель на ноль(nullptr)
	//Функция strrchr(char* str) - делает тоже самое но наченая с конца строки

	system(sz_cmd);
#endif // DZ

	/*const unsigned int SIZE = 256;
	char sz_filename[SIZE] = {};
	cout << "Введите имя файла: "; cin.getline(sz_filename, SIZE);
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
	Работа с файлами
	Работа с файлпми в языке с++ очень похожа на вывод на экран и ввод с клавиатуры
	для вывода на экран мы используем поток cout а для ввода с клавиатуры поток cin
	аналогично для вывода информации в файл используется поток fout для чтения файла используется поток fin
	cout является объэктом класса (ostream - поток вывода) а cin класса (istream - поток ввода)
	fout является объэктом класса (ofstream - output file stream(поток вывода в файл)) а fin класса (ifstream - Input file stream(поток ввода в файл))
	Единственным различием потоков ввода вывода с клавиатуры и на экран(cin cout) и потоками ввода вывода из файла в файл является то что cin/cout уже существуют а fin/fout нужно создавать непосредственно перед чтением/записью файла.
	Потоки cin/cout находятся в библиотеки iostream
	Потоки fin/fout находятся в библиотеки fstream
*/
