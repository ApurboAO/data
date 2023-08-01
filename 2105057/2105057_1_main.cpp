#include <bits/stdc++.h>
#include "2105057_1_ll_queue.cpp"
// #include"2105057_1_a_queue.cpp"

int main() {
    Queue<int> queue;

    std::string input;
    while (getline(std::cin, input)) {
        int Q, P;
        sscanf(input.c_str(), "%d %d", &Q, &P);

        if (Q == 0) {
            break;
        }

        switch (Q) {
            case 1:
                queue.enqueue(P);
                break;
            case 2:
                if (queue.is_empty()) {
                    cout << "Error: Queue is empty!" << endl;
                } else {
                    cout << queue.dequeue() << endl;
                }
                break;
            case 3:
                cout << queue.length() << endl;
                break;
            case 4:
                if (queue.is_empty()) {
                    cout << "Error: Queue is empty!" << endl;
                } else {
                    cout << queue.front() << endl;
                }
                break;
            case 5:
                if (queue.is_empty()) {
                    cout << "Error: Queue is empty!" << endl;
                } else {
                    cout << queue.back() << endl;
                }
                break;
            case 6:
                cout << (queue.is_empty() ? "True" : "False") << endl;
                break;
            case 7:
                queue.clear();
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
        }

        // Print the queue contents
        
        queue.show_queue();
        
    }

    return 0;
}

// 4
// 1 10
// 3 2
// 1 20
// 1 30
