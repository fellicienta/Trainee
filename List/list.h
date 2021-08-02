#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "listiterator.h"

template<typename T>
class ListIterator;

template<typename T>
class ListIteratorPtr;

template<typename T>
class List
{
    friend class ListIterator<T>;
    friend class ListIteratorPtr<T>;
    template<typename X>
    friend std::ostream& operator<<(std::ostream& out, const List<X>& list);

public:
    ListIterator<T> createIterator();
    ListIteratorPtr<T> begin();
    ListIteratorPtr<T> end();
    List() : m_head(nullptr), m_tail(nullptr), m_size(0) {}
    ~List() {}
    bool empty() const;
    void pushFront(const T &data);
    void pushBack(const T &data);
    void popFront();
    void popBack();
    void clear();
    int32_t size() const;
    T& front();
    T& back();

private:
    template<typename N>
    class Node
    {
    public:
        Node(N data, Node *next, Node *previous) : data(data), next(next), previous(previous) {}
        ~Node() {}

        N data;
        Node *next;
        Node *previous;
    };

    Node<T> *m_head;
    Node<T> *m_tail;
    int32_t m_size;
};

template<typename T>
ListIterator<T> List<T>::createIterator()
{
    return ListIterator<T>(m_head);
}

template<typename T>
ListIteratorPtr<T> List<T>::begin()
{
    return ListIteratorPtr<T>(m_head);
}

template<typename T>
ListIteratorPtr<T> List<T>::end()
{
    return ListIteratorPtr<T>(nullptr);
}

template<typename T>
bool List<T>::empty() const
{
    return m_head == nullptr ? true : false;
}

template<typename T>
void List<T>::pushFront(const T &data)
{
    if (empty())
    {
        m_head = new Node<T>(data, nullptr, nullptr);
        m_tail = m_head;
    }
    else
    {
        Node<T> *tmp = new Node<T>(data, m_head, nullptr);
        m_head->previous = tmp;
        m_head = tmp;
    }
    ++m_size;
}

template<typename T>
void List<T>::pushBack(const T &data)
{
    if (empty())
    {
        m_head = new Node<T>(data, nullptr, nullptr);
        m_tail = m_head;
    }
    else
    {
        Node<T> *tmp = new Node<T>(data, nullptr, m_tail);
        m_tail->next = tmp;
        m_tail = tmp;
    }
    ++m_size;
}

template<typename T>
void List<T>::popFront()
{
    if (empty())
        return;

    Node<T> *tmp = m_tail;

    if (m_tail != m_head)
    {
        m_tail = m_tail->previous;
        m_tail->next = nullptr;
    }
    else
    {
        m_head = m_tail = nullptr;
    }
    delete tmp;
}

template<typename T>
void List<T>::popBack()
{
    if (empty())
        return;

    Node<T> *tmp = m_head;

    if (m_tail != m_head)
    {
        m_head = m_head->next;
        m_head->previous = nullptr;
    }
    else
    {
        m_head = m_tail = nullptr;
    }
    delete tmp;
}

template<typename T>
void List<T>::clear()
{
    if (empty())
        return;

    Node<T> *tmp = m_head;

    while (tmp->next != nullptr)
    {
        tmp = tmp->next;
        delete tmp->previous;
    }

    m_head = m_tail = nullptr;
    delete tmp;
}

template<typename T>
int32_t List<T>::size() const
{
    return m_size;
}

template<typename T>
T& List<T>::front()
{
    return m_head->data;
}

template<typename T>
T&List<T>:: back()
{
    return m_tail->data;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const List<T>& list)
{
    typename List<T>::template Node<T> *current = list.m_head;

    while (current != nullptr)
    {
       out << current->data << " --> ";
       current = current->next;
    }

    out << std::endl;

    return out;
}

#endif // LIST_H
