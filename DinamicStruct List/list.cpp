#pragma once
#include "list.h"
#include <iostream>
Node* List::push_back(int num, Node* node )
{
    Node* elem = new Node();
    elem->field = num;
    count++;
    if (node == nullptr) // ���������� ������ �����
    {
        if (head == nullptr) {
            elem->ptr = nullptr;
            head = elem;
        }
        else {
            elem->ptr = head;
            head = elem;
        }
        return elem;
    }
    elem->ptr = node->ptr; // ���������� ���� ����� ��������
    node->ptr = elem;
    return elem;
}
Node* List::remove(Node* node)
{
    if (node == nullptr) { return nullptr; } // � ������ ��� �����
    count--;
    if (node == head)  // �������� ��������� ����
    {
        head = node->ptr;
        delete node;
        return head;
    }
    Node* prev = Prev(node); // �������� �������������� ����
    prev->ptr = node->ptr;
    delete node;
    return prev;
}
Node* List::Next(Node* node)
{
    if (isEmpty()) return nullptr;
    return node->ptr;
}
Node* List::Prev(Node* node)
{
    if (isEmpty()) return nullptr;
    if (node == head) return nullptr;
    Node* p = head;
    while (p->ptr != node)
        p = p->ptr;
    return p;
}
Node* List::getLast()
{
    Node* p = head;
    while (Next(p) != nullptr)
        p = Next(p);
    return p;
}
void  List::Clear()
{
    class Node* p = head;
    if (p == nullptr) return;
    do {
        Node* d = p;
        p = Next(p);
        delete d;
    } while (p != nullptr);
    count = 0;
    head = nullptr;
}
void  List::Print()
{
    if (isEmpty()) { std::cout << "������ ����" << std::endl; return; }
    Node* p = head;
    do {
        std::cout << getValue(p) << " ";
        p = Next(p);
    } while (p != nullptr);
    std::cout << std::endl;
}
