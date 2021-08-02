#ifndef LISTITERATOR_H
#define LISTITERATOR_H

#include "iterator.h"
#include "list.h"

template <typename X>
class ListIterator : public Iterator<X>
{
public:
    template <typename T>
    ListIterator(const List<T> *list);
    void first() override;
    void next() override;
    bool isDone() const override;
    T currentItem() const override;

private:
    const List<T> *m_list;
    long m_current;
};

template <typename T>
ListIterator<T>::ListIterator(const List<T> *list) : m_list(list), m_current(0) {}

template <typename T>
void ListIterator<T>::first()
{
    m_current = 0;
}

template <typename T>
void ListIterator<T>::next()
{
    ++m_current;
}

template <typename T>
bool ListIterator<T>::isDone() const
{
    return m_current >= m_list->size();
}

template <typename T>
T ListIterator<T>::currentItem() const
{
    if (isDone())
        throw "IteratorOutOfBounds";

 //   return m_list.;
}

//template <typename T>
//class ListIteratorPtr : public IteratorPtr<T>
//{
//public:
//    ListIteratorPtr<T>& operator=(typename List<T>::template Node<T> *node) override;
//    ListIteratorPtr<T>& operator++() override;
//    ListIteratorPtr<T>& operator++(T) override;
//    ListIteratorPtr<T>& operator--() override;
//    ListIteratorPtr<T>& operator--(T) override;
//    bool operator!=(ListIteratorPtr<T>&) const override;
//    T& operator*();

//private:
//    const List<T> *m_list;
//    typename List<T>::template Node<T> *m_currentNode;
//};

template <typename T>
class ListIteratorPtr
{
public:
    ListIteratorPtr<T>& operator=(typename List<T>::template Node<T> *node) ;
    ListIteratorPtr<T>& operator++() ;
    ListIteratorPtr<T>& operator++(T) ;
    ListIteratorPtr<T>& operator--() ;
    ListIteratorPtr<T>& operator--(T) ;
    bool operator!=(ListIteratorPtr<T>&) const ;
    T& operator*();

private:
    const typename List<T>::template Node<T> *m_currentNode;
};


template <typename T>
ListIteratorPtr<T>& ListIteratorPtr<T>::operator=(typename List<T>::template Node<T> *node)
{
    m_currentNode = node;
    return *this;
}

template <typename T>
ListIteratorPtr<T>& ListIteratorPtr<T>::operator++()
{
    if (m_currentNode)
        m_currentNode = m_currentNode->next;
    return *this;
}

template <typename T>
ListIteratorPtr<T>& ListIteratorPtr<T>::operator++(T)
{
    ListIteratorPtr it = *this;
    ++(*this);
    return *it;
}

template <typename T>
bool ListIteratorPtr<T>::operator!=(ListIteratorPtr<T>& it) const
{
    return m_currentNode != it.m_currentNode;
}

template <typename T>
T& ListIteratorPtr<T>::operator*()
{
    return m_currentNode->data;
}
#endif // LISTITERATOR_H
