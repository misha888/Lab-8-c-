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
    Node* head;    // ������ ������
    int count = 0; // ���������� ����� ������
    Node* Prev(Node*); // ������� � ����������� ���� (�� ������������ �����)
public:
    List() { head = nullptr; } // ������������� ������
    int getCount() { return count; } // ��������� ���������� ����� ������
    bool isEmpty() { return head == nullptr; }  // ��������, ���� �� ������
    int getValue(Node* p) { return p->field; } // ��������� �������� ���� ������
    void setValue(Node* p, int val) { p->field = val; } // ��������� �������� ���� ������
    Node* getFirst() { return head; } // ��������� ��������� ���� ������
    Node* getLast();      // ��������� ���������� ���� ������
    void Clear();        // ������� ������
    Node* Next(Node*);      // ������� � ���������� ����
    Node* push_back(int, Node* node=nullptr);    // ���������� ���� ������
    Node* remove(Node*);    // �������� ���� ������
    void  Print();
};

