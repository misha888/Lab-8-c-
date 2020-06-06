#pragma once
class Node
{
public:
    int field;
    class Node* ptr;
    friend class List;
};
class List
{
    Node* head;    // Корень списка
    int count = 0; // Количество узлов списка
    Node* Prev(Node*); // Переход к предыдущему узлу (не интерфейсный метод)
public:
    List() { head = nullptr; } // Инициализация списка
    int getCount() { return count; } // Получение количества узлов списка
    bool isEmpty() { return head == nullptr; }  // Проверка, пуст ли список
    int getValue(Node* p) { return p->field; } // Получение значения узла списка
    void setValue(Node* p, int val) { p->field = val; } // Установка значения узла списка
    Node* getFirst() { return head; } // Получение корневого узла списка
    Node* getLast();      // Получение последнего узла списка
    void Clear();        // Очистка списка
    Node* Next(Node*);      // Переход к следующему узлу
    Node* push_back(int, Node* node=nullptr);    // Добавление узла списка
    Node* remove(Node*);    // Удаление узла списка
    void  Print();
};

