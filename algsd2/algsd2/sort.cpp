#include <iostream>//cout,cin
#include <fstream>//потоковая работа с файлами
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>//стандартная библиотека
#include <ctime>

using namespace std;//стандартное пространство имён

unsigned long rev, check;//глобальные переменные

long lenght_file(char*Fname);

int vsort2(char *a, int m); //фаза слияния
//сортировка прямым слиянием
int vsort(char* Fname,int* reversion, int* checks)
{
	rev = 0;
	check=0;
	FILE *A,*B,*C; //переменные файла
	int a;//чтение из исходного файла
	int nb,nc;//счётчики файлов B,C
	int p; //флаг конца исходного файла
	int m = 1; //число элементов
	int k = 0;//число элементов в исходном файле
	while(1)
	{
		if((A=fopen(Fname,"r"))==NULL)
		{
			printf("\n Невозможно открыть файл %s",Fname);
			getch();return -1;
		}
		if ((B=fopen("B","w"))==NULL)
		{
			printf("\n Невозможно открыть файл B");
			getch();
			return -1;	
		}
		if ((C=fopen("C","w"))==NULL)
		{
			printf("\n Невозможно открыть файл C");
			getch();
			return -1;
		}

		nb = 0;
		nc = 0;
		p = 0;

		while(1)
		{
			while(1)
			{
				if(fscanf(A,"%d",&a)==EOF)
				{
					check++;
					rev++;
					p=1;
					break;
				}
				else
				{
					if (nb<m) //формирование B
					{
						check++;
						rev++;
						fprintf(B," %d",a);
						k++;
						nb++;
						continue;
					}
					else
					{
						check++;
						rev++;
						fprintf(C," %d",a);
						nb = 0;
						nc++;
						break;
					}
				}
			}
			if(p)
			{
				check++;
				break;
			}
			while(1)
			{
				if(fscanf(A,"%d",&a)==EOF)
				{
					check++;
					p = 1;
					break;
				}
				else
				{
					if(nc)//!!!
					{
						rev++;
						check++;
						fprintf(C," %d",a);
						k++;
						nc++;
						continue;
					}
					else
					{
						rev++;
						check++;
						fprintf(B," %d",a);
						k++;
						nc=0;
						nb++;
						break;
					}
				}
			}
			if(p)
				break;
		}
		fclose(A);
		fclose(B);
		fclose(C);
		vsort2(Fname,m);//функция слияния
		if (m>=(k-k/2))//конец сортировки
		{
			check++;
			remove("B");
			remove("C");
			return 0;
		}
		m=m*2;
		k=0;
	}
}

//фаза слияния
int vsort2(char*a, int m)
{
	FILE *A,*B,*C; //файловые переменные
	int b,c; //считывание из B и C
	int nb,nc; //счётчики считывания B и C
	int rb, rc; //флаги завершения считывания
	if((A=fopen(a,"w"))==NULL)
	{
		printf("\nне открывается Файл %s",a);
		getch();
		return -1;		
	}
	if((B=fopen("B","r"))==NULL)
	{
		printf("\nне открывается Файл B");
		getch();
		return -1;		
	}
	if((C=fopen("C","r"))==NULL)
	{
		printf("\nне открывается Файл C");
		getch();
		return -1;		
	}
	rb = fscanf(B,"%d",&b);
	rc = fscanf(C,"%d",&c);
	nb = 1;
	nc = 1;
	while (1)
	{
		if((rb>0)&&(rc<=0))//конец файла
		{
			rev++;
			check++;
			fprintf(A," %d",b);
			while(fscanf(B,"%d", &b)>0)
			{
				fprintf(A," %d",b);
				rev++;
			}
			fclose(A);
			fclose(B);
			fclose(C);
			return 0;
		}
		else
		{
			if((rb<=0)&&(rc>0)) //Конец B
			{
				rev++;
				check++;
				fprintf(A," %d",c);
				while(fscanf(C,"%d",&c)>0)
				{
					fprintf(A," %d",c);
					rev++;
				}
				fclose(A);
				fclose(B);
				fclose(C);
				return 0;
			}
			else
				if((rb<=0)&&(rc<=0))//конец B и C
				{
					check++;
					fclose(A);
					fclose(B);
					fclose(C);
					return 0;				
				}
		}
		if((nb<=m)&&(nc<=m))
		{
			check++;
			if(b<=c)
			{
				rev++;
				check++;
				fprintf(A," %d",b);
				rb = fscanf(B,"%d",&b);
				nb++;
				continue;
			}
			else
			{
				rev++;
				check++;
				fprintf(A," %d", c);
				rc = fscanf(C,"%d", &c);
				nc++;
				continue;
			}
		}
		if((nb<=m)&&(nc>m))
		{
			rev++;
			check++;
			fprintf(A," %d",b);
			rb = fscanf(B,"%d",&b);
			nb++;
			continue;
		}
		if((nb>m)&&(nc<=m))
		{
			rev++;
			check++;
			fprintf(A," %d", c);
			rc = fscanf(C,"%d", &c);
			nc++;
			continue;
		}
		if((nb>m)&&(nc>m))
		{
			check++;
			nb = 1;
			nc = 1;
			continue;
		}
	}
}

int multiphase(char* Fname, int * reversion, int* checks)
{

	return 0;
}

