#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool Posled(const string& brackets) {
    stack<char> stack;

    for (const auto& bracket : brackets) {
        if (bracket == '(' || bracket == '[' || bracket == '{') {
            stack.push(bracket);
        } else {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            stack.pop();

            if ((bracket == ')' && top != '(') || (bracket == ']' && top != '[') || (bracket == '}' && top != '{')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    string example = "(()([[]{})]{})";

    if (Posled(example)) {
        cout << "Последовательность правильная";
    } else {
        cout << "Последовательность неверна";
    }

    return 0;
}