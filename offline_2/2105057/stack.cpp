
template <typename T>
class Stack
{
public:
    T *ptr;
    int total_size;
    int topIn;

    Stack(int _total_size)
    {
        ptr = (T *)malloc(sizeof(T) * _total_size);
        total_size = _total_size;
        topIn = -1;
    }
    ~Stack()
    {
        free(ptr);
    }

    void push(T item)
    {
        if (total_size == (topIn + 1))
        {
            ptr = (T *)realloc(ptr, 2 * sizeof(T) * total_size);
        }
        ptr[++topIn] = item;
    }
    T pop()
    {
        T topval = ptr[topIn];
        topIn--;
        return topval;
    }
    T topValue()
    {
        return ptr[topIn];
    }
    T length()
    {
        return topIn + 1;
    }
    bool isEmpty()
    {
        return topIn == -1 ? true : false;
    }
    void clear()
    {
        topIn = -1;
    }
    void show_Stack()
    {
        int len = (topIn + 1);
        std::cout << "<";
        for (int i = 0; i < len; i++)
        {
            if (i != (len - 1))
            {
                std::cout << ptr[i] << ",";
            }
            else
            {
                std::cout << ptr[i];
            }
        }
        std::cout << ">" << std::endl;
    }
};
