#include<bits/stdc++.h>

using namespace std;

// Stack abtract class


template <typename E>
class Stack
{
private:
    // void operator=(const Stack &) {} // Protect assignment
    // Stack(const Stack &) {}          // Protect copy constructor
public:
    Stack() {}          // Default constructor
    virtual ~Stack() {} // Base destructor
    // Reinitialize the stack. The user is responsible for
    // reclaiming the storage used by the stack elements.
    virtual void clear() = 0;
    // Push an element onto the top of the stack.
    // it: The element being pushed onto the stack.
    virtual void push(const E &it) = 0;
    // Remove the element at the top of the stack.
    // Return: The element at the top of the stack.
    virtual E pop() = 0;
    // Return: A copy of the top element.
    virtual const E &topValue() const = 0;
    // Return: The number of elements in the stack.
    virtual int length() const = 0;
};

template <typename E>
class Link
{
public:
    E element;
    Link *next;

    Link(E elemValue, Link *_next = NULL)
    {
        element = elemValue;
        next = _next;
    }
    Link(Link * _next=NULL){
        next=_next;
    }
};

template <typename T>
class LStack : public Stack<T>
{
private:
    Link<T> *top;
    int size;

public:
    LStack()
    {
        top = NULL;
        size = 0;
    }
    ~LStack()
    {
        clear();
    }

    void clear()
    {
        while (top != NULL)
        {
            Link<T> *prev = top;
            top = top->next;
            delete prev;
        }
        size = 0;
    }

    void push(const T &it)
    {

        top = new Link<T>(it, top);
        size++;
    }

    T pop()
    {
        Link<T> *rtop = top;
        T top_ele = top->element;
        top = top->next;
        delete rtop;
        size--;
        return top_ele;
    }

    const T &topValue() const
    {
        return top->element;
    }
    int length() const
    {
        return size;
    }
};

long fact(int n, Stack<int> &S)
{ // Compute n!
    // To fit n! in a long variable, require n <= 12
    // Assert((n >= 0) && (n <= 12), "Input out of range");
    while (n > 1)
        S.push(n--); // Load up the stack
        
    long result = 1; // Holds final result
    while (S.length() > 0)
        result = result * S.pop(); // Compute
    return result;
}


int main() {
    cout<<"HI\n";
    LStack<int> obj;
    long int res = fact(6, obj);
    cout<<res<<endl;
}