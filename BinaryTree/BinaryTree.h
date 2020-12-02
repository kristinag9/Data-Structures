#pragma once

#include <iostream>
#include <string>
#include <fstream>

class BinaryTree {
public:
	BinaryTree();
	BinaryTree(const BinaryTree& other);
	BinaryTree& operator=(const BinaryTree& other);
	~BinaryTree();

	bool addElement(const std::string& path, int data);
	bool isEmpty() const;
	int getRootData() const;
	int sumOfElements() const;
	unsigned findMaxHeight() const;
	double average() const;
	bool isBinaryOrderedTree() const;
	int findByIndex(int index) const;
	int* createArray() const;
	bool isSymmetric() const;

	void printPreorder(std::ostream& out) const;
	void printInorder(std::ostream& out) const;
	void printPostOrder(std::ostream& out) const;
	void printLeaves() const;
	void printOnKLevel(unsigned level) const;

	unsigned numberOfElements() const;
	unsigned numberOfElemsInRight() const;
	unsigned numberOfElemsInLeft() const;
	unsigned numberOfLeaves() const;
	unsigned numberOfOddElements() const;
	unsigned numberOfEvenElements() const;

private:
	struct Node {
		int data;
		Node* left;
		Node* right;

		Node(int _data, Node* _left = nullptr, Node* _right = nullptr) {
			data = _data;
			left = _left;
			right = _right;
		}
	};

	Node* root;

	Node* copy(Node* current);
	void clear(Node* current);

	void printPreorderHelper(std::ostream& out, Node* current) const;
	void printInorderHelper(std::ostream& out, Node* current) const;
	void printPostorderHelper(std::ostream& out, Node* current) const;
	void printLeavesHelper(Node* current) const;
	void printOnKLevelHelper(Node* current, unsigned level) const;

	unsigned numberOfElementsHelper(Node* current) const;
	unsigned numberOfElemsInRightHelper(Node* current) const;
	unsigned numberOfElemsInLeftHelper(Node* current) const;
	unsigned numberOfLeavesHelper(Node* current) const;
	unsigned numberOfOddElementsHelper(Node* current) const;
	unsigned numberOfEvenElementsHelper(Node* current) const;
	unsigned findMaxHeightHelper(Node* current) const;
	int sumOfElementsHelper(Node* current) const;
	void findByIndexHelper(Node* current, Node*& result, int& index) const;

	bool isBinaryOrderedTreeHelper(Node* current) const;
	bool isBiggerThanElement(Node* current, int data) const;
	bool isSmallerThanElement(Node* current, int data) const;
	bool isSymmetricHelper(Node* currentLeftTree, Node* currentRightTree) const;
	int* createArrayHelper(Node* current) const;

};