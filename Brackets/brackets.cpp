#include "brackets.h"

#include <map>
#include <algorithm>
#include <stack>
#include <cstring>

std::map<char, char> BRACKETS = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

namespace  {
bool isPunct(const char c)
{
    return ispunct(c) &&
            !(std::any_of(BRACKETS.begin(), BRACKETS.end(), [&](const std::pair<char, char> &p){ return c == p.first || c == p.second;}));
}
bool isText(const char c)
{
    return isalpha(c) || isdigit(c) || isPunct(c);
}
bool isOpenBracket(const char c)
{
    return std::any_of(BRACKETS.begin(), BRACKETS.end(), [&](const std::pair<char, char> &p){ return c == p.first;});
}
bool isCloseBracket(const char c)
{
    return std::any_of(BRACKETS.begin(), BRACKETS.end(), [&](const std::pair<char, char> &p){ return c == p.second;});
}
bool isPair(const char c1, const char c2)
{
    return BRACKETS[c1] == c2;
}
}

bool checkBrackets(const char inputString[])
{
    std::stack<char> st;

    for (size_t c = 0; c < strlen(inputString); ++c)
    {
        if(isCloseBracket(inputString[c]) && st.empty())
            return false;
        else if (isText(inputString[c]))
            continue;
        else if (isOpenBracket(inputString[c]))
            st.push(inputString[c]);
        else if(isCloseBracket(inputString[c]) && isPair(st.top(), inputString[c]))
            st.pop();
    }

    return st.empty();
}
