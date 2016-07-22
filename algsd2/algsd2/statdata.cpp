#include <iostream>//cout,cin
#include <stdlib.h>//стандартна€ библиотека
#include <time.h>//работа со временем
#include <locale.h>//руссификаци€ консоли
#include <ctime>//clock()

using namespace std;//стандартное пространство имЄн


void multiphase(int*arr, long size, int* reversion, int* checks);//быстра€ сортировка
int vsort(char* Fname,int* reversion, int* checks);

void zap(int *arr, int size, char metk);
void write_file(int n, char flag);
//второй режим
int statdata()
{
/*	setlocale(LC_ALL,"Russia");//руссификаци€
	srand(time(0));//начало отсчЄта времени с нул€

	bool flag1 = true, flag = true, flag2 = true;
	char otv_sp, otv_method;
	int RangeStart,RangeEnd, step, reversion, checks, n;
	unsigned int start_time, end_time;
	double serch_time; 
	char str[45];
	
	//способ заполнени€ массива
	while(flag1)
	{
		cout<<"¬ведите способ заполнени€ массива\n";
		cout<<"1.—лучайными значени€ми\n2.¬ пор€дке возрастани€\n3.Ќатуральные в пор€дке убывани€\n";
		cin>>otv_sp;
		cin.clear();
		cin.sync();		
		if ((otv_sp == '1')||(otv_sp == '2')||(otv_sp == '3'))
			flag1 = false;
	}

	//диапозон значений
	cout<<"”кажите диапозон размеров массива\n";
	cin>>RangeStart>>RangeEnd;

	//шаг изменени€ размеров массива
	cout<<"”кажите шаг изменени€ размеров массива\n";
	cin>>step;
		
	//метод сортировки
	while(flag)
	{
		cout<<"¬ыберите метод сортировки\n";
		cout<<"1. орпоративный\n2.быстрый\n";
		cin>>otv_method;
		cin.clear();
		cin.sync();
		if ((otv_method == '1')||(otv_method == '2'))
			flag = false;
	}

	n = RangeStart;
	while (flag2)
	{
		write_file(n, flag1);
		switch(otv_method)
		{
		case '1'://корпоративна€ сортировка
			start_time = clock(); 
			vsort(Fname,&reversion, &checks);
			end_time = clock();	
			serch_time = (end_time-start_time)/1000.0;
			break;
		case '2'://быстра€ сортировка
			start_time = clock();
			//multiphase(mas, n, &reversion, &checks); 
			end_time = clock();
			serch_time = (end_time-start_time)/1000;
			break;
		}	
		//write_stat(n,serch_time,str);//запись результатов
		n+=step;
		if(n>=RangeEnd)
			flag2 = false;
	}*/
	return 0;
}