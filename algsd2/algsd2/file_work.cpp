#include <iostream>//потоковый ввод/вывод
#include <fstream>//потоковая работа с файлами
#include <stdio.h>//работа с файлами
#include <time.h>//работа со временем
#include <stdlib.h>//стандартная библиотека
using namespace std;//стандартное пространство имён

//считывание данных из файла
int read_file(int *B, long n)
{
	char*Fname = "massiv.txt\0";
	ifstream txtin(Fname, ios::in);//открытие файла для считывания
	txtin.seekg(0,ios::beg);//установка положения курсора в начало файла
	//считывание данных
	for (int i = 0; i<n; i++)
		txtin>>B[i];
	txtin.close();//закрытие файла
	return 0;
}
//определение количества записей в файле
long lenght_file(char*Fname)
{	
	ifstream txtin(Fname, ios::in);//открытие файла для считывание
	long cnt = 0;
	int temp;
	//подсяёт количества записей в файле
	while(txtin.cur != txtin.eof())
	{
		txtin>>temp;
		cnt++;
	}
	txtin.clear();//очищение выходного потока файла
	txtin.close();//закрытие файла
	return cnt;//возврат количества записей
}
//запись данных в файла
void write_file(int n, char flag)
{
	char*Fname = "massiv.txt\0";
	ofstream txtout(Fname, ios::out|ios::trunc);//открытие файла для вывода	
	//запись данных

	if (flag == '1')
	{
		for(int i=0;i<n;i++)
			txtout<<(rand()%2001 - 2001)<<" ";
		txtout.close();//закрытие файла
	}
	else if (flag == '2')
	{
		for(int i=0;i<n;i++)
			txtout<<i<<" ";	
	}
	else if (flag == '3')		
	{
		for(int i=0;i<n;i++)
			txtout<<(n-i-1)<<" ";	
	}
}

//заполнение массива
void zap(int *arr, int size, char metk)
{
	srand(time(0));//начало отсчёта времени с нуля
	long i;
	char*Fname = "massiv.txt\0";
	ofstream txtout(Fname, ios::out);//открытие файла для вывода
	switch(metk)
	{
	case '1'://заполнение случайными значениями
		for(i=0;i<size;i++)
			txtout<<(rand()%2001-2000)<<" ";	
		break;
	case '2'://заполнение в порядке возрастания
		for(i=0;i<size;i++)
			txtout<<i;	
		break;
	case '3': //заполнение в порядке убывания
		for(i=0;i<size;i++)
			txtout<<(size-i-1);	
		break;
	}
	txtout.close();//закрытие файла
}
