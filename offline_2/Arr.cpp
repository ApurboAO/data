#include <iostream>
#include <string>
#include "stack.cpp"

using namespace std;

bool is_num(char ch)
{
    return ch >= '0' && ch <= '9';
}

int precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    return 0;
}

int do_math(int a, int b, char c)
{
    switch (c)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
    return 0;
}

void evaluate(const string &math)
{
    int len = math.length();
    Stack<int> opn(len);
    Stack<char> opr(len);
    for (int i = 0; i < len; i++)
    {
        if(math[i]==' '){
            continue;
        }
        if (math[i] == '(')
        {
            opr.push(math[i]);
        }

        else if (is_num(math[i]))
        {
            int number = 0;
            while (i < len && is_num(math[i]))
            {
                number = number * 10 + (math[i] - '0');
                i++;
            }
            opn.push(number);
            i--;
        }
        else if (math[i] == ')')
        {
            while (!opr.isEmpty() && opr.topValue() != '(')
            {
                int val1 = opn.pop();
                int val2 = opn.pop();
                char ch = opr.pop();
                opn.push(do_math(val2, val1, ch));
            }
            if (!opr.isEmpty() && opr.topValue() == '(')
            {
                opr.pop(); // Pop the opening parenthesis
            }
        }
        else
        {
            while (!opr.isEmpty() && precedence(opr.topValue()) >= precedence(math[i]))
            {
                int val1 = opn.pop();
                int val2 = opn.pop();
                char ch = opr.pop();
                opn.push(do_math(val2, val1, ch));
            }
            opr.push(math[i]);
        }
    }

    while (!opr.isEmpty())
    {
        int val1 = opn.pop();
        int val2 = opn.pop();
        char ch = opr.pop();
        opn.push(do_math(val2, val1, ch));
    }

    cout << "Computed value: " << opn.topValue() << endl;
}

int main()
{
    string expression;
    cout << "Enter an arithmetic expression: ";
    getline(cin, expression);

    evaluate(expression);

    return 0;
}

/*
(2*(3+2))
*/