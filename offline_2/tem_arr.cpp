
#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class List
{
public:
    int total_size;
    T *ptr;
    int curr_pos;
    int tail;
    int used_size;
    List(int _total_size)
    {
        total_size = _total_size;
        // used_size = _used_size;
        used_size = 0;
        ptr = (T *)malloc(sizeof(T) * total_size);
        curr_pos = -1;
        tail = -1;
    }

    List()
    {
    }

    ~List()
    {
        // cout << "freed the list " << endl;
        free(ptr);
    }
    void resize()
    {
        ptr = (T *)realloc(ptr, (2 * total_size * sizeof(T)));
        total_size *= 2;
    }
    void show()
    {
        cout << "<";
        for (int i = 0; i < (tail + 1); i++)
        {
            if(i!=tail){
            cout << ptr[i] << ",";
            }
            else{
                cout<<ptr[i];
            }
        }
        cout << ">" << endl;
    }

    void remove()
    {
        cout<<"tail : and curr pos "<<curr_pos<<" "<<tail<<endl;
        if((tail-curr_pos)==1 && curr_pos!=-1){
            // cout<<"currpos back"<<curr_pos<<" "<<tail<<endl;
            curr_pos--;
        }
        if (curr_pos == -1)
        {
            for (int i = curr_pos + 1; i < tail; i++)
            {
                ptr[i] = ptr[i + 1];
            }
        }
        else
        {
            for (int i = curr_pos + 1; i < tail; i++)
            {
                ptr[i] = ptr[i + 1];
            }
        }
        ptr[tail] = T();
        used_size--;
        tail--;
    }

    void insert(T item)
    {
        if ((tail + 1) < total_size)
        {
            if (tail == -1)
            {
                ptr[++tail] = item;
            }
            else
            {
                for (int i = tail; i > curr_pos; i--)
                {
                    ptr[i + 1] = ptr[i];
                }
                tail++;
                // cout << "inserted item successfully" << endl;
                ptr[curr_pos + 1] = item;
                used_size++;
            }
        }
        else
        {
            resize();
            if (tail == -1)
            {
                ptr[++tail] = item;
            }
            else
            {
                for (int i = tail; i > curr_pos; i--)
                {
                    ptr[i + 1] = ptr[i];
                }
                tail++;
                // cout << "inserted item successfully" << endl;
                ptr[curr_pos + 1] = item;
                used_size++;
            }
        }
    }
    void next()
    {
        if (curr_pos < tail)
        {
            curr_pos++;
        }
    }
    void prev()
    {
        if (curr_pos != -1)
        {
            curr_pos--;
        }
    }
    void moveToEnd()
    {
        curr_pos = tail - 1;
    }
    void moveToStart()
    {
        curr_pos = -1;
    }
    void moveToPos(int pos)
    {
        curr_pos = pos - 1;
    }
    int currPos()
    {
        return curr_pos + 1;
    }
    int getValue()
    {
        return ptr[currPos()];
    }
    int length()
    {
        return (tail + 1);
    }
};

// int main()
// {
//     List<char> myList(10);
//     myList.insert('c');
//     myList.insert('g');
//     myList.insert('r');
//     myList.insert('t');
//     myList.insert('y');
//     myList.insert('u');
//     std::cout << myList.currPos() << std::endl;
//     myList.insert('f');
//     myList.show();
//     // myList.moveToPos(3);
//     myList.moveToEnd();
//     myList.show();
//     myList.remove();
//     myList.show();
// }