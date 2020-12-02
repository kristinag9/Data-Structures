#include "BinaryTree.h"

BinaryTree::Node* BinaryTree::copy(Node* current) {
	if (current == nullptr) {
		return nullptr;
	}

	Node* copyNode = new Node(current->data);
	copyNode->left = copy(current->left);
	copyNode->right = copy(current->right);

	return copyNode;
}

void BinaryTree::clear(Node* current) {
	if (current == nullptr) {
		return;
	}

	clear(current->left);
	current->left = nullptr;
	clear(current->right);
	current->right = nullptr;
	delete current;
	current = nullptr;
}

BinaryTree::BinaryTree() {
	root = nullptr;
}

BinaryTree::BinaryTree(const BinaryTree& other) {
	root = copy(other.root);
}

BinaryTree& BinaryTree::operator=(const BinaryTree& other) {
	if (this != &other) {
		clear(root);
		root = copy(other.root);
	}

	return *this;
}

BinaryTree::~BinaryTree() {
	clear(root);
}

bool BinaryTree::addElement(const std::string& path, int data) {
	unsigned lengthOfPath = path.length();

	if (lengthOfPath == 0) {
		if (root != nullptr) {
			return false;
		}
		root = new Node(data);
		return true;
	}

	Node* current = root;

	for (int i = 0; i < lengthOfPath - 1; i++) {
		if (current == nullptr) {
			return false;
		}

		if (path[i] == 'L') {
			current = current->left;
		}
		else if (path[i] == 'R') {
			current = current->right;
		}
		else {
			return false;
		}
	}

	if (current == nullptr) {
		return false;
	}

	if (path[lengthOfPath - 1] == 'L') {
		if (current->left != nullptr) {
			return false;
		}
		current->left = new Node(data);
		return true;
	}
	else if (path[lengthOfPath - 1] == 'R') {
		if (current->right != nullptr) {
			return false;
		}
		current->right = new Node(data);
		return true;
	}

	return false;
}

void BinaryTree::printPreorderHelper(std::ostream& out, Node* current) const {
	if (current == nullptr) {
		out << 'X';
		return;
	}

	out << '(' << current->data << ' ';
	printPreorderHelper(out, current->left);
	out << ' ';
	printPreorderHelper(out, current->right);
	out << ')';
}

void BinaryTree::printInorderHelper(std::ostream& out, Node* current) const {
	if (current == nullptr) {
		out << 'X';
		return;
	}

	out << '(';
	printInorderHelper(out, current->left);
	out << ' ' << current->data << ' ';
	printInorderHelper(out, current->right);
	out << ')';
}

void BinaryTree::printPostorderHelper(std::ostream& out, Node* current) const {
	if (current == nullptr) {
		out << 'X';
		return;
	}

	out << '(';
	printInorderHelper(out, current->right);
	out << ' ' << current->data << ' ';
	printInorderHelper(out, current->left);
	out << ')';
}

void BinaryTree::printPreorder(std::ostream& out) const {
	printPreorderHelper(out, root);
}

void BinaryTree::printInorder(std::ostream& out) const {
	printInorderHelper(out, root);
}

void BinaryTree::printPostOrder(std::ostream& out) const {
	printPostorderHelper(out, root);
}

unsigned BinaryTree::numberOfElementsHelper(Node* current) const {
	if (current == nullptr) {
		return 0;
	}

	return 1 + numberOfElementsHelper(current->left) + numberOfElementsHelper(current->right);
}

unsigned BinaryTree::numberOfElemsInRightHelper(Node* current) const {
	if (current == nullptr) {
		return 0;
	}

	return 1 + numberOfElemsInRightHelper(current->right);
}

unsigned BinaryTree::numberOfElemsInLeftHelper(Node* current) const {
	if (current == nullptr) {
		return 0;
	}

	return 1 + numberOfElemsInRightHelper(current->left);
}

unsigned BinaryTree::numberOfLeavesHelper(Node* current) const {
	if (current == nullptr) {
		return 0;
	}

	if (current->left == nullptr && current->right == nullptr) {
		return 1;
	}

	return numberOfLeavesHelper(current->left) + numberOfLeavesHelper(current->right);
}

unsigned BinaryTree::numberOfElements() const {
	return numberOfElementsHelper(root);
}

unsigned BinaryTree::numberOfElemsInRight() const {
	return numberOfElemsInRightHelper(root);
}

unsigned BinaryTree::numberOfElemsInLeft() const {
	return numberOfElemsInLeftHelper(root);
}

unsigned BinaryTree::numberOfLeaves() const {
	return numberOfLeavesHelper(root);
}

unsigned BinaryTree::numberOfOddElementsHelper(Node* current) const {
	if (current == nullptr) {
		return 0;
	}

	if (current->data % 2 != 0) {
		return 1 + numberOfOddElementsHelper(current->left) + numberOfOddElementsHelper(current->right);
	}

	return numberOfOddElementsHelper(current->left) + numberOfOddElementsHelper(current->right);
}

unsigned BinaryTree::numberOfEvenElementsHelper(Node* current) const {
	if (current == nullptr) {
		return 0;
	}

	if (current->data % 2 == 0) {
		return 1 + numberOfEvenElementsHelper(current->left) + numberOfEvenElementsHelper(current->right);
	}

	return numberOfEvenElementsHelper(current->left) + numberOfEvenElementsHelper(current->right);
}

unsigned BinaryTree::numberOfOddElements() const {
	return numberOfOddElementsHelper(root);
}

unsigned BinaryTree::numberOfEvenElements() const {
	return numberOfEvenElementsHelper(root);
}

void BinaryTree::printLeavesHelper(Node* current) const {
	if (current == nullptr) {
		return;
	}
	
	if (current->left == nullptr && current->right == nullptr) {
		std::cout << current->data << ' ';
		return;
	}

	printLeavesHelper(current->left);
	printLeavesHelper(current->right);
}

void BinaryTree::printOnKLevelHelper(Node* current, unsigned level) const {
	if (current == nullptr) {
		return;
	}

	if (level == 0) {
		std::cout << current->data << ' ';
	}

	printOnKLevelHelper(current->left, level - 1);
	printOnKLevelHelper(current->right, level - 1);
}

void BinaryTree::printLeaves() const {
	printLeavesHelper(root);
}

void BinaryTree::printOnKLevel(unsigned level) const {
	printOnKLevelHelper(root, level);
}

bool BinaryTree::isEmpty() const {
	return root == nullptr;
}

int BinaryTree::getRootData() const {
	if (root == nullptr) {
		std::cout << "The tree is empty!\n";
		return 1;
	}
	return root->data;
}

unsigned BinaryTree::findMaxHeightHelper(Node* current) const {
	if (current == nullptr) {
		return 0;
	}

	int left = findMaxHeightHelper(current->left);
	int right = findMaxHeightHelper(current->right);
	int max = left > right ? left : right;

	return 1 + max;
}

int BinaryTree::sumOfElementsHelper(Node* current) const {
	if (current == nullptr) {
		return 0;
	}

	return current->data + sumOfElementsHelper(current->left) + sumOfElementsHelper(current->right);
}

void BinaryTree::findByIndexHelper(Node* current, Node*& result, int& index) const
{
	if (current == nullptr || index < 0) {
		return;
	}

	findByIndexHelper(current->left, result, index);

	if (index == 0) {
		result = new Node(current->data);
		index = -1;
		return;
	}
	--index;

	findByIndexHelper(current->right, result, index);
}

bool BinaryTree::isBiggerThanElement(Node* current, int data) const {
	if (current == nullptr) {
		return true;
	}

	if (current->data > data) {
		return false;
	}

	return isBiggerThanElement(current->left, data) && isBiggerThanElement(current->right, data);
}

bool BinaryTree::isSmallerThanElement(Node* current, int data) const {
	if (current == nullptr) {
		return true;
	}

	if (current->data < data) {
		return false;
	}

	return isSmallerThanElement(current->left, data) && isSmallerThanElement(current->right, data);
}

bool BinaryTree::isSymmetricHelper(Node* currentLeftTree, Node* currentRightTree) const
{
	if (currentLeftTree == nullptr && currentRightTree == nullptr) {
		return true;
	}

	if (currentLeftTree != nullptr && currentRightTree != nullptr) {
		if (currentLeftTree->data == currentRightTree->data) {
			return isSymmetricHelper(currentLeftTree->left, currentRightTree->right) &&
				isSymmetricHelper(currentLeftTree->right, currentRightTree->left);
		}

	}
	return false;
}

int* BinaryTree::createArrayHelper(Node* current) const
{
	if (current == nullptr) {
		throw "The tree is empty!\n";
	}

	size_t size = numberOfElements();
	int* result = new int[size];

	for (int i = 0; i < size; i++) {
		result[i] = findByIndex(i);
	}

	return result;
}

bool BinaryTree::isBinaryOrderedTreeHelper(Node* current) const {
	if (current == nullptr) {
		return true;
	}

	if (isBiggerThanElement(current->left, current->data) == false) {
		return false;
	}

	if (isSmallerThanElement(current->right, current->data) == false) {
		return false;
	}

	return true;
}

int BinaryTree::sumOfElements() const {
	return sumOfElementsHelper(root);
}

unsigned BinaryTree::findMaxHeight() const {
	return findMaxHeightHelper(root);
}

double BinaryTree::average() const {
	return sumOfElementsHelper(root) / numberOfElementsHelper(root);
}

bool BinaryTree::isBinaryOrderedTree() const {
	return isBinaryOrderedTreeHelper(root);
}

int BinaryTree::findByIndex(int index) const
{
	if (root == nullptr) {
		std::cout << "Element is not found!\n";
		return -1;
	}

	Node* result = nullptr;
	findByIndexHelper(root, result, index);

	if (result == nullptr) {
		std::cout << "Element is not found!\n";
		return -1;
	}

	return result->data;
}

int* BinaryTree::createArray() const
{
	try {
		return createArrayHelper(root);
	}
	catch (const char* message) {
		std::cout << message;
		return new int[0];
	}
}

bool BinaryTree::isSymmetric() const
{
	return isSymmetricHelper(root, root);
}
