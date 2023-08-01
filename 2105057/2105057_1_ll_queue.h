#include <bits/stdc++.h>
using namespace std;

template <typename T>
class node
{
public:
    T item;
    node *next;
    node(T _item, node *_next = nullptr)
    {
        item = _item;
        next = _next;
    }
    node()
    {
        next = nullptr;
    }
};

template <typename T>
class List
{
private:
    node<T> *root;
    node<T> *tail;
    node<T> *curr_node;
    // node* traverse;
    int list_size;
    void init()
    {
        curr_node = tail = root = new node<T>();
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
    List()
    {
        init();
    }
    List(int total_size)
    {
        // cout<<"constructor called"<<endl;
        init();
    }
    ~List()
    {
        // cout<<"destructor called"<<endl;
        removeList();
    }
    void remove()
    {
        node<T> *removeNode = curr_node->next;
        curr_node->next = removeNode->next;
        free(removeNode);
        list_size--;
    }

    void clear()
    {
        moveToStart();
        while (curr_node->next != tail)
        {
            remove();
        }
        remove();
        tail = root;
        list_size = 0;
    }

    void insert(T item)
    {
        curr_node->next = new node<T>(item, curr_node->next);
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
        node<T> *traverse = root->next;

        cout << "< ";
        for (int i = 0; i < list_size; i++)
        {
            if (i == (list_size - 1))
            {
                cout << (traverse->item);
            }
            else
            {
                cout << (traverse->item) << ",";
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
        curr_node = tail;
        // while (curr_node->next != tail)
        // {
        //     curr_node = curr_node->next;
        // }
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
        node<T> *traverse;
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
        node<T> *traverse;
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
    T getValue()
    {
        if (curr_node == root)
        {
            return ((curr_node->next)->item);
        }
        if (curr_node == tail)
        {
            return curr_node->item;
        }
    }

    bool is_empty()
    {
        if (root == tail)
        {
            return true;
        }
        return false;
    }
};
