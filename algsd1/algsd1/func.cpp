#include <time.h>//работа со временем
#include <stdlib.h>//стандартная библиотека

//заполнение массива
void zap(int *arr, int size, char metk)
{
	srand(time(0));//начало отсчёта времени с нуля
	unsigned long i;
	switch(metk)
	{
	case '1'://заполнение случайными значениями
		for(i=0;i<size;i++)
			arr[i] = rand()%2001 -2000;	
		break;
	case '2'://заполнение в порядке возрастания
		for(i=0;i<size;i++)
			arr[i] = i;	
		break;
	case '3': //заполнение в порядке убывания
		for(i=0;i<size;i++)
			arr[i] = size-i-1;	
		break;
	}
}