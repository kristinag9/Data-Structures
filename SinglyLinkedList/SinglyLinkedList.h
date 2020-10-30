#pragma once
#include <iostream>
using namespace std;

class SinglyLinkedList {
private:
	struct Node {
		int data;
		Node* next;

		Node(const int& data, Node* next = nullptr) {
			this->data = data;
			this->next = next;
		}
	};

	Node* first;
	size_t size;

public:
	SinglyLinkedList();
	SinglyLinkedList(const SinglyLinkedList& rhs);
	SinglyLinkedList& operator=(const SinglyLinkedList& rhs);
	~SinglyLinkedList();

	void insert_front(int element);
	void insert_last(int element);
	void insert_before(int element, int elementInList);
	
	void remove_first();
	void remove_last();
	void remove_before(int afterData);

	bool contains(int data) const;
	size_t getSize() const;
	void print_list() const;

	int count(int element);
	void reverse();

	friend ostream& operator<<(ostream& os, const SinglyLinkedList& list);

private:
	void copy(const SinglyLinkedList& rhs);
	void clear();
};