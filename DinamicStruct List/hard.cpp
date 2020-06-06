#include "main.h"
using namespace std;
/*
Дано число K (> 0) и указатели P1 и P2 на первый и последний элементы непустого двусвязного списка.
Осуществить циклический сдвиг элементов списка на K позиций вперед (то есть в направлении от начала 
к концу списка) и вывести указатели на первый и последний элементы полученного списка. Для 
выполнения циклического сдвига преобразовать исходный список в циклический, после чего «разорвать»
его в позиции, соответствующей данному значению K. Операции выделения и освобождения памяти не 
использовать
*/
struct list
{
  int field; // поле данных
  struct list *next; // указатель на следующий элемент
  struct list *prev; // указатель на предыдущий элемент
};
struct list * init(int a)  // а- значение первого узла
{
  struct list *lst;
  // выделение памяти под корень списка
  lst = (struct list*)malloc(sizeof(struct list));
  lst->field = a;
  lst->next = NULL; // указатель на следующий узел
  lst->prev = NULL; // указатель на предыдущий узел
  return(lst);
}
struct list * addelem(list *lst, int number)
{
  struct list *temp, *p;
  temp = (struct list*)malloc(sizeof(list));
  p = lst->next; // сохранение указателя на следующий узел
  lst->next = temp; // предыдущий узел указывает на создаваемый
  temp->field = number; // сохранение поля данных добавляемого узла
  temp->next = p; // созданный узел указывает на следующий узел
  temp->prev = lst; // созданный узел указывает на предыдущий узел
  if (p != NULL)
    p->prev = temp;
  return(temp);
}
struct list * deletelem(list *lst)
{
  struct list *prev, *next;
  prev = lst->prev; // узел, предшествующий lst
  next = lst->next; // узел, следующий за lst
  if (prev != NULL)
    prev->next = lst->next; // переставляем указатель
  if (next != NULL)
    next->prev = lst->prev; // переставляем указатель
  free(lst); // освобождаем память удаляемого элемента
  return(prev);
}
struct list * deletehead(list *root)
{
  struct list *temp;
  temp = root->next;
  temp->prev = NULL;
  free(root);   // освобождение памяти текущего корня
  return(temp); // новый корень списка
}
void listprint(list *lst)
{
  struct list *p;
  p = lst;
  do {
    printf("%d ", p->field); // вывод значения элемента p
    p = p->next; // переход к следующему узлу
  } while (p != NULL); // условие окончания обхода
}
void hard()
{
	system("cls");
	cout << "\nHard tasklevel: \n";
struct list *prev1, *prev2, *next1, *next2;
  prev1 = lst1->prev;  // узел предшествующий lst1
  prev2 = lst2->prev;  // узел предшествующий lst2
  next1 = lst1->next; // узел следующий за lst1
  next2 = lst2->next; // узел следующий за lst2
  if (lst2 == next1)  // обмениваются соседние узлы
  {
    lst2->next = lst1;
    lst2->prev = prev1;
    lst1->next = next2;
    lst1->prev = lst2;
    if(next2 != NULL)
      next2->prev = lst1;
    if (lst1 != head)
      prev1->next = lst2;
  }
  else if (lst1 == next2)  // обмениваются соседние узлы
  {
    lst1->next = lst2;
    lst1->prev = prev2;
    lst2->next = next1;
    lst2->prev = lst1;
    if(next1 != NULL)
      next1->prev = lst2;
    if (lst2 != head)
      prev2->next = lst1;
  }
  else  // обмениваются отстоящие узлы
  {
    if (lst1 != head)  // указатель prev можно установить только для элемента,
      prev1->next = lst2; // не являющегося корневым
    lst2->next = next1;
    if (lst2 != head)
      prev2->next = lst1;
    lst1->next = next2;
    lst2->prev = prev1;
    if (next2 != NULL) // указатель next можно установить только для элемента,
      next2->prev = lst1; // не являющегося последним
    lst1->prev = prev2;
    if (next1 != NULL)
      next1->prev = lst2;
  }
  if (lst1 == head)
    return(lst2);
  if (lst2 == head)
    return(lst1);
	cout << "\nPress Enter to exit...\n";
	while (getchar() != '\n')
		continue;
}
