#include "list.h"

#include <assert.h>

int main()
{
// *** Create list ***
    List<int> list;
    assert(list.empty());
    assert(list.size() == 0);

// *** Push front and check ***
    list.pushFront(1);
    assert(list.front() == 1);
    assert(list.back() == 1);

    list.pushFront(2);
    assert(list.front() == 2);
    assert(list.back() == 1);
    assert(!list.empty());

// *** Push back and check ***
    list.pushBack(3);
    assert(list.back() == 3);
    assert(list.size() == 3);

// *** Print list ***
    std::cout << list;
    list.popBack();
    std::cout << list;
    list.popFront();
    list.clear();
    std::cout << list;


    return 0;
}

