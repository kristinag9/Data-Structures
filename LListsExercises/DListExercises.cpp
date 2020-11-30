#include <iostream>
#include <stack>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int _data, Node* _next = nullptr, Node* _prev = nullptr) {
        data = _data;
        next = _next;
        prev = _prev;
    }
};

// Task 1. Write a function which check if a doubly linked list is a palindrome
bool isPalindrome(Node* start) {
    if (start == nullptr) {
        return true;
    }

    Node* current = start;

    std::stack<int> elementsFromList;
    while (current != nullptr) {
        elementsFromList.push(current->data);
        current = current->next;
    }

    current = start;

    while (elementsFromList.empty() == false) {
        if (current->data != elementsFromList.top()) {
            return false;
        }
        current = current->next;
        elementsFromList.pop();
    }

    return true;
}

Node* reverse(Node* start) {
    if (start == nullptr) {
        return nullptr;
    }

    Node* current = new Node(start->data);

    start = start->next;
    while (start != nullptr) {
        current = new Node(start->data, current);
        current->next->prev = current;
        start = start->next;
    }

    return current;
}

int main() {
    Node* n1 = new Node(3);
    Node* n2 = new Node(2);
    Node* n3 = new Node(1);

    n1->next = n2;
    n2->prev = n1;
    n2->next = n3;
    n3->prev = n2;

    std::cout << isPalindrome(n1);

    Node* result = reverse(n1);
    while (result != nullptr)
    {
        std::cout << result->data << ' ';
        result = result->next;
    }

    return 0;
}