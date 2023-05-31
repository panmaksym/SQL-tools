
#ifndef SQL_TOOLS_CHECKSYNTAX_H
#define SQL_TOOLS_CHECKSYNTAX_H
#include <stack>;
#include <string>

bool isSQLArrayValid(const std::string& sqlArray) {
    std::stack<char> stack;
    for (char c : sqlArray) {
        if (c == '(') {
            stack.push(c);
        } else if (c == ')') {
            if (stack.empty() || stack.top() != '(') {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}
#endif //SQL_TOOLS_CHECKSYNTAX_H
