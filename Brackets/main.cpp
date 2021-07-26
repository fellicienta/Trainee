#include "brackets.h"

#include <assert.h>

int main()
{
    assert(!checkBrackets("("));
    assert(!checkBrackets("{[}"));
    assert(!checkBrackets("foo(bar[i);"));
    assert(!checkBrackets("[]([]}"));
    assert(!checkBrackets("({[()]}"));

    assert(checkBrackets("()"));
    assert(checkBrackets("([])"));
    assert(checkBrackets("([{((({})))}])"));
    assert(checkBrackets("foo(bar);"));
    assert(checkBrackets("a"));
    return 0;
}
