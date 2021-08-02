#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"

template <typename T>
class Iterator
{
public:
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() const = 0;
    virtual T currentItem() const = 0;

protected:
    Iterator();
};

//template <typename T>
//class IteratorPtr
//{
//public:
//    virtual IteratorPtr<T>& operator++() = 0;
//    virtual IteratorPtr<T>& operator++(T) const = 0;
//    virtual IteratorPtr<T>& operator--() const = 0;
//    virtual IteratorPtr<T>& operator--(T) const = 0;
//    virtual IteratorPtr<T>& operator=(typename List<T>::template Node<T> *node) = 0;
//    virtual bool operator!=(IteratorPtr<T>&);
//    T& operator*();

//protected:
//    IteratorPtr();
//};

#endif // ITERATOR_H
