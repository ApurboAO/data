#include <iostream>

template <typename T>
class LList
{
private:
    struct Node
    {
        T data;
        Node *next;
        Node(const T &value) : data(value), next(nullptr) {}
    };

    Node *head;

public:
    LList() : head(nullptr) {}

    ~LList()
    {
        clear();
    }

    void push(const T &value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void reverse()
    {
        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void display() const
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void clear()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }
    void merge_list(LList<T>list_1,LList<T>list_2){
        Node* tail;
        while()
    }
};

int main()
{
    LList<int> myList;

    myList.push(4);
    myList.push(5);
    myList.push(3);
    myList.push(2);
    myList.push(7);

    std::cout << "Original List: ";
    myList.display();

    myList.reverse();

    std::cout << "Reversed List: ";
    myList.display();
    myList.reverse();
    myList.display();

    return 0;
}
