#include <iostream>
#include "SinglyLinkedList.h"

void SinglyLinkedList::copy(const SinglyLinkedList& rhs)
{
	this->size = rhs.size;
	this->first = new Node(rhs.first->data);

	Node* copy = rhs.first;
	Node* cur = this->first;

	while (copy->next != nullptr) {
		cur->next = new Node(copy->next->data);
		copy = copy->next;
		cur = cur->next;
	}
}

void SinglyLinkedList::clear() {
	Node* temp = nullptr;

	while (this->first != nullptr) {
		temp = new Node(first->data);
		first = first->next;
		delete temp;
	}

	this->size--;
}

SinglyLinkedList::SinglyLinkedList()
{
	this->first = nullptr;
	this->size = 0;
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& rhs)
{
	this->copy(rhs);
}

SinglyLinkedList& SinglyLinkedList::operator=(const SinglyLinkedList& rhs)
{
	if (this != &rhs) {
		this->clear();
		this->copy(rhs);
	}

	return *this;
}

SinglyLinkedList::~SinglyLinkedList()
{
	this->clear();
}

void SinglyLinkedList::insert_front(int element)
{
	Node* newNode = new Node(element);

	if (this->first != nullptr) {
		newNode->next = this->first;
	}

	this->first = newNode;
	this->size++;
}

void SinglyLinkedList::insert_last(int element) {
	Node* newNode = new Node(element);

	// if the list is empty
	if (this->first == nullptr) {
		this->first = newNode;
	}
	else {
		Node* current = this->first;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = newNode;
	}
	this->size++;
}

void SinglyLinkedList::insert_before(int element, int beforeData) {
	Node* cur = this->first;
	Node* newNode = new Node(element);
	
	while (cur->next != nullptr) {
		
		if (cur->next->data == beforeData)
		{
			newNode->next = cur->next;
			cur->next = newNode;
			break;
			
		}
		cur = cur->next;
	}
	
	this->size++;
}

void SinglyLinkedList::remove_first()
{
	Node* toDelete = nullptr;
	
	if (first->next != nullptr) {
		toDelete = new Node(first->data);
		first = first->next;
		delete toDelete;
	}
	
	this->size--;
}

void SinglyLinkedList::remove_last() 
{
	Node* cur = this->first;
	Node* toDelete = nullptr;

	if (first == nullptr) {
		return;
	}
	else if (first->next == nullptr) {
		first = nullptr;
		delete first;
		std::cout << "There's only one node in the list!\n";
	} else {
		while (cur->next != nullptr) {
			toDelete = cur;
			//toDelete = new Node(cur->data);
			cur = cur->next;
		}
		toDelete->next = nullptr;
		delete cur;
	}
	
	this->size--;
}

void SinglyLinkedList::remove_before(int afterData)
{
	Node* cur = this->first;
	Node* toDelete = nullptr;
	
	while (cur->next != nullptr) {
		if (cur->next->next->data == afterData) {
			toDelete = new Node(cur->next->data);
			cur->next = cur->next->next;
			delete toDelete;
			break;
		}
		cur = cur->next;
	}
	this->size--;
}

bool SinglyLinkedList::contains(int data) const
{
	Node* cur = this->first;

	while (cur != nullptr) {
		if (cur->data == data) {
			return true;
		}
		cur = cur->next;
	}

	return false;
}

int SinglyLinkedList::count(int element) {
	Node* current = this->first;
	int counter = 0;

	if (this->first == nullptr) {
		return counter;
	}

	while (current != nullptr) {
		if (current->data == element) {
			counter++;
		}
		current = current->next;
	}

	return counter;
}

size_t SinglyLinkedList::getSize() const
{
	return this->size;
}

void SinglyLinkedList::print_list() const
{
	Node* cur = this->first;

	while (cur != nullptr) {
		std::cout << cur->data << " ";
		cur = cur->next;
	}

	std::cout << "\n";
}

void SinglyLinkedList::reverse()
{
	Node* cur = this->first;
	Node* prev = nullptr;
	Node* next = nullptr;

	while (cur != nullptr) {
		next = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next;
	}
	this->first = prev;
}

ostream& operator<<(ostream& os, const SinglyLinkedList& list)
{
	SinglyLinkedList::Node* cur = list.first;
	while (cur != nullptr) {
		os << cur->data << " ";
		cur = cur->next;
	}
	os << endl;

	return os;
}
