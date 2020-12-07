#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <deque>

class NTree {
private:
	struct Node {
		int data;
		std::vector<Node*> children;

		Node(int _data);
	};

	Node* root;
	void clear(Node* current);
	Node* copy(Node* current);

	bool addElementHelper(Node*& current, const char* path, const int element);
	bool containsElement(Node* current, const int element) const;
	bool isChildOfHelper(Node* current, const int father, const int child) const;

	int sumHelper(Node* current) const;
	int findMaxElementHelper(Node* current) const;
	unsigned countElementsHelper(Node* current) const;
	unsigned findMaxHeightHelper(Node* current) const;

	void printHelper(std::ostream& out, Node* current) const;
	void printChildrenHelper(Node* current, const int data) const;
	void elementsOnKLevelHelper(Node* current, unsigned level) const;
	void printNeighboursHelper(Node* current, const int data, unsigned& level) const;
	void countSumEqualsToGrandfatherHelper(Node* current, unsigned& counter) const;

public:
	NTree();
	NTree(const NTree& other);
	NTree& operator=(const NTree& other);
	~NTree();

	bool addElement(const char* path, const int element);
	bool contains(const int element) const;
	bool isChildOf(const int father, const int child) const;

	int sum() const;
	int findMaxElement() const;
	unsigned countElements() const;
	unsigned findMaxHeight() const;
	unsigned countSumEqualsToGrandfather() const;

	void print(std::ostream& out) const;
	void printChildren(const int data) const;
	void elementsOnKLevel(unsigned level) const;
	void printDFS() const;
	void printBFS() const;
	void printNeighbours(const int data) const;
};

