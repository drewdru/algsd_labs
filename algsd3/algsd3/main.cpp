#include <iostream>
#include <locale.h>
#include "class_spisok.h"
using namespace std;

int menu(List& lst, int metk);
int main()
{
	setlocale(LC_ALL, "Russian");

	List lst1;
	List lst2;
	
	cout<<"Двусвязный список:\n";
	while (true)
	{
		int flag = 0;
		flag = menu(lst1,1);
		if (flag == 1)
		{
			flag = menu(lst2,2);		
		}
		if (flag == 0)
			return 0;
		if (flag == 2)
		{
			lst1.clear_not_lis2(lst2);
			cout<<"В 1 списке остались элементы:\n";
			lst1.Show();
		}
	}
}

int menu(List& lst, int metk)
{
	int otv, otv2;
	int elem;
	int num, n;
	int res;
	bool k,b;

	while (true)
	{
		cout<<"\n1.Добавление элемента в начало списка\n";
		cout<<"2.Добавление элемента в конец списка\n";
		cout<<"3.Добавление элемента на № позиции списка\n";
		cout<<"4.Удаление элемента из начала списка\n";
		cout<<"5.Удаление элемента из конца списка\n";
		cout<<"6.Удаление элемента из № позиции списка\n";
		cout<<"7.Очистить список\n";
		cout<<"8.Поиск элементов списка по значению\n";
		cout<<"9.Поиск элемента списка по номеру\n";
		cout<<"10.Вывод элементов списка на экран\n";
		cout<<"11.Удалить элементы списка с наиболее часто встечаемым значением\n";
		if (metk == 1)
			cout<<"12.Создать новый список и удалить из перевого те элементы,\nкоторых нет во втором\n";
		else
			cout<<"12.Завершить заполнение второго списка\n";
		cout<<"13.Выход\n";
		cin>>otv;
		cin.clear();
		cin.sync();

		switch (otv)
		{
		case 1:
			cout<<"Введите элемент: ";
			cin>>elem;
			cin.clear();
			cin.sync();
			lst.Add_start(elem);
			cout<<"\nЭлемент добавлен в начало списка\n";
			break;
		case 2:
			cout<<"Введите элемент: ";
			cin>>elem;
			cin.clear();
			cin.sync();
			lst.Add_end(elem);
			cout<<"\nЭлемент добавлен в конец списка\n";
			break;
		case 3:
			cout<<"Введите позицию для добавления элемента в список: ";
			cin>>num;
			cin.clear();
			cin.sync();
			cout<<"\nВведите элемент: ";
			cin>>elem;
			cin.clear();
			cin.sync();
			lst.Add_num(elem, num);
			cout<<"\nЭлемент добавлен в список на позицию №"<<num<<"\n";
			break;
		case 4:
			k = true;
			res = lst.Del_start(&k);
			if (k)
				cout<<"Первый элемент со значением "<<res<<" удалён из списка\n";
			else
				cout<<"Элемент удалят не требуется\n";
			break;
		case 5:
			k = true;
			res = lst.Del_end(&k);
			if (k)
				cout<<"Последний элемент со значением "<<res<<" удалён из списка\n";
			else
				cout<<"Элемент удалят не требуется\n";
			break;		
		case 6:
			cout<<"Введите позицию для удаление элемента из списка: ";
			cin>>num;
			cin.clear();
			cin.sync();
			k = true;
			elem = lst.Del_num(num,&k);
			if (k)
				cout<<"\nЭлемент №"<<num<<" со значением "<<elem<<" удалён из списка\n";
			else
				cout<<"Элемент удалят не требуется\n";
			break;
		case 7:
			lst.Clear();
			cout<<"Список очищен\n";
			break;
		case 8:
			cout<<"Введите искомое значение: ";
			cin>>elem;
			cin.clear();
			cin.sync();
			cout<<"\nПозиция элементов с искомым значением:\n";
			k = true;
			lst.Find(elem, &k);
			if(!k)
				cout<<"Элементов с данным значением не найдено\n";
			break;
		case 9:
			cout<<"Введите номер в списке искомог значения: ";
			cin>>num;
			cin.clear();
			cin.sync();
			cout<<"\nЗначение искомого элемента:\n";
			lst.Show_number(num);
			break;
		case 10:
			cout<<"В списке содержаться следующие элементы:\n";
			k = lst.Show();
			break;
		case 11:
			cout<<"В списке содержаться следующие элементы:\n";
			k = lst.Show();
			if (k)
			{
				b = true;
				n = lst.del_often(&b);
				if(b)
					cout<<"Элементы с наиболее часто встечаемым значением: "<<n<<" удалены\n";
				else
					cout<<"Список пуст\n";
			}
			break;
		case 12:
			if (metk == 1)
			{
				cout<<"Вы заполнили список 1?(1/0)\n";
				cin>>otv2;
				if (otv2 == 1)
					return 1;
			}
			else if (metk == 2)
			{
				cout<<"Вы заполнили список 2?(1/0)\n";
				cin>>otv2;
				if (otv2 == 1)
					return 2;
			}
			break;
		case 13:
			return 0;
		default: break;
		}
	}
}