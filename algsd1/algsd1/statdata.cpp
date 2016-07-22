#include <iostream>//cout,cin
#include <stdlib.h>//стандартная библиотека
#include <time.h>//работа со временем
#include <locale.h>//руссификация консоли
#include <ctime>//clock()

using namespace std;//стандартное пространство имён

void korp_sotr(int*arr, long size, int* reversion, int* checks);//корпоративная сортировка
void fast_sort(int*arr, long size, int* reversion, int* checks);//быстрая сортировка
void zap(int *arr, int size, char metk);//заполнение массива
int write_stat(int size, double time, char* file_name);	//вывод в файл результатов

//второй режим
int statdata()
{
	setlocale(LC_ALL,"Russia");//руссификация
	srand(time(0));//начало отсчёта времени с нуля

	bool flag1 = true, flag = true, flag2 = true;
	char otv, otv_sp, otv_method;
	int RangeStart,RangeEnd, step, reversion, checks, n;
	unsigned int start_time, end_time;
	double serch_time; 
	char str[45];
	
	//способ заполнения массива
	while(flag1)
	{
		cout<<"Введите способ заполнения массива\n";
		cout<<"1.Случайными значениями\n2.В порядке возрастания\n3.Натуральные в порядке убывания\n";
		cin>>otv_sp;
		cin.clear();
		cin.sync();		
		if ((otv_sp == '1')||(otv_sp == '2')||(otv_sp == '3'))
			flag1 = false;
	}

	//диапозон значений
	cout<<"Укажите диапозон размеров массива\n";
	cin>>RangeStart>>RangeEnd;

	//шаг изменения размеров массива
	cout<<"Укажите шаг изменения размеров массива\n";
	cin>>step;
		
	//метод сортировки
	while(flag)
	{
		cout<<"Выберите метод сортировки\n";
		cout<<"1.Корпоративный\n2.быстрый\n";
		cin>>otv_method;
		cin.clear();
		cin.sync();
		if ((otv_method == '1')||(otv_method == '2'))
			flag = false;
	}
	
	puts("Введите имя файл для вывода результотов программы");
	gets(str);	

	n = RangeStart;
	while (flag2)
	{
		int *mas = new int[n];//выделение памяти динамическому массиву
		zap(mas, n, otv_sp);//заполнение массива
		switch(otv_method)
		{
		case '1'://корпоративная сортировка
			start_time = clock(); 
			korp_sotr(mas, n, &reversion, &checks);
			end_time = clock();			
			break;
		case '2'://быстрая сортировка
			start_time = clock();
			fast_sort(mas, n, &reversion, &checks); 
			end_time = clock();
			break;
		}	
		delete[] mas; //освобождение памяти	от массива
		serch_time = (end_time-start_time)/*/1000.0*/;//время сортировки
		write_stat(n,serch_time,str);//запись результатов
		n+=step;
		if(n>=RangeEnd)
			flag2 = false;
	}
	return 0;
}

//вывод в файл
int write_stat(int size, double time, char* file_name_out)	
{
	FILE *out;
	
	//проверка на возможность открытия файла
	if((out = fopen(file_name_out,"a+"))==0)
	{
		fprintf(stderr,"Невозможно открыть файл %s\n",file_name_out);
		return 1;
	}
	
	//вывод в файл размер массива и времени работы
	fprintf(out,"%d\t\t",size);
	fprintf(out,"%f\n",time);

	fclose(out);

	return 0;
}