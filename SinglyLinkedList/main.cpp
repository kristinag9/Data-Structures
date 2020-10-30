#include <iostream>
#include "SinglyLinkedList.h"

int main() {
	SinglyLinkedList myList;
	myList.insert_last(5);
	myList.insert_last(6);
	myList.insert_last(2);
	myList.insert_last(5);
	//myList.insert_front(1);
	//myList.insert_front(3);

	myList.insert_before(9, 2);
	myList.print_list();
	//myList.remove_last();
	//myList.print_list();
	myList.remove_before(2);
	myList.print_list();

	myList.reverse();
	myList.print_list();

	//myList.print_list();
	//myList.~SinglyLinkedList();
	//myList.print_list();

	//myList.print_list();
	std::cout << "List's size: " << myList.getSize();

	if (myList.contains(5)) {
		std::cout << "\nIt contains 5.\n";
	}
	else {
		std::cout << "\nIt doesn't contain1 5.\n";
	}

	if (myList.contains(1)) {
		std::cout << "\nIt contains 1.\n";
	}
	else {
		std::cout << "\nIt doesn't contain 1.\n";
	}

	int countElem = myList.count(5);
	std::cout << countElem << "\n";

	SinglyLinkedList newList = myList;
	std::cout << "Testing copy constructor: " << newList;



	return 0;
}