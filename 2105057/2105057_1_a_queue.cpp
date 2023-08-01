#include <iostream>
#include "2105057_1_a_queue.h"

using namespace std;

template <typename T>
class Queue
{
private:
    List<T> myque;

public:
    void enqueue(T item)
    {
        myque.insert(item);
    }

    T dequeue()
    {
        return myque.dequeue();
    }

    int length()
    {
        return myque.length();
    }

    T front()
    {
        return myque.front();
    }

    T back()
    {
        return myque.back();
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
    int total_siz()
    {
        return myque.total_s();
    }
    int end()
    {
        return myque.rear();
    }
    int str()
    {
        return myque.root();
    }
};
