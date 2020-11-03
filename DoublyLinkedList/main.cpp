#include <iostream>
#include "DoublyLinkedList.h"

int main() {
	DoublyLinkedList dList;

	dList.insert_front(5);
	dList.insert_front(4);
	dList.insert_front(3);
	dList.print();

	dList.insert_last(2);
	dList.print();

	dList.insert_after(7, 3);
	dList.print();

	dList.insert_before(8, 5);
	dList.print();

	dList.reverse();
	dList.print();

	DoublyLinkedList dListCopy = dList;
	dListCopy.print();

	DoublyLinkedList result = dListCopy + 4;
	result.print();

	result += 10;
	result.print();

	result.insert_front(4);
	result.insert_front(2);
	result.insert_front(2);
	result.insert_front(2);
	result.print();
	std::cout << "The times 10 is met: " << result.count(10) << std::endl;
	std::cout << "The times 4 is met: " << result.count(4) << std::endl;
	std::cout << "The times 2 is met: " << result.count(2) << std::endl;
	
	result.removeAll(4);
	result.print();
	/*dList.remove_first();
	dList.print();

	dList.remove_last();
	dList.print();

	dList.remove_by_value(8);
	dList.print();

	dList.remove_at_pos(2);
	dList.print();*/

	return 0;
}