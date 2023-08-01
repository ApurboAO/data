#include <bits/stdc++.h>
#include "2105057_2_stack.cpp"
using namespace std;
int main() {
    Stack<int> stack;

    std::string input;
    while (getline(std::cin, input)) {
        int Q, P;
        sscanf(input.c_str(), "%d %d", &Q, &P);

        if (Q == 0) {
            break;
        }

        switch (Q) {
            case 1:
                stack.push(P);
                break;
            case 2:
                if (stack.empty()) {
                    cout<< "Error: Stack is empty!" << endl;
                } else {
                    stack.pop();
                }
                break;
            case 3:
                cout<< stack.size() << endl;
                break;
            case 4:
                if (stack.empty()) {
                    cout<< "Error: Stack is empty!" << endl;
                } else {
                    cout<< stack.top() << endl;
                }
                break;
            case 5:
                cout<< stack.top() << endl;
                break;
            case 6:
                cout<< (stack.empty() ? "True" : "False") << endl;
                break;
            default:
                cout<< "Invalid option!" << endl;
                break;
        }


    }

    return 0;
}

