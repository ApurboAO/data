#include <iostream>
#include"stack.cpp"

int main()
{
    int x, k;
    std::cin >> x >> k;
    Stack<int> newStack(x);

    for (int i = 0; i < k; i++)
    {
        int in;
        std::cin >> in;
        newStack.push(in);
    }

    int q, p;
    std::cin >> q;
    std::cin >> p;
    for (int i = 1; i < q; i++)
    {
        switch (i)
        {
        case 0:
            return 0;
            break;
        case 1:
            newStack.push(p);
            newStack.show_Stack();
            break;
        case 2:
            std::cout << "pop value :" << newStack.pop() << std::endl;
            newStack.show_Stack();
            break;
        case 3:
            std::cout << "stack length :" << newStack.length() << std::endl;
            break;
        case 4:
            std::cout << " isEmpty? :" << newStack.isEmpty() << std::endl;
            newStack.show_Stack();
            break;
        case 5:
            std::cout << "topvalue :" << newStack.topValue() << std::endl;
            break;
        case 6:
            newStack.clear();
            newStack.show_Stack();
            break;
        }
    }

    return 0;
}
/*
10
5
1
2
3
4
5
7
23


*/