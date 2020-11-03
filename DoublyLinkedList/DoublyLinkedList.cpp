#include "DoublyLinkedList.h"
#include <iostream>

void DoublyLinkedList::copy(const DoublyLinkedList& rhs)
{
	this->first = new Node(rhs.first->data);

	Node* copy = rhs.first;
	Node* cur = this->first;

	while (copy->next != nullptr) {
		cur->next = new Node(copy->next->data);
		cur->next->prev = cur;
		cur = cur->next;
		copy = copy->next;
	}

	this->last = cur;
}

void DoublyLinkedList::clear() {
	Node* temp = nullptr;

	while (first != nullptr) {
		temp = new Node(first->data);
		first = first->next;
		delete temp;
	}

	this->last = nullptr;
}

void DoublyLinkedList::clearReverse()
{
	Node* temp = nullptr;
	while (last != nullptr) {
		temp = new Node(last->data);
		last = last->prev;
		delete temp;
	}

	this->first = nullptr;
}

DoublyLinkedList::DoublyLinkedList()
{
	this->first = nullptr;
	this->last = nullptr;
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& rhs)
{
	this->copy(rhs);
}

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& rhs)
{
	if (this != &rhs) {
		this->clear();
		this->copy(rhs);
	}
	return *this;
}

DoublyLinkedList::~DoublyLinkedList()
{
	clear();
}


DoublyLinkedList DoublyLinkedList::operator+(const int& element) const
{
	DoublyLinkedList result = (*this);
	result += element;
	return result;
}

DoublyLinkedList& DoublyLinkedList::operator+=(const int& element) {
	Node* newFirst = new DoublyLinkedList::Node(element, first, nullptr);
	first->prev = newFirst;
	first = newFirst;

	return *this;
}

void DoublyLinkedList::insert_front(const int& data)
{
	Node* newNode = new Node(data);

	if (this->first != nullptr) {
		newNode->next = this->first;
		this->first->prev = newNode;
	}

	this->first = newNode;
}

void DoublyLinkedList::insert_last(const int& data)
{
	Node* newNode = new Node(data);

	if (this->first == nullptr) {
		this->first = newNode;
	}
	else {
		Node* cur = this->first;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		cur->next = newNode;
		newNode->prev = cur;
	}

	/* if there is only one pointer - to the beginning
	Node* cur = new Node(data);
	while (cur->next != nullptr) {
		cur = cur->next;
	}
	//Node* newNode = new Node(data, cur);
	cur->next = newNode;*/
}

void DoublyLinkedList::insert_before(int data, int beforeData)
{
	Node* cur = this->first;
	Node* newNode = new Node(data);

	while (cur != nullptr && cur->data != beforeData) {
		cur = cur->next;
	}

	// insert at the beginning
	if (cur->prev == nullptr) {
		newNode->next = cur;
		cur->prev = newNode;
		this->first = newNode;
	}
	else {
		newNode->next = cur;
		newNode->prev = cur->prev;
		cur->prev->next = newNode;
		cur->prev = newNode;
	}
}

void DoublyLinkedList::insert_after(int data, int afterData)
{
	if (this->first == nullptr) {
		return;
	}

	Node* cur = this->first;
	Node* newNode = new Node(data);

	while (cur != nullptr && cur->data != afterData) {
		cur = cur->next;
	}

	// if we want to insert at the end
	if (cur->next == nullptr) {
		cur->next = newNode;
		newNode->prev = cur;
	}
	else {
		newNode->next = cur->next;
		newNode->prev = cur;
		cur->next = newNode;
		cur->next->prev = newNode;
	}
}

void DoublyLinkedList::remove_first()
{
	if (this->first == nullptr) {
		return;
	}

	Node* temp = this->first->next;
	delete this->first;
	this->first = temp;
}

void DoublyLinkedList::remove_last()
{
	if (this->first == nullptr) {
		return;
	}

	Node* cur = this->first;
	while (cur->next != nullptr) {
		cur = cur->next;
	}

	cur->prev->next = nullptr;
	delete cur;
}

void DoublyLinkedList::remove_by_value(int data)
{
	Node* cur = this->first;

	if (this->first == nullptr) {
		return;
	}

	while (cur->next != nullptr && cur->data != data) {
		cur = cur->next;
	}

	// deleting the first element
	if (cur->prev == nullptr) {
		cur->next->prev = nullptr;
		first = cur->next;
	}
	else if (cur->next == nullptr) { // deleting the last element
		cur->prev->next = nullptr;
	}
	else {
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
	}

	delete cur;
}

void DoublyLinkedList::remove_at_pos(int position)
{
	if (this->first == nullptr) {
		return;
	}

	Node* cur = this->first;
	for (int i = 0; i < position; i++) {
		cur = cur->next;
	}

	if (cur->prev == nullptr) {
		cur->next->prev == nullptr;
		this->first = cur->next;
	}
	else if (cur->next == nullptr) {
		cur->prev->next = nullptr;
	}
	else {
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
	}

	delete cur;
}

int DoublyLinkedList::count(int elementInList)
{
	int counter = 0;
	// if the list is empty
	if (this->first == nullptr) {
		return counter;
	}

	if (this->first->data == elementInList) {
		counter++;
	}

	Node* cur = this->first;

	while (cur->next != nullptr) {
		cur = cur->next;
	
		if (cur->data == elementInList) {
			counter++;
		}
	}	
	return counter;
}

void DoublyLinkedList::removeAll(const int& elementInList)
{
	if (this->first == nullptr) {
		return;
	}

	Node* cur = this->first;
	Node* temp;

	while (cur != nullptr) {
		if (cur->data == elementInList) {
			if (cur == this->first) {
				this->first = cur->next;
				if (this->first->prev != nullptr) {
					this->first->prev = nullptr;
				}
				else {
					this->last = nullptr;
				}
				delete cur;
				cur = this->first;
			}
			else if (cur == this->last) {
				this->last = cur->prev;
				this->last->next = nullptr;
				delete cur;
				cur = nullptr;
			}
			else {
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				Node* holder = cur->next;
				delete cur;
				cur = cur->next;
			}
		}
		else {
			cur = cur->next;
		}
	}
}

void DoublyLinkedList::print() const
{
	Node* cur = first;
	while (cur != nullptr) {
		std::cout << cur->data << " ";
		cur = cur->next;
	}
	std::cout << "\n";
}

void DoublyLinkedList::reverse() {
	Node* cur = this->first;
	Node* copy = nullptr;

	while (cur != nullptr) {
		copy = cur->prev;
		cur->prev = cur->next;
		cur->next = copy;
		cur = cur->prev;
	}

	if (copy != nullptr) {
		this->first = copy->prev;
	}
}

//template<class T>
//std::ostream& operator<<(std::ostream& os, const DoublyLinkedList<T>& rhs)
//{
//	DoublyLinkedList<T>::Node* cur = rhs.first;
//	while (cur != nullptr) {
//		os << cur->data << " ";
//		cur = cur->next;
//	}
//	
//	return os;
//}