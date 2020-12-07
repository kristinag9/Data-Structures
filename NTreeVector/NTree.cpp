#include "NTree.h"

NTree::Node::Node(int _data)
{
	data = _data;
	children = {}; // initialize the vector	
}

void NTree::clear(Node* current)
{
	if (current == nullptr) {
		return;
	}

	for (Node* node : current->children) {
		clear(node);
	}

	delete current;
	current = nullptr;
}

NTree::Node* NTree::copy(Node* current) {
	if (current == nullptr) {
		return nullptr;
	}

	Node* newNode = new Node(current->data);

	for (Node* node : current->children) {
		newNode->children.push_back(copy(node));
	}

	return newNode;
}

bool NTree::addElementHelper(Node*& current, const char* path, const int element)
{
	// *path -> take the first element
	if (*path == '\0') {
		current->children.push_back(new Node(element));
		return true;
	}

	int currentNumber = 0;

	if (*path == ' ') {
		++path;
	}

	do {
		currentNumber = currentNumber * 10 + (*path - '0');
		++path;
	} while (*path != '\0' && *path != ' ');

	for (Node* node : current->children) {
		if (node != nullptr && node->data == currentNumber) {
			return addElementHelper(node, path, element);
		}
	}

	return false;
}


bool NTree::containsElement(Node* current, const int element) const
{
	if (current == nullptr) {
		std::cout << "The tree is empty!\n";
		return false;
	}

	if (current->data == element) {
		return true;
	}

	for (Node* node : current->children) {
		if (node->data == element || containsElement(node, element)) {
			return true;
		}
	}

	return false;
}

bool NTree::isChildOfHelper(Node* current, const int father, const int child) const
{
	if (current == nullptr) {
		return false;
	}

	if (current->data == father) {
		for (Node* node : current->children) {
			if (node->data == child) {
				return true;
			}
		}
		return false;
	}

	for (Node* node : current->children) {
		return isChildOfHelper(node, father, child);
	}

	return false;
}

int NTree::sumHelper(Node* current) const
{
	int sum = 0;
	if (current == nullptr) {
		return sum;
	}

	sum += current->data;

	for (Node* node : current->children) {
		sum += sumHelper(node);
	}

	return sum;
}

int NTree::findMaxElementHelper(Node* current) const
{
	if (current == nullptr) {
		throw "The tree is empty!\n";
	}

	int max = current->data;

	for (Node* node : current->children) {
		int curMax = findMaxElementHelper(node);

		if (curMax > max) {
			max = curMax;
		}
	}

	return max;
}

unsigned NTree::countElementsHelper(Node* current) const
{
	int counter = 0;
	if (current == nullptr) {
		return counter;
	}

	for (Node* node : current->children) {
		counter += countElementsHelper(node);
	}

	return counter + 1;
}

unsigned NTree::findMaxHeightHelper(Node* current) const
{
	int max = 0;
	if (current == nullptr) {
		return max;
	}

	for (Node* node : current->children) {
		int curMax = findMaxHeightHelper(node);

		if (curMax > max) {
			max = curMax;
		}
	}

	return max + 1;
}

void NTree::printHelper(std::ostream& out, Node* current) const
{
	if (current == nullptr) {
		out << "The tree is empty!\n";
		return;
	}

	out << '(' << current->data;

	for (Node* node : current->children) {
		out << ' ';
		printHelper(out, node);
	}

	out << ')';
}

void NTree::printChildrenHelper(Node* current, const int data) const
{
	if (current == nullptr) {
		return;
	}

	if (current->data == data) {
		for (Node* node : current->children) {
			std::cout << node->data << ' ';
		}
		return;
	}
	
	for (Node* node : current->children) {
		printChildrenHelper(node, data);
	}
}

void NTree::elementsOnKLevelHelper(Node* current, unsigned level) const
{
	if (current == nullptr) {
		return;
	}

	if (level == 0) {
		std::cout << current->data << ' ';
		return;
	}

	for (Node* node : current->children) {
		elementsOnKLevelHelper(node, level - 1);
	}
}

void NTree::printNeighboursHelper(Node* current, const int data, unsigned& level) const
{
	if (current == nullptr) {
		std::cout << "The tree is empty!\n";
		return;
	}

	if (current->data == data) {
		elementsOnKLevel(level);
		return;
	}

	for (Node* node : current->children) {
		printNeighboursHelper(node, data, ++level);
		level--;
	}
}

void NTree::countSumEqualsToGrandfatherHelper(Node* current, unsigned& counter) const
{
	if (current == nullptr) {
		return;
	}

	for (Node* node : current->children) {
		int takeSum = 0;
		for (Node* nNode : node->children) {
			takeSum += nNode->data;
		}

		if (takeSum == current->data) {
			countSumEqualsToGrandfatherHelper(node, ++counter);
		} 
		
		countSumEqualsToGrandfatherHelper(node, counter);
	}
}

NTree::NTree()
{
	root = nullptr;
}

NTree::NTree(const NTree& other)
{
	root = copy(other.root);
}

NTree& NTree::operator=(const NTree& other)
{
	if (this != &other) {
		clear(root);
		root = copy(other.root);
	}

	return *this;
}

NTree::~NTree() {
	clear(root);
}

bool NTree::addElement(const char* path, const int element)
{
	if (path == nullptr) {
		if (root != nullptr) {
			std::cout << "An element was found!\n";
			return false;
		}

		root = new Node(element);
		return true;
	}

	return addElementHelper(root, path, element);
}

bool NTree::contains(const int element) const
{
	return containsElement(root, element);
}

bool NTree::isChildOf(const int father, const int child) const
{
	return isChildOfHelper(root, father, child);
}


int NTree::sum() const
{
	return sumHelper(root);
}

int NTree::findMaxElement() const
{
	return findMaxElementHelper(root);
}

unsigned NTree::countElements() const
{
	return countElementsHelper(root);
}

unsigned NTree::findMaxHeight() const
{
	return findMaxHeightHelper(root);
}

unsigned NTree::countSumEqualsToGrandfather() const
{
	unsigned result = 0;
	countSumEqualsToGrandfatherHelper(root, result);

	return result;
}

void NTree::print(std::ostream& out) const
{
	printHelper(out, root);
}

void NTree::printChildren(const int data) const
{
	printChildrenHelper(root, data);
}

void NTree::elementsOnKLevel(unsigned level) const
{
	elementsOnKLevelHelper(root, level);
}

void NTree::printDFS() const
{
	if (root == nullptr) {
		return;
	}

	std::stack<Node*> frontier;
	frontier.push(root);

	while (!frontier.empty()) {
		Node* sndCurrent = frontier.top();
		frontier.pop();
		std::cout << sndCurrent->data << ' ';

		std::stack<Node*> currentElements;
		for (Node* node : sndCurrent->children) {
			currentElements.push(node);
		}

		while (!currentElements.empty()) {
			frontier.push(currentElements.top());
			currentElements.pop();
		}
	}
}

void NTree::printBFS() const
{
	if(root == nullptr) {
		return;
	}

	std::queue<Node*> frontier;
	frontier.push(root);

	while (!frontier.empty()) {
		Node* sndCurrent = frontier.front();
		frontier.pop();
		std::cout << sndCurrent->data << ' ';

		for (Node* node : sndCurrent->children) {
			frontier.push(node);
		}
	}
}

void NTree::printNeighbours(const int data) const
{
	unsigned level = 0;
	printNeighboursHelper(root, data, level);
}



