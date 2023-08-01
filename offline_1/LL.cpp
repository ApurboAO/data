#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int item;
    node *next;
    node(int _item, node *_next = nullptr)
    {
        item = _item;
        next = _next;
    }
    node()
    {
        next = nullptr;
    }
};

class List
{
private:
    node *root;
    node *tail;
    node *curr_node;
    // node* traverse;
    int list_size;
    void init()
    {
        curr_node = tail = root = new node();
        // traverse=root->next;
        list_size = 0;
    }
    void removeList()
    {
        while (root != nullptr)
        {
            curr_node = root;
            root = root->next;
            delete curr_node;
        }
    }

public:
    // List()
    // {
    //     init();
    // }
    List(int total_size)
    {
        cout<<"constructor called"<<endl;
        init();
    }
    ~List()
    {
        cout<<"destructor called"<<endl;
        removeList();
    }
    void remove()
    {
        node *removeNode = curr_node->next;
        curr_node->next = removeNode->next;
        free (removeNode);
    }
    void insert(int item)
    {
        curr_node->next = new node(item, curr_node->next);
        if (tail == curr_node)
        {
            tail = curr_node->next;
        }
        // if(curr_node==root){
        //     curr_node=curr_node->next;
        // }
        list_size++;
    }
    void show()
    {
        node *traverse = root->next;
        // cout<<"list size "<<list_size<<endl;
        cout << "< ";
        for (int i = 0; i < list_size; i++)
        {
            if (currPos() == i)
            {
                cout << " | " << (traverse->item) ;
            }
            else
            {
                cout << (traverse->item) ;
                // cout<<"value of i:"<<i<< "and currPos()"<<currPos()<<endl;
            }
            traverse = traverse->next;
        }
        cout << " >";
        cout << endl;
    }
    void moveToStart()
    {
        curr_node = root;
    }
    void moveToEnd()
    {
        // curr_node=tail;
        while (curr_node->next != tail)
        {
            curr_node = curr_node->next;
        }
    }
    void moveToPos(int pos)
    {
        moveToStart();
        for (int i = 0; i < pos; i++)
        {
            curr_node = curr_node->next;
        }
    }
    int currPos()
    {
        node *traverse;
        traverse = root;
        int count = -1;
        while (traverse != curr_node)
        {
            traverse = traverse->next;
            count++;
        }
        return (count + 1);
    }
    int length()
    {
        return list_size;
    }
    void prev()
    {
        node *traverse;
        traverse = root;
        while ((traverse->next) != curr_node)
        {
            traverse = traverse->next;
        }
        curr_node = traverse;
    }
    void next()
    {
        curr_node = curr_node->next;
    }
    int getValue()
    {
        return ((curr_node->next)->item);
    }


};

