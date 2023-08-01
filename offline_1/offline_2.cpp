#include <iostream>
#include <stack>
#include <string>
#include <sstream>

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

bool isValidExpression(const std::string& expression) {
    std::stack<char> bracketsStack;

    for (char ch : expression) {
        if (ch == '(') {
            bracketsStack.push(ch);
        } else if (ch == ')') {
            if (bracketsStack.empty() || bracketsStack.top() != '(') {
                return false;  // Mismatched or unexpected closing bracket
            }
            bracketsStack.pop();
        }
    }

    return bracketsStack.empty();
}

bool hasValidOperators(const std::string& expression) {
    std::string validChars = "0123456789.+-*/()";
    for (char ch : expression) {
        if (validChars.find(ch) == std::string::npos) {
            return false;  // Invalid character found
        }
    }
    return true;
}

int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0;
    }
}

int evaluateExpression(const std::string& expression) {
    std::stack<int> operandStack;

    std::istringstream iss(expression);
    std::string token;
    while (std::getline(iss, token, ' ')) {
        if (isOperator(token[0])) {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            int result = performOperation(token[0], operand1, operand2);
            operandStack.push(result);
        } else {
            int operand;
            std::istringstream(token) >> operand;
            operandStack.push(operand);
        }
    }

    return operandStack.top();
}

int main() {
    std::string expression = "2-3*4+32/2";

    if (!isValidExpression(expression)) {
        std::cout << "The expression is not valid." << std::endl;
        return 0;
    }

    if (!hasValidOperators(expression)) {
        std::cout << "The expression contains invalid characters." << std::endl;
        return 0;
    }

    int result = evaluateExpression(expression);

    std::cout << "Expression: " << expression << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}
