#pragma once
#include "Junction.h"
#include <queue>
#include <set>
#include <stack>

// assign alternative name to datatype pair
typedef std::pair<std::vector<std::string>, unsigned> PathPair;

// class Graph represents the graph which contains junctions and streets between them
class Graph {
private:

	// struct Node represents one element from the graph
	struct Node {
		Junction data;    // it contains data for the junction which has name and vector of streets
		std::vector<Node*> children; // and also a vector of children

		// constructor for the struct Node
		Node(const Junction& _data);
	};

	Node* start;   // pointer to the start element of the graph
	std::set<std::string> closedJunctions; // set of closed junctions 

	// ---------------------- helper functions -------------------------------//

	// function which clears the elements from the graph
	void clear(Node* current); 
	// helper function for writing the graph in the file
	bool writeHelper(Node* current, std::ostream& out) const; 
	// a check if there is a junction with name junctionName in the graph
	bool find(Node* current, const std::string& junctionName, Node*& toAssign) const; 
	// get all junction names (the vertices in the graph)
	void getVertices(std::vector<std::string>& junctions) const;
	// find all pairs of street names, made up of the names of the junctions and save them in the vector result
	void crossproduct(std::vector<PathPair>& result) const; 
	// helper function for hasPath which checks if there is a path to a given junction
	bool hasPathHelper(Node* current, const std::string& secondJunction) const; 
	// helper function which prints the streets which are dead-end
	void deadEndStreetHelper(Node* current) const; 
	// helper function which finds all paths from one junction to another
	void allPaths(Node* startJuntion, Node* finalJunction) const;
public:
	Graph();   	// constructor for the graph
	~Graph();   // destructor for the graph

	// function which reads the graph from a given file
	bool read(const std::string& filename);
	// function which write a graph in a file
	bool write(std::ostream& out) const;
	// function hasPath which checks if there is a path between two given junctions
	bool hasPath(const std::string& firstJunction, const std::string& secondJunction) const;
	// function which finds the best three paths from the first given junction to the second one
	void findBestThree(const std::string& firstJunction, const std::string& secondJunction) const;
	// function hasCycle which checks if there is a cycle in the graph
	bool hasCycle(const std::string& junctionName) const;
	// function hasTouristPath which checks if there is an Eulirian cycle in the graph
	bool hasTouristPath() const;
	// function reachJunction which checks if one junction can reach the other ones
	bool reachJunction(const std::string& junctionName) const;
	// function deadEndStreet which checks if there are any dead-end streets in the graph
	void deadEndStreet() const;
}; // end of class Graph