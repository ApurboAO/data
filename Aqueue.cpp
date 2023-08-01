#include <bits/stdc++.h>

using namespace std;

template <typename E>
class Queue
{
private:
    void operator=(const Queue &) {} // Protect assignment
    Queue(const Queue &) {}          // Protect copy constructor

public:
    Queue()
    {
    }
    virtual ~Queue()
    {
        clear();
    }

    virtual void enqueue(const E &it) = 0;
    virtual E dequeue() = 0;
    virtual void clear() = 0;
    virtual const E &frontValue() = 0;
    virtual const E &length() = 0;
};

template <typename E>
class AQueue : public Queue<E>
{
private:
    int maxsize;
    int front;
    int rear;
    E *listarray;

public:
    AQueue(int _maxsize = defaultSize)
    {
        maxsize = _maxsize + 1;
        front = 1;
        rear = 0;
        listarray = new E[maxsize];
    }
    ~AQueue()
    {
        delete[] listarray;
    }

    void clear()
    {
        rear = 0;
        front = 1;
    }

    void enqueue(const E &it)
    {
        rear = (rear + 1) % maxsize;
        listarray[rear] = it;
    }
    E dequeue()
    {
        E return_val = listarray[front];
        front = (front + 1) % maxsize;
        return return_val;
    }
    const E &frontValue()
    {
        return listarray[front];
    }
    virtual int length() const
    {
        return (rear + maxsize - front + 1) % maxsize;
    }
};
