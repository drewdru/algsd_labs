#include <iostream>//cout,cin
#include <locale.h>//руссификация вывода в консоль

using namespace std;//стандартное пространство имён

int singlesort();//первый режим
int statdata(); //второй режим

int main()//точка входа в программу
{
	setlocale(LC_ALL,"Russian");//руссификация консоли

	bool flag = true;
	char otv;

	//цикл работы программы
	while (flag)
	{
		cout<<"Меню:\n";
		cout<<"1.Сортировка массива\n2.Накопление статистики\n3.Выход\n";
		
		cin>>otv;		
		cin.clear();
		cin.sync();

		switch(otv)
		{
		case '1'://вызов первого режима программы
			singlesort();
			break;
		case '2'://вызов второго режима программы
			statdata();
			break;
		case '3'://выход из программы
			flag=false;
			break;
		default: flag=true;
		}
		cin.clear();
		cin.sync();
		cout<<"\n";
	}

	return 0;//возврат из функции
}