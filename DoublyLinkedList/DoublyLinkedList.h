#pragma once
#include <iostream>

class DoublyLinkedList {
private:
	struct Node {
		int data;
		Node* next;
		Node* prev;

		Node(const int& data, Node* next = nullptr, Node* prev = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};

	Node* first, * last;

	void copy(const DoublyLinkedList& rhs);
	void clear();
	void clearReverse();

public:
	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& rhs);
	DoublyLinkedList& operator=(const DoublyLinkedList& rhs);
	~DoublyLinkedList();

	DoublyLinkedList operator+(const int& element) const;  
	DoublyLinkedList& operator+=(const int& element);		

	void insert_front(const int& data);
	void insert_last(const int& data);
	void insert_before(int data, int beforeData);
	void insert_after(int data, int afterData);

	void remove_first();
	void remove_last();
	void remove_by_value(int data);
	void remove_at_pos(int position);

	int count(int elementInList);
	void removeAll(const int& elementInList);

	void print() const;
	void reverse();
	//friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& rhs);

};
