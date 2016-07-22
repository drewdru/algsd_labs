#include <iostream>//cout,cin
#include <stdio.h>
#include <stdlib.h>//стандартна€ библиотека

#define MAXSTACK 2048//деректива препроцессора (замена MAXSTACK на 2048)

using namespace std;//стандартное пространство имЄн

unsigned long rev, check;//глобальные переменные

void downHeap(int*arr, long k, long n);//корпоротивна€ сортировка построение пирамиды

//корпоративна€ сортировка
void korp_sotr(int*arr, long size, int* reversion, int* checks)
{
	long i;
	int temp; 
	rev = 0;//счЄтчик перестановок
	check = 0;//счЄтчик проверок

	// строим пирамиду 
	for(i=size/2-1; i >= 0; i--) downHeap(arr, i, size-1);
  
	// теперь a[0]...a[size-1] пирамида 
	for(i=size-1; i > 0; i--) 
	{
		rev++;
		// мен€ем первый с последним 
		temp=arr[i]; arr[i]=arr[0]; arr[0]=temp;

    // восстанавливаем пирамидальность a[0]...a[i-1] 
		downHeap(arr, 0, i-1); 
	}

	*reversion = rev;
	*checks = check;
}

//построение пирамиды
void downHeap(int*arr, long k, long n) 
{
	//  процедура просеивани€ следующего элемента 
	//  ƒо процедуры: a[k+1]...a[n]  - пирамида 
	//  ѕосле:  a[k]...a[n]  - пирамида 
	int new_elem;
	long child;
	new_elem = arr[k];

	while(k <= n/2) 
	{  	// пока у a[k] есть дети 
		child = 2*k;
		//  выбираем большего сына 
		if( child < n && arr[child] < arr[child+1] ) 
		{
			check++; 
			child++;
		}
		else
		{
			check++;
		}
		if( new_elem >= arr[child] ) 
		{
			check++;
			break;
		}
		else
		{
			check++;
			rev++;
			arr[k] = arr[child]; 	// переносим сына наверх 
			k = child;
		}
	}
	arr[k] = new_elem;
}

//быстра€ сортировка
void fast_sort(int*arr, long size, int* reversion, int* checks)
{
	rev = 0;
	check = 0;
	long i, j;   			// указатели, участвующие в разделении  
	long lb, ub;  		// границы сортируемого в цикле фрагмента
	long lbstack[MAXSTACK], ubstack[MAXSTACK]; // стек запросов
                        // каждый запрос задаетс€ парой значений,
                        // а именно: левой(lbstack) и правой(ubstack) 
                        // границами промежутка
	long stackpos = 1;   	// текуща€ позици€ стека
	long ppos;            // середина массива
	double pivot;              // опорный элемент
	int temp; 

	lbstack[1] = 0;
	ubstack[1] = size-1;

	do { 
		// ¬з€ть границы lb и ub текущего массива из стека. 
		lb = lbstack[ stackpos ];
		ub = ubstack[ stackpos ];
		stackpos--;
		do {
			// Ўаг 1. –азделение по элементу pivot
			 ppos = ( lb + ub ) >> 1;
			i = lb; 
			j = ub; 
			pivot = arr[ppos];

			do {
				while ( arr[i] < pivot ) i++;
				while ( pivot < arr[j] ) j--;

				if ( i <= j ) {
					check++;
					temp = arr[i]; 
					arr[i] = arr[j]; 
					arr[j] = temp;
					rev++;
					i++; 
					j--;
				}
			} while ( i <= j );

			// —ейчас указатель i указывает на начало правого подмассива,
			// j - на конец левого (см. иллюстрацию выше), lb ? j ? i ? ub.
			// ¬озможен случай, когда указатель i или j выходит за границу массива

			// Ўаги 2, 3. ќтправл€ем большую часть в стек  и двигаем lb,ub
			if ( i < ppos ) 
			{     // права€ часть больше
				check++;
				if ( i < ub ) 
				{     //  если в ней больше 1 элемента - нужно 
					check++;
					stackpos++;       //  сортировать, запрос в стек
					lbstack[ stackpos ] = i;
					ubstack[ stackpos ] = ub;
				}
				ub = j;     //  следующа€ итераци€ разделени€
                            //  будет работать с левой частью
			} 
			else 
			{       	    // лева€ часть больше
				if ( j > lb )
				{ 
					check++;
					stackpos++;
					lbstack[ stackpos ] = lb;
					ubstack[ stackpos ] = j;
				}
				lb = i;
			}
		} while ( lb < ub );        // пока в меньшей части более 1 элемента
	} while ( stackpos != 0 );    // пока есть запросы в стеке
	
	*reversion = rev;
	*checks = check;
}

