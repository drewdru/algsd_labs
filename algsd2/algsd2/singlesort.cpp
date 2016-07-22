#include <iostream>//cout,cin
#include <stdlib.h>//стандартная библиотека
#include <time.h>//работа со временем
#include <locale.h>//руссификация консоли
#include <ctime>//clock()
#include <fstream>//потоковая работа с файлами

using namespace std;///стандартное пространство имён

void multiphase(int*arr, long size, int* reversion, int* checks);//быстрая сортировка
int vsort(char* Fname,int* reversion, int* checks);

//первый режим
int singlesort()
{
	setlocale(LC_ALL,"Russia");//руссификация консоли
	srand(time(0));//начало отсчёта времени с нуля

	int RangeStart,RangeEnd, mas, i, reversion = 0, checks = 0;
	long n;
	char otv;
	bool flag = true;
	unsigned int start_time, end_time;
	double serch_time; 
	
	//размер массива
	printf("Введите размер массива\n");
	cin>>n;

	//диапозон щначений
	cout<<"Укажите диапозон значений массива\n";
	cin>>RangeStart>>RangeEnd;

	char*Fname = "massiv.txt\0";
	ofstream txtout(Fname, ios::out|ios::trunc);//открытие файла для вывода
	//заполнение файла
	for(i=0;i<n;i++)
		if(RangeStart>=0)
		{
			mas=(rand()%(RangeEnd - RangeStart) + RangeStart);
			txtout<<mas<<" ";
		}
		else
		{
			mas=(rand()%(RangeEnd - RangeStart + 1) + RangeStart);
			txtout<<mas<<" ";
		}
	txtout.close();//закрытие файла

	//выбор метода сортировки
	while(flag)
	{
		cout<<"Выберите метод сортировки\n";
		cout<<"1.Корпоративный\n2.быстрый\n";
		cin>>otv;
		cin.clear();
		cin.sync();

		flag = false;
		switch(otv)
		{
		case '1'://корпоративная сортировка
			start_time = clock();
			vsort(Fname,&reversion, &checks);//корпоративная сортировка
			end_time = clock();
			//время работы сортировки
			cout<<"Время пирамидальной сортировки: ";
			serch_time = (end_time-start_time)/1000.0;
			cout<<serch_time<<" сек\n";
			break;
		case '2'://быстрая сортировка
			start_time = clock();
			//multiphase(mas, n, &reversion, &checks); //быстрая сортировка
			end_time = clock();
			//время работы сортировки
			cout<<"Время быстрой сортировки: ";
			serch_time = (end_time-start_time)/1000;
			cout<<(serch_time)<<" сек\n";
			break;
		default: flag = true;
		}	
//		cout<<"Количество перестановок: "<<reversion<<"\n";
//		cout<<"Количество проверок: "<<checks<<"\n";
	}
		
	return 0;
}