#include <iostream>
#include <string>
#include <cmath>
#include "stack.cpp"

using namespace std;
#define cout std::cout

bool isOp(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
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
    if (ch == '*' || ch == '/')
    {
        return 2;
    }
    return 0;
}

double do_math(double a, double b, char c)
{
    switch (c)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    }
}

void calculate(string math)
{
    // if (math[0] != '(')
    // {
    //     math = "(" + math + ")";
    // }
    int len = math.length();
    Stack<double> opn(len);
    Stack<char> opr(len);
    Stack<char> paran(len);
    for (int i = 0; i < len; i++)
    {
        bool isUnary = false;
        if (math[i] == ' ')
        {
            continue;
        }

        if (math[i] == '(')
        {
            opr.push(math[i]);
            paran.push(math[i]);
        }

        else if (is_num(math[i]))
        {
            if (math[i - 1] == '-' && math[i - 2] == '(')
            {
                isUnary = true;
                opr.pop();
                // opr.pop();
            }
            int number = 0;
            while (i < len && is_num(math[i]))
            {
                number = number * 10 + (math[i] - '0');
                i++;
            }
            i--;
            if (isUnary)
            {
                // cout << "pushed number" << (-number) << endl;
                opn.push((-number));
            }
            else
            {
                opn.push(number);
            }
        }

        else if (math[i] == ')')
        {
            if (paran.topValue() != '(')
            {
                cout << "Not Valid!" << endl;
                return;
            }
            else
            {
                paran.pop();
            }

            while (!opr.isEmpty() && opr.topValue() != '(')
            {

                double val1 = opn.pop();
                double val2 = opn.pop();
                char ch = opr.pop();
                opn.push(do_math(val2, val1, ch));
            }
            if (!opr.isEmpty() && opr.topValue() == '(')
            {
                opr.pop();
            }
        }
        else
        {
            // opr.show_Stack();
            if (isUnary && math[i] == ')')
            {
                opr.pop();
                opr.pop();
                isUnary = false;
            }

            if (!opr.isEmpty() && isOp(math[i - 1]))
            {
                cout << "Not Valid!" << endl;
                return;
            }

            while (!opr.isEmpty() && precedence(opr.topValue()) >= precedence(math[i]))
            {
                double val_1 = opn.pop();
                double val_2 = opn.pop();
                char sign = opr.pop();
                opn.push(do_math(val_2, val_1, sign));
                // cout << do_math(val_1, val_2, sign);
            }
            opr.push(math[i]);
        }
    }
    // opn.show_Stack();
    // opr.show_Stack();
    // paran.show_Stack();
    // cout << opn.topValue() << endl;
    while (!opr.isEmpty())
    {
        double val1 = opn.pop();
        double val2 = opn.pop();
        char ch = opr.pop();
        opn.push(do_math(val2, val1, ch));
    }
    if (!paran.isEmpty())
    {
        cout << "Not Valid!" << endl;
        return;
    }
    cout << "Valid expression" << endl;
    cout << "Computed value: " << opn.topValue() << endl;
}

int main()
{
    string expression;
    cout << "Enter an arithmetic expression: ";
    getline(std::cin, expression);
    calculate(expression);

    return 0;
}
/*
(9*3-(7*8+((-4)/2)))
(9*3-(7*8+((4/2)))
6/3*2
2+4/5*10/3
2++4
*/