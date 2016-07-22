#include<iostream>
#include<cstdlib>
#include<fstream>
#include<stdlib.h>

using namespace std;

struct Node       //Структура являющаяся звеном списка
{
	int x;     //Значение x будет передаваться в список
	Node *Next,*Prev; //Указатели на адреса следующего и предыдущего элементов списка
};

class List   //Создаем тип данных Список
{
	Node *Head,*Tail; //Указатели на адреса начала списка и его конца
public:
	List():Head(NULL),Tail(NULL){}; //Инициализируем адреса как пустые
	~List(); //Деструктор
	void Add_start(int x); //Функция добавления элементов в начало списока
	void Add_end(int x); //Функция добавления элементов в конец списка
	void Add_num(int x, int p);//Функция добавления элементов на позицию в списке
	int Del_end(bool*kkk);//Функция удаления последнего элемента списка
	int Del_start(bool*kkk);//Функция удаления первого элемента списка	
	int Del_num(int pos, bool*kkk);//Функция удаления элементов с позиции в списке
	void Clear();
	bool Show(); //Функция отображения списка на экране
	void Show_number(int p);
	void Find(int p, bool*kkk);
	int del_often(bool*kkk);
	int size();
	void clear_not_lis2(List& lst2);
};

List::~List() //Деструктор
{   
	while (Head) //Пока по адресу на начало списка что-то есть
	{
		Tail=Head->Next; //Резервная копия адреса следующего звена списка
		delete Head; //Очистка памяти от первого звена
		Head=Tail; //Смена адреса начала на адрес следующего элемента
	}
}

int List::size()
{
	Node *temp=Tail;
	int cnt = 1;
	temp=Head; //Временно указываем на адрес первого элемента
	while (temp!=NULL) //Пока не встретим пустое значение
	{
		temp=temp->Next; //Смена адреса на адрес следующего элемента
		cnt++;
	}
	return cnt;
}

void List::Add_start(int x)
{
	Node *temp=new Node; //Выделение памяти под новый элемент структуры
	temp->Prev=NULL;  //Указываем, что изначально по предыдущему адресу пусто
	temp->x=x;//Записываем значение в структуру
 
	if (Head!=NULL) //Если список не пуст
	{
		temp->Next=Head; //Указываем адрес на следующий элемент в соотв. поле
		Head->Prev=temp; //Указываем адрес предыдущего за хвостом элемента
		Head=temp; //Меняем адрес хвоста
	}
	else //Если список пустой
	{
		temp->Next=NULL; //Следующий элемент указывает в пустоту
		Head=Tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
	}
}


void List::Add_end(int x)
{
	Node *temp=new Node; //Выделение памяти под новый элемент структуры
	temp->Next=NULL;  //Указываем, что изначально по следующему адресу пусто
	temp->x=x;//Записываем значение в структуру
 
	if (Head!=NULL) //Если список не пуст
	{
		temp->Prev=Tail; //Указываем адрес на предыдущий элемент в соотв. поле
		Tail->Next=temp; //Указываем адрес следующего за хвостом элемента
		Tail=temp; //Меняем адрес хвоста
	}
	else //Если список пустой
	{
		temp->Prev=NULL; //Предыдущий элемент указывает в пустоту
		Head=Tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
	}
}

//добавить узел в список в определённую позицию
void List::Add_num(int x, int p)
{
	Node *temp=new Node; //Выделение памяти под новый элемент структуры
	temp->Next=NULL;  //Указываем, что изначально по следующему адресу пусто
	temp->Prev=NULL;  //Указываем, что изначально по предыдущему адресу пусто
	temp->x=x;//Записываем значение в структуру
 
	if (Head!=NULL) //Если список не пуст
	{
		Node *t = Head;
		for(int i=p;i>1;i--,t=t->Next);
		t->Prev->Next=temp;
		temp->Prev=t->Prev; //Указываем адрес на предыдущий элемент в соотв. поле
		temp->Next=t;//добавляем элемент перед t
		t->Prev=temp;
	}
	else //Если список пустой
	{
		temp->Prev=NULL; //Предыдущий элемент указывает в пустоту
		temp->Next=NULL; //Предыдущий элемент указывает в пустоту
		Head=Tail=temp; //Голова=Хвост=тот элемент, что сейчас добавили
	}
}

int List::Del_start(bool*kkk)//удалить узел по индексу из списка
{
	int val;
	if(Head==NULL) 
	{
		*kkk = false;
		return 0;//спсок пуст	
	}
	if(Head->Next==NULL)//если это последний элемент в списке
	{
		val=Head->x;
		delete Head;
		Head=NULL;
	}
	else
	{	
		Node *t = Head;
		val = Head->x;
		Head = Head->Next;
		delete t;
	}
	return val;
}

int List::Del_end(bool*kkk)
{
	int val;
	if(Head==NULL) 
	{
		*kkk = false;
		return 0;//спсок пуст	
	}
	if(Head->Next==NULL)//если это последний элемент в списке
	{
		val=Head->x;
		delete Head;
		Head=NULL;
	}
	else
	{	
		Node *t = Tail;
		val = Tail->x;
		Tail = Tail->Prev;
		Tail->Next = NULL;
		delete t;
	}
	return val;}

int List::Del_num(int pos, bool*kkk)//удалить узел по индексу из списка
{
	int val;
	if(Head==NULL) 
	{
		*kkk = false;
		return 0;//спсок пуст	
	}
	if((pos>size()-1)||(pos<1))
	{
		*kkk = false;
		return 0;
	}
	if(Head->Next==NULL)//если это последний элемент в списке
	{
		val=Head->x;
		delete Head;
		Head=NULL;
	}
	else if(pos==1)
	{
		val = Del_start(kkk);
	}
	else if(pos==size() - 1)
	{
		val = Del_end(kkk);
	}
	else
	{			
		Node *t=Head;
		for(int i=pos;i>1;i--,t=t->Next);
		if(t==Head)Head=t->Next;//если пытаемся удалить 1-ый элемент то голова указывает на 2-ой
		t->Prev->Next=t->Next;//удаляем t элемент
		t->Next->Prev=t->Prev;
		val=t->x;
		delete t;		
	}
	return val;
}

void List::Clear()
{
	List ls;
	Node *temp=Tail;
	temp=Head; //Временно указываем на адрес первого элемента
	while (temp!=NULL) //Пока не встретим пустое значение
	{		
		Head = Head->Next;
		temp = Head;
	}
}


bool List::Show()
{
	Node *temp=Tail;
	int cnt = 0;
//ВЫВОДИМ СПИСОК С НАЧАЛА
	temp=Head; //Временно указываем на адрес первого элемента
	while (temp!=NULL) //Пока не встретим пустое значение
	{
		cout<<temp->x<<" "; //Выводим каждое считанное значение на экран
		temp=temp->Next; //Смена адреса на адрес следующего элемента
		cnt++;
	}
	if(cnt == 0)
	{
		cout<<"В списке не содержатся элементы\n";
		return false;
	}
	cout<<"\n";
	return true;
 }

void List::Show_number(int p)
{
	if (Head!=NULL) //Если список не пуст
		{
			Node *t = Head;
			for(int i=p;i>1;i--,t=t->Next);
			cout<<t->x<<"\n";
		}
	else
		cout<<"Список пуст\n";
}

void List::Find(int p, bool*kkk)
{
	Node *temp=Tail;
	int cnt = 1;
	int cnt2 = 1;
	temp=Head; //Временно указываем на адрес первого элемента
	while (temp!=NULL) //Пока не встретим пустое значение
	{
		if(temp->x==p)
		{
			cout<<cnt<<" ";
			cnt2++;
		}
		temp=temp->Next; //Смена адреса на адрес следующего элемента
		cnt++;
	}
	cout<<endl;
	if (cnt2==1)
		*kkk = false;
}

void sort(Node *start)
{
	Node *tmp;
    Node *a;
    int t=0;
    bool flag=1;
    while(flag==1)
    {
        tmp=start;
        a=tmp->Next;
        flag=0;
        while(a)
        {
            if((tmp->x)>(a->x))
            {
                t=tmp->x;
                tmp->x=a->x;
                a->x=t;
                flag=1;
            }
            tmp=tmp->Next;
            a=a->Next;
        }
    }
}

int List::del_often(bool*kkk)
{
	int del_elem, del;
	int max = 0;
	sort(Head);
	Node *temp=Head;
	int cnt = 0;
	if(Head == NULL)
		*kkk = false;
	del_elem = Head->x;
	temp=Head->Next; //Временно указываем на адрес первого элемента	
	while (temp!=NULL) //Пока не встретим пустое значение
	{
		if(temp->x==temp->Prev->x)
			cnt++;
		else
		{
			if(max < cnt)
			{
				max = cnt;
				del_elem = temp->Prev->x;				
			}		
			cnt = 0;
		}
		temp=temp->Next; //Смена адреса на адрес следующего элемента		
	}

	temp=Head; //Временно указываем на адрес первого элемента
	int n = 1;
	while (temp!=NULL) //Пока не встретим пустое значение
	{
		Node*t =temp->Next;
		if(temp->x==del_elem)
			del = Del_num(n,kkk);
		else
			n++;

		temp=t; //Смена адреса на адрес следующего элемента				
	}
	return del_elem;
};

void List::clear_not_lis2(List& lst2)
{
	Node* temp;
	bool qwe, ddd;
	bool kkk = true;
	if(Head==NULL) 
	{
		kkk = false;
		cout<<"Список 1 пуст\n";
	}
	if(lst2.size()-1<1)
	{
		kkk = false;
		cout<<"Список 2 пуст\n";
	}
	if (kkk)
	{
		int cnt = 1;
		temp = Head;
		while (temp!=NULL) //Пока не встретим пустое значение
		{
			qwe = true;
			lst2.Find(temp->x, &qwe);
			ddd = true;
			if (qwe)
			{							
				cnt++;
				temp = temp->Next;
			}
			else
			{
				int del = Del_num(cnt,&ddd);	
				temp = Head;
				for(int i=cnt;i>1;i--,temp=temp->Next);
			}
		}		
	}
}