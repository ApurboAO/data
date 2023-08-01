#include <bits/stdc++.h>
#include "2105057_1_ll_queue.h"



using namespace std;

template <typename T>
class Queue
{
private:
    List<T> myque;

public:
    Queue()
    {
    }
    ~Queue()
    {
        cout<<"memory cleared"<<endl;
        clear();
    }
    void enqueue(T item)
    {
        myque.moveToEnd();
        myque.insert(item);
    }
    T dequeue()
    {
        myque.moveToStart();
        T front_val = front();
        myque.remove();
        return front_val;
    }
    int length()
    {
        return myque.length();
    }
    T front()
    {
        myque.moveToStart();
        return myque.getValue();
    }
    T back()
    {
        myque.moveToEnd();
        return myque.getValue();
    }
    bool is_empty()
    {
        return myque.is_empty();
    }
    void clear()
    {
        myque.clear();
    }
    void show_queue()
    {
        myque.show();
    }
};
