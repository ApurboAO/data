
#include <iostream>
#include <cstdlib>
using namespace std;

class List
{
public:
    int total_size;
    int *ptr;
    int curr_pos;
    int tail;

    int used_size;
    List(int _total_size)
    {
        total_size = _total_size;
        // used_size = _used_size;
        used_size = 0;
        ptr = (int *)malloc(sizeof(int) * total_size);
        curr_pos = -1;
        tail = -1;
    }

    List()
    {
    }

    ~List()
    {
        // cout << "freed the list " << endl;
        // free(ptr);
    }
    void resize()
    {
        ptr = (int *)realloc(ptr, (2 * total_size * sizeof(int)));
        total_size *= 2;
    }
    void show()
    {
        cout << "< ";

        for (int i = 0; i < (tail + 1); i++)
        {
            if (i == currPos())
            {
                cout << "|" << ptr[i];
            }

            else
            {
                cout << " " << ptr[i] ;
            }
        }
        cout << " >" << endl;
    }



    void remove()
    {
        if (curr_pos == -1)
        {
            for (int i = curr_pos + 1; i < tail; i++)
            {
                ptr[i] = ptr[i + 1];
            }
        }
        else
        {
            for (int i = curr_pos; i < tail; i++)
            {
                ptr[i] = ptr[i + 1];
            }
        }
        ptr[tail + 1] = 0;
        used_size--;
        tail--;
    }

    void insert(int item)
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

