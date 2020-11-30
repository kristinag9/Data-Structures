#include <iostream>
#include <stack>

// Задача 1. Дефинирайте функцията void swapWithSecond(Node* &first, int element),
// която намира подадената стойност в списъка и я разменя със стойността на елемента,
// намиращ се на две позиции напред в списъка (ако е възможно).
// Ако списъкът не съдържа подадената стойност се извежда съобщение, че не е възможна размяна. 
struct Node {
    int data;
    Node* next;

    Node(int _data, Node* _next = nullptr) {
        data = _data;
        next = _next;
    }
};

void swapWithSecond(Node*& first, int element) {
    if (first == nullptr) {
        std::cout << "No elements\n";
        return;
    }

    Node* current = first;
    while (current != nullptr) {
        if (current->next == nullptr || current->next->next == nullptr) {
            std::cout << "Element cannot be swapped!\n";
            return;
        }
        
        if (current->data == element) {
            int temp = current->data;
            current->data = current->next->next->data;
            current->next->next->data = temp;
            return;
        }

        current = current->next;

    }
}

// Задача 2. Дефинирайте функцията void deleteSum(Node* &first), 
// която намира разликата на най-големия и най-малкия елемент в списъка и ако в него съществува възел с такава стойност, 
// изтрива всички негови срещания. В противен случай извежда съобщение, че не е намерен такъв елемент.
void deleteSum(Node*& first) {
    if (first == nullptr) {
        return;
    }

    Node* start2 = first;
    Node* current = first;
    int min = current->data;
    int max = current->data;
    int diff = 0;

    current = current->next;
    while (current != nullptr) {
        if (current->data < min) {
            min = current->data;
        }
        else if (current->data > max) {
            max = current->data;
        }

        current = current->next;
    }

    diff = max - min;

    if (first->data == diff) {
        Node* toDelete = first;
        first = first->next;
        toDelete->next = nullptr;
        delete toDelete;
        return;
    }

    while (start2 != nullptr) {
        if (start2->next->data == diff) {
            Node* toDelete = start2->next;
            start2->next = toDelete->next;
            toDelete->next = nullptr;
            delete toDelete;
        }
        start2 = start2->next;
    }
}

// Задача 3. 
int countElements(Node* first) {
    Node* current = first;
    int counter = 0;

    while (current != nullptr) {
        counter++;
        current = current->next;
    }
    return counter;
}

void pushFront(Node* first, int data) {
    Node* newNode = new Node(data);

    newNode->next = first;
    first = newNode;
}

void shuffle(Node* first) {
    int count = countElements(first);

    int size = count % 2 == 0 ? count / 2 : count / 2 + 1;
    Node* current = first;
    while (current != nullptr)
    {
        current = current->next;
    }

    std::stack<int> elemFromList;
    Node* holder = current->next;
    current->next = nullptr;

    while (holder != nullptr) {
        elemFromList.push(holder->data);
        holder = holder->next;
    }

    std::stack<int> reverse;

    while (elemFromList.empty() == false) {
        reverse.push(elemFromList.top());
        elemFromList.pop();
    }

    while (!reverse.empty()) {
        pushFront(first, reverse.top());
        reverse.pop();
    }
}

int main()
{
    Node* n1 = new Node(3);
    Node* n2 = new Node(2);
    Node* n3 = new Node(1);
    Node* n4 = new Node(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

   //swapWithSecond(n1, 2);
    deleteSum(n1);
    while (n1 != nullptr)
    {
        std::cout << n1->data << ' ';
        n1 = n1->next;
    }

    return 0;
}
