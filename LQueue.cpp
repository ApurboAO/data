#include<bits/stdc++.h>

using namespace std;



template<typename E>
class Queue{
private:


public:

    Queue(){

    }
    virtual~ Queue(){
        clear();
    }

    virtual void enqueue(const E& it)=0;
    virtual E dequeue()=0;
    virtual void clear()=0;
    virtual const E& frontValue()=0;
    virtual const E& length()=0;


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
    Link(){

    }
};


template <typename E>
class  LQueue:public Queue<E>{
private:
    Link<E>* front;
    Link<E>* rear;
    int size;
public:
    LQueue(int _size=defaultSize){
        front=rear =new Link<E>();
        size=0;
    }
    ~LQueue(){
        clear();
        delete front;
    }
    void clear(){
        while(front->next!=NULL){
            rear=front ;
            delete rear;
            
        }
        size=0;
    }
    void enqueue(const E& it){
        rear->next=new Link<E>(it,rear->next);
        rear=rear->next;
        size++;
    }
    E dequeue(){
        E it=front->next->element;
        Link<E>* item=front->next;
        front->next=item->next;
        if(rear==item)rear=front;

        delete item;
        size--;
        return it;

    }
    const E& frontValue()const{
        return front->next->element;
    }
    virtual int length()const {
        return size;
    }
};













