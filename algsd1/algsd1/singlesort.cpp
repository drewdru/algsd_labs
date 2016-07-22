#include <iostream>//cout,cin
#include <stdlib.h>//стандартна€ библиотека
#include <time.h>//работа со временем
#include <locale.h>//руссификаци€ консоли
#include <ctime>//clock()

using namespace std;///стандартное пространство имЄн


void korp_sotr(int*arr, long size, int* reversion, int* checks);//корпоративна€ сортировка
void fast_sort(int*arr, long size, int* reversion, int* checks);//быстра€ сортировка
int write_mas(int*arr,  int nlen);//вывод массива

//первый режим
int singlesort()
{
	setlocale(LC_ALL,"Russia");//руссификаци€ консоли
	srand(time(0));//начало отсчЄта времени с нул€

	int RangeStart,RangeEnd, i, reversion, checks;
	long n;
	char otv;
	bool flag = true;
	unsigned int start_time, end_time;
	double serch_time; 

	//размер массива
	printf("¬ведите размер массива\n");
	cin>>n;

	int *mas = new int[n];//динамический массив
	
	//диапозон щначений
	cout<<"”кажите диапозон значений массива\n";
	cin>>RangeStart>>RangeEnd;

	//заполнение массива
	for(i=0;i<n;i++)
		if(RangeStart>=0)
			mas[i] = rand()%(RangeEnd - RangeStart) + RangeStart;
		else
			mas[i] = rand()%(RangeEnd - RangeStart + 1) + RangeStart;

	//выбор метода сортировки
	while(flag)
	{
		cout<<"¬ыберите метод сортировки\n";
		cout<<"1. орпоративный\n2.быстрый\n";
		cin>>otv;
		cin.clear();
		cin.sync();

		flag = false;
		switch(otv)
		{
		case '1'://корпоративна€ сортировка
			printf("¬ывод исходного массива\n");
			write_mas(mas, n);//вывод массива
			start_time = clock();
			korp_sotr(mas, n, &reversion, &checks);//корпоративна€ сортировка
			end_time = clock();
			printf("¬ывод отсортированного массива\n");
			write_mas(mas, n);	//вывод массива	
			//врем€ работы сортировки
			cout<<"¬рем€ пирамидальной сортировки: ";
			serch_time = (end_time-start_time)/1000.0;
			cout<<serch_time<<" сек\n";
			break;
		case '2'://быстра€ сортировка
			printf("¬ывод исходного массива\n");
			write_mas(mas, n);//вывод массива	
			start_time = clock();
			fast_sort(mas, n, &reversion, &checks); //быстра€ сортировка
			end_time = clock();
			printf("¬ывод отсортированного массива\n");
			write_mas(mas, n);//вывод массива	
			//врем€ работы сортировки
			cout<<"¬рем€ быстрой сортировки: ";
			serch_time = (end_time-start_time)/1000;
			cout<<(serch_time)<<" сек\n";
			break;
		default: flag = true;
		}	
		cout<<" оличество перестановок: "<<reversion<<"\n";
		cout<<" оличество проверок: "<<checks<<"\n";
	}

	delete[] mas;//освобождение пам€ти

	return 0;
}

//вывод массива
int write_mas(int*arr, int nlen)
{	
	int i,k = 12;
	char file_name_out[45];
	FILE *out;
	puts("¬ведите им€ файл дл€ вывода массива");
	gets(file_name_out);
	
	//проверка на возможность открыть файл
	if((out = fopen(file_name_out,"a+"))==0)
	{
		fprintf(stderr,"Ќевозможно открыть файл %s\n",file_name_out);
		return 1;
	}
	
	//вывод массива в файл
	for (i = 0; i<nlen; i++)
	{
		fprintf(out,"%d, ",arr[i]);
		if(i == k)
		{
			fprintf(out,"\n");
			k+=12;
		}
	}
	
	fprintf(out,"\n\n\n");
	fclose(out);//закрытие файла

	return 0;
}