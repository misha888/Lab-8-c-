#include"Stdafx.h"


///+-+-+-+-+-++-+-+-+-+-++-+-+-+-+-++-+-+-+-+-++-+-+-+-+-++-+-+-+-+-+ Variant 2 +-+-+-+-+-++-+-+-+-+-++-+-+-+-+-++-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+-
using namespace std;
struct List
{	///<линейный однонаправленный>
	int x;
	List* Next;
};	///<\линейный однонаправленный>



void BaseLevelTask()
{

	cout << "\nBase level task: \n";
	/*
	Создать линейный однонаправленный список из целых чисел. Определить сумму значений элементов списка, кратных 5.
	*/
	List* Begin = nullptr;
	char Key;
	bool flag = false;
	while (TRUE)
	{
	//	do {
			printf("\nEnter the number - the mode of "
				"operations with Lists: "
				"\n		1 - FORMATION OF THE LIST"
				"\n		2 - VIEWING OF CONTENTS OF THE LIST"
				"\n		3 - Remove the element from the begin of List"
				"\n		4 - Remove the element from the midle of list"
				"\n		5 - Remove the element from the end of List"
				"\n		6 - ADD THE ELEMENT IN THE BEGIN OF LIST"
				"\n		7 - ADD THE ELEMENT IN THE END OF LIST"
				"\n		8 - ADD THE ELEMENT AFTER ELEMENT-KEY OF LIST"
				"\n		9 - Search sum element list % 5"
				"\n		10 - END OF WORK\n"
			);
			//fflush(stdin);
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> Key;
			cin.ignore(cin.rdbuf()->in_avail());
			system("cls");
			/*if (Key != '1')
			{
				(Key == '1') ? flag = true : flag = false;

				cout << "\nСписок еще не создан, перед тем как выполнять какие либо операци "
					"над списком выберите команду '1'\n";
			}*/

		//} while (!flag);
		switch (Key)
		{
		case '1':
			system("cls");
			Begin = CreateList();
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '2':
			system("cls");
			DisplayList(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '3':
			system("cls");
			//RemoveTermBegin(&Begin);
			Begin = deletehead(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '4':
			system("cls");
			RemoveTermTag(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '5':
			system("cls");
			RemoveTermEnd(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '6':
			system("cls");
			AddTermBegin(&Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '7':
			system("cls");
			AddTermEnd(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '8':
			system("cls");
			AddTermTag(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			break;
		case '9':
			system("cls");
			WorkFunc(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();	
			break;

		case '10':
			system("cls");
			FreeList(&Begin);
			//DisplayList(Begin);
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			return ;
		default:
			system("cls");
			cout << "\nIncorrect input!!! Try again!!!\n";
			cout << "\n\nPress any key to return in the menu...\n";
			getchar();
			system("cls");
			if (Begin != nullptr)
				FreeList(&Begin);
			break;
		}
	}

}
///
struct node {
	node* prev;
	node* next;
	double   val;
	node(double v) :prev(nullptr), next(nullptr), val(v) {}
};

typedef struct {
	node* head, * tail;
} list_t;

void  list_init(list_t* lst) { lst->head = lst->tail = nullptr; }
void  list_copy(list_t* lst, const int* a, double n);
node* list_erase(list_t* lst, node* pos);
node* list_insert_before(list_t* lst, node* pos, double val);
void  list_clear(list_t* lst);



//копирование массива
void list_copy(list_t* lst, const double* a, double n) {
	node* p;
	list_init(lst);
	for (int i = 0; i < n; ++i) {
		p = new node(a[i]);

		if (lst->head == nullptr)
			lst->head = lst->tail = p;
		else {
			p->prev = lst->tail;
			lst->tail->next = p;
			lst->tail = p;
		}
	}
}

//удаление
node* list_erase(list_t* lst, node* pos) {
	node* p = pos->next;
	if (pos == lst->head) {
		lst->head = lst->head->next;
		if (lst->head == nullptr)
			lst->tail = nullptr;
		else
			lst->head->prev = nullptr;
	}
	else if (pos == lst->tail) {
		lst->tail = lst->tail->prev;
		lst->tail->next = nullptr;
	}
	else {
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
	}
	delete pos;
	return p;
}

//вставка перед pos
node* list_insert_before(list_t* lst, node* pos, double val) {
	node* p = new node(val);
	if (pos == lst->head) {
		lst->head->prev = p;
		p->next = lst->head;
		lst->head = p;
	}
	else {
		p->next = pos;
		p->prev = pos->prev;

		pos->prev->next = p;
		pos->prev = p;
	}
	return pos;
}

//удаление всех
void list_clear(list_t* lst) {
	node* t;
	while (lst->head != nullptr) {
		t = lst->head;
		lst->head = lst->head->next;
		delete t;
	}
	lst->tail = nullptr;
}
///
void MidleLevelTask() ///DLL  Doubly linked  list
{
	cout << "\Midle level task: \n";
//Создать линейный двунаправленный список из вещественных чисел. Удалить из списка элемент после каждого элемента с отрицательным значением
	list_t lst;
	double a[] = { 4.0, -4.0, 1.0, -1.1, 1.2, 1.5, 4.3, 7.3, 4.3, -8.5, 4.4, 9.4, 1.3, -15, 4.6, -9.11 };
	list_init(&lst);
	list_copy(&lst, a, (sizeof(a) / sizeof(a[0])));
	for (const node* x = lst.head; x != nullptr; x = x->next)
		std::cout << x->val << ' ';
	std::cout << std::endl<<endl;

	/*for (const node* y = lst.tail; y != nullptr; y = y->prev)
		std::cout << y->val << ' ';
	std::cout << std::endl;*/
	//Удалить из списка элемент после каждого отрицательного элемента, 
	node* p = lst.head;
	while (p != nullptr) {
		if ((p->val < 0) && (p->next != nullptr))
			p = list_erase(&lst, p->next);
		else
			p = p->next;
	}

	//Вставить число 0 перед каждым числом 1
	/*for (p = lst.head; p != NULL; p = p->next) {
		if (p->val == 1)
			p = list_insert_before(&lst, p, 0);
	}*/

	//вывод
	for (const node* x = lst.head; x != nullptr; x = x->next)
		std::cout << x->val << ' ';
	std::cout << std::endl;

	/*for (const node* y = lst.tail; y != nullptr; y = y->prev)
		std::cout << y->val << ' ';
	std::cout << std::endl;*/

	list_clear(&lst);
}
void HardLevelTask()///Using Двусвязный циклический список(DLCL(Doubly linked circular list))
{
	cout << "\Hard level task: \n";
	/*
	Создать циклический двунаправленный список из целых чисел. Удалить из списка первый элемент со значением 10
	*/
	list* lst =nullptr;
	cout << "Intput count elements for Doubly linked circular list $ ";
	int countelem = 0;
	cin >> countelem;
	//cin.ignore(cin.rdbuf()->in_avail());

	/*while (cin >> countelem)
	{
		if (!cin.fail() && countelem > 0)
			break;
		else
		{
			cin.ignore(32222, '\n');
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
		}
	}*/
	bool flag = true;
	for (size_t i = 0; i < countelem-1; i++)
	{
		if (flag)
		{
			flag = false;
			lst = init(rand() % 20);
		}
		lst = addelem(lst,(rand() % 20));
	}
	cout << "\nList integer digit: \n";
	listprint(lst);
		list* p;
		p = lst;
		flag = false;
		do {
			//printf("%d ", p->field); // вывод значения элемента p
			if (p->field == 10 && !flag)
			{
				flag = true;
				p = deletelem(p);
				
			}
			p = p->next; // переход к следующему узлу
		} while (p != lst); // условие окончания обхода
		lst = p;
		flag ? cout << "\nСписок после удаления первого элемента значения которого 10\n" :cout<<"\nВ списске не найдено ни одного элемента удовлетворяющего условие!\n";
		listprint(lst);
}


int main(int argc, char** argv)
{
	srand(time(0));
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(0, "");
	//BaseLevelTask();
		MidleLevelTask();
	//HardLevelTask();
}

int WorkFunc(List* Begin)
{
	List* Current = Begin;
	int Sum = 0;
	if (Begin == nullptr)
	{
		cout << "List is empty\n";
		return -1;
	}
	//cout << "\nThe List of numbers: \n";
	while (Current)
	{
		//printf("%d", Current->x);
		if (Current->x % 5 == 0)
			Sum += Current->x;
		Current = Current->Next;
	}
	cout << "\nThe sum elements of list % 5 -> " << Sum << endl;

	return 0;
}
List* CreateList(void)
{
	List* Begin = nullptr, * Previos/*предыдущий*/ = nullptr,
		* Current = nullptr;
	char ok = 'y';

	while (ok == 'y')
	{
		cout << "\nEnter the numbers of List: ";
		Current = (List*)malloc(sizeof(List));

		if (Begin == nullptr)
			Begin = Current;
		else
			Previos->Next = Current;

		Previos = Current;
		scanf("%d", &Current->x);
		fflush(stdin);
		printf("\nContinue? (Y / N): ");
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> ok;
	}
	Previos->Next = nullptr;
	return Begin;
}


void DisplayList(List* Begin)
{
	List* Current = Begin;

	if (Begin == nullptr)
	{
		cout << "List is empty\n";
		return;
	}
	cout << "\nThe List of numbers: \n";
	while (Current)
	{
		printf("%d ", Current->x);
		Current = Current->Next;
	}
	cout << endl;
}
List* deletehead(List* root)
{
	struct List* temp;
	temp = root->Next;
	free(root); // освобождение памяти текущего корня
	return(temp); // новый корень списка
}
/*void RemoveTermBegin(List** Begin)
{
	List** Current = Begin;
	*Begin = (*Current)->Next;
	free(Current);
}*/

void RemoveTermTag(List* Begin)
{
	List* Current = Begin, * Previos = Current;
	int NumberTag;
	cout << "\nEnter number-key: ";
	scanf("%d", &NumberTag);

	while (Current)
	{
		if (Current->x == NumberTag)
		{
			Previos->Next = Current->Next;
			free(Current);
			Current = Previos->Next;
		}
		else
		{
			Previos = Current;
			Current = Current->Next;
		}
	}
}

void RemoveTermEnd(List* Begin)
{
	List* Current = Begin, * Previos = nullptr;

	while (Current->Next)
	{
		Previos = Current;
		Current = Current->Next;
	}

	Previos->Next = NULL;
	free(Current);
}

void AddTermBegin(List** Begin)
{
	List* Current = (List*)malloc(sizeof(List));
	cout << "\nEnter number: ";
	scanf("%d", &Current->x);

	Current->Next = *Begin;
	*Begin = Current;
}


void AddTermEnd(List* Begin)
{
	List* Current = Begin, * Previos = nullptr;

	while (Current)
	{
		Previos = Current;
		Current = Current->Next;
	}

	Current = (List*)malloc(sizeof(List));
	Previos->Next = Current;

	cout << "\nEnter the number: \n";
	scanf("%d", &Current->x);
	Current->Next = nullptr;
}

void AddTermTag(List* Begin)
{
	List* Current = Begin, * Previos = Current;
	int NumberTag;

	cout << "\nEnter number-tag: ";
	cin >> NumberTag;

	while (Current)
	{

		if (Current->x == NumberTag)
		{
			Previos = Current;
			Current = (List*)malloc(sizeof(List));
			Current->Next = Previos->Next;
			Previos->Next = Current;
			cout << "\nEnter the number: \n";
			cin >> Current->x;
			break;
		}
		else
		{
			Previos = Current;
			Current = Current->Next;
		}
	}
}

void FreeList(List** Begin)
{
	List* Current = *Begin;

	while (Current)
	{
		*Begin = (*Begin)->Next;
		free(Current);
		Current = *Begin;
	}
}