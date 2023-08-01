#include <iostream>
#include <cstdlib>
using namespace std;

template <typename T>
class List
{
public:
    int total_size;
    T *ptr;
    int head;
    int curr_pos;
    int tail;
    int used_size;

    List()
    {

        total_size = 2;
        used_size = 0;
        ptr = (T *)malloc(sizeof(T) * total_size);
        curr_pos = -1;
        head = 1;
        tail = 0;
    }

    ~List()
    {
        cout << "freed the list " << endl;
        free(ptr);
    }

    void resize()
    {
        if (head <= tail)
        {
            ptr = (T *)realloc(ptr, (2 * total_size * sizeof(T)));
            total_size = 2 * total_size;
        }
        else
        {
            int last_indx = total_size - 1;
            ptr = (T *)realloc(ptr, (2 * total_size * sizeof(T)));
            total_size = 2 * total_size;
            for (int i = 0; i <= tail; i++)
            {
                ptr[++last_indx] = ptr[i];
            }
            tail = last_indx;
        }
    }

    void insert(T item)
    {
        if ((tail + 2) % total_size == head)
        {
            resize();
        }

        tail = (tail + 1) % total_size;
        ptr[tail] = item;

        used_size++;
    }

    int rear()
    {
        return tail;
    }
    int root()
    {
        return head;
    }

    T dequeue()
    {
        T front_val = ptr[head];
        head = (head + 1) % total_size;
        return front_val;
    }

    T front()
    {
        return ptr[head];
    }
    T back()
    {
        return ptr[tail];
    }
    int length()
    {
        return (tail + total_size + 1 - head) % total_size;
    }
    int total_s()
    {
        return total_size;
    }
    void clear()
    {
        tail = -1;
        head = 0;
    }

    bool is_empty()
    {
        if (length() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void show()
    {
        cout << "< ";
        int cur = head;
        int tot = total_size;
        // for (int i = head; i <= tail; i = (i + 1) % total_size)
        while (tot--)
        {
            if (cur != tail)
            {
                cout << ptr[cur] << ",";
            }
            else
            {
                cout << ptr[cur];
                break;
            }
            cur = (cur + 1) % total_size;
        }
        cout << " >" << endl;
    }
};