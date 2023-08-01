#include <bits/stdc++.h>
#include "2105057_1_ll_queue.cpp"
// #include"2105057_1_a_queue.cpp"

using namespace std;
template <typename T>
class Stack
{
    Queue<T> q;

public:
    Stack()
    {
    }
    ~Stack()
    {
    }
    void push(T item)
    {
        int size = q.length();
        q.enqueue(item);
        for (int i = 0; i < size; i++)
        {
            q.enqueue(q.front());
            q.dequeue();
        }
    }

    void pop()
    {
        if (q.is_empty())
        {
            cout << "queue is empty" << endl;
        }
        else
        {
            q.dequeue();
        }
    }
    T top()
    {
        return q.front();
    }
    int size()
    {
        return q.length();
    }
    bool empty()
    {
        if (q.is_empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
