#include "Graph.h"

// constructor for the struct Node
Graph::Node::Node(const Junction& _data)
{
	data = _data;  // initialize data with _data
	children = {}; // initialize the vector of children with the empty vector
}

// function which clears the elements from the graph using depth-first search
void Graph::clear(Graph::Node* current) 
{
	std::stack<Node*> frontier;		// declare a stack with nodes - junctions
	std::set<std::string> visited;  // set for the visited nodes which contains unique elements only

	// push the current junction in the stack
	frontier.push(current); 

	// while the stack is not empty
	while (!frontier.empty()) {
		Node* topElement = frontier.top(); // take the first element from the stack and pop it
		frontier.pop();

		// if there is such element in the set, delete the taken element and return
		if (visited.count(topElement->data.getName()) == 1) {
			delete topElement;
			topElement = nullptr;
			return;
		}

		// look at the children 
		for (Node* node : topElement->children) {
			frontier.push(node);
		}

		// insert the unique elements in the set
		visited.insert(topElement->data.getName());
	}
}

// helper function for writing the graph in the file using breadth-first search
bool Graph::writeHelper(Node* current, std::ostream& out) const
{
	std::queue<Node*> frontier;		// declare a queue for the elements
	std::set<std::string> visited;  // set for the visited nodes which contains only unique elements 

	// push the current junction in the queue
	frontier.push(current); 

	// while the queue is not empty
	while (!frontier.empty()) {
		Node* frontElement = frontier.front(); // take the first element from the queue and pop it
		frontier.pop(); 

		// if the name of the junction has already been read, we just skip it, beacause we don not want to have duplicate names
		if (visited.count(frontElement->data.getName()) == 1) {
			continue;
		}

		// if the data cannot be written, return false
		if (!(out << frontElement->data)) {
			return false;
		}

		// look at the children
		for (Node* node : frontElement->children) {
			if (visited.count(node->data.getName()) == 0) { // if the current node is not in the set, add it to the frontier
				frontier.push(node);
			}
		}

		// insert the elements in the set, making it visited
		visited.insert(frontElement->data.getName());
	}

	return true;
}

// a check if there is a junction with name junctionName in the graph using breadth-first search
bool Graph::find(Node* current, const std::string& junctionName, Node*& toAssign) const
{
	std::queue<Node*> frontier;		 // contains all nodes
	std::set<std::string> visited;   // contains only the visited ones

	// push the current element in the junction
	frontier.push(current);

	// while thare are elements in the queue
	while (!frontier.empty()) {
		Node* frontElement = frontier.front(); // take the first element and then remove it from the queue
		frontier.pop();

		// if frontElement name is equal to the name of the given junction => we found it => return true
		if (frontElement == nullptr || frontElement->data.getName() == junctionName) {
			toAssign = frontElement;
			return true;
		}

		// else look at the children
		for (Node* node : frontElement->children) {
			if (visited.count(node->data.getName()) == 0) { // if the set does not contain such element => push it in the queue
				frontier.push(node);
			}
		}

		// insert the element in the set and make it visited
		visited.insert(frontElement->data.getName());
	}

	return false;
}

// find all pairs of street names, made up of the names of the junctions and save them in the vector result
// using breadth-first search
void Graph::crossproduct(std::vector<PathPair>& result) const
{
	std::queue<Node*> frontier;     // the queue contains all nodes
	std::set<std::string> visited;  // the set contains only the unique ones which are visited

	// push the current element in the queue
	frontier.push(start);

	// while the queue is not empty
	while (!frontier.empty()) {
		Node* frontElement = frontier.front(); // take the first pair from the queue and pop it
		frontier.pop();

		// use the current element => push it in the vector, making a new Pair from its name and it children name
		for (Node* node : frontElement->children) {
			result.push_back(PathPair({ frontElement->data.getName(), node->data.getName() }, 0));
		}

		// look in the children
		for (Node* node : frontElement->children) {
			if (visited.count(node->data.getName()) == 0) { // if the set doesn't contain this element, push it in the queue
				frontier.push(node);
			}
		}

		// add the element in the set, making it visited
		visited.insert(frontElement->data.getName());
	}
}

// find all pairs of street names, made up of the names of the junctions and save them in the vector result
void Graph::getVertices(std::vector<std::string>& junctions) const
{
	std::queue<Node*> frontier;    // contains all of the elements
	std::set<std::string> visited; // contains only the unique ones

	// push the current element in the queue
	frontier.push(start);

	// while the queue is not empty
	while (!frontier.empty()) {
		Node* frontElement = frontier.front(); // take the first element from the queue and pop it
		frontier.pop();

		junctions.push_back(frontElement->data.getName()); // add the current element in the vector

		// then, do it for the children
		for (Node* node : frontElement->children) {
			if (visited.count(node->data.getName()) == 0) { // if there is not such element, add it to the queue
				frontier.push(node);
			}
		}

		// add the elements in the set, making them visited
		visited.insert(frontElement->data.getName());
	}
}

// helper function for hasPath which checks if there is a path to a given junction
bool Graph::hasPathHelper(Node* current, const std::string& secondJunction) const
{
	std::queue<Node*> frontier;		// contains all nodes
	std::set<std::string> visited;  // contains only the visited ones

	// push the current element in the queue
	frontier.push(current);

	// while thare are elements in the queue
	while (!frontier.empty()) {
		Node* frontElement = frontier.front(); // take the first element from the queue and remove it from the frontier
		frontier.pop();

		// for all junctions of the vector of children
		for (Node* node : frontElement->children) {
			// if the name of the junction is found it means that there is a path
			if (node->data.getName() == secondJunction) {
				return !(visited.size() == 0 && frontier.empty() && node->data.getName() == frontElement->data.getName());
			}

			// if the set does not contain such element, push it in the queue
			if (visited.count(node->data.getName()) == 0) { 
				frontier.push(node);
			}
		}

		// insert the elements in the set and make them visited
		visited.insert(frontElement->data.getName());
	}

	return false;
}

// helper function which prints the streets which are dead-end
void Graph::deadEndStreetHelper(Node* current) const
{
	bool foundStreetNotDeadEnd = false;  // if the flag is false, there is a dead-end street
	std::queue<Node*> frontier;		     // the queue contains all of the elements in the graph
	std::set<std::string> visited;	     // the set is for the unique elements only

	// push the current element in the queue
	frontier.push(current);

	// while there are elements in the queue
	while (!frontier.empty()) {
		Node* frontElement = frontier.front(); // take the first one and pop it
		frontier.pop();

		// use the current element => if it doesn't have any children, it means that the street is dead-end => print it
		if (frontElement->children.empty()) {
			std::cout << "All streets ending in " << frontElement->data.getName() << " are dead-end.\n";
		}
		else if (foundStreetNotDeadEnd == false){ // else there is a street that is not dead-end and flag is true
			foundStreetNotDeadEnd = true;
		}

		// look at the other junctions in the graph
		for (Node* node : frontElement->children) {
			if (visited.count(node->data.getName()) == 0) { // if the set doesn't contain this element, push it in the queue
				frontier.push(node);
			}
		}

		// add the element in the set and make it visited
		visited.insert(frontElement->data.getName());
	}

	// if flag is true, there aren't any dead-end streets
	if (foundStreetNotDeadEnd) {
		std::cout << "There aren't any dead-end streets in the graph!\n";
	}
}

// class Compare creates a custom predicate the path pairs can be compared
class Compare {
public:
	// operator which compairs the pairs
	bool operator()(const PathPair& lhs, const PathPair& rhs) const {
		return lhs.second > rhs.second;
	}
};

// helper function which finds all paths from one junction to another
// using uniform-cost search because it uses total path cost
void Graph::allPaths(Node* startJunction, Node* finalJunction) const
{
	std::stack<PathPair> frontier;     // create a stack which contains all path pairs 
	std::priority_queue<PathPair, std::vector<PathPair>, Compare> resultPaths; // use priority_queue because we want the pair paths to be sorted, starting with the best one

	// push the current pair with the name is startJunction and its distance which is 0
	frontier.push(PathPair({ startJunction->data.getName() }, 0));

	// while the queue is not empty
	while (!frontier.empty()) {
		PathPair frontElement = frontier.top(); // take the first path pair from the stack and pop it
		frontier.pop();

		const unsigned lengthOfTopPath = frontElement.first.size();			// take the length of the top path
		std::string currentPath = frontElement.first[lengthOfTopPath - 1];	// take the last element from the frontElement which is the first path

		// if this element is the name of the goal junction, it means that this is one path to it and push it in the queue
		if (currentPath == finalJunction->data.getName()) {
			resultPaths.push(frontElement);
		}
		else { // else this is not a path to this junction and so take this path' first element and look at its children
			Node* current = start; // pointer to the beginnig of the current path

			// check if the the junction is not in the graph
			if (!find(start, currentPath, current)) {
				std::cout << "allPaths cannot find " << currentPath << '\n';
				return;
			} // else it is in the graph

			// for all junctions in the vector of children of the current path
			for (Node* node : current->children) {
				std::string nameOfNextJunction = node->data.getName(); // take the name of the next junction

				// if the junction is closed, we skip it
				if (closedJunctions.count(node->data.getName()) == 1) {
					continue;
				}

				// take the distance from the current junction to the next one
				unsigned currentNextDistance = current->data.getDistanceTo(nameOfNextJunction);

				frontElement.first.push_back(nameOfNextJunction); // push the name of the next junction in the pair as first element
				frontElement.second += currentNextDistance;		  // increase the distance adding the distance from the current junction to the next one

				bool duplicatePaths = false;
				for (int i = 0; i < lengthOfTopPath - 1 && duplicatePaths == false; ++i) {
					for (int j = i + 1; j < lengthOfTopPath && duplicatePaths == false; ++j) {
						// if the path already exists in the PathPair, we do not add it in the stack again
						if (frontElement.first[i] == frontElement.first[j]) {
							duplicatePaths = true;
						}
					}
				}
				if (duplicatePaths == false) { // else if the path is not in the stack, we add it 
					frontier.push(frontElement);
				}

				// so, we already look at all children of this path and that's why we pop it from the current path and make the distance as it was 
				frontElement.first.pop_back();
				frontElement.second -= currentNextDistance;
			}
		}
	}

	// printing the paths

	// the number of path which we want to display
	unsigned numberOfPaths = 0;

	// while there are elements in the queue and we want 3 best paths
	while (!resultPaths.empty() && numberOfPaths < 3) {
		// take the first pair from the queue and pop it
		PathPair pair = resultPaths.top();
		resultPaths.pop();

		// display all junction from the pair
		for (const std::string& junction : pair.first) {
			std::cout << junction << ' ';
		}

		// total path cost is the distance 
		std::cout << "with total path cost: " << pair.second << '\n';

		// increase the numberOfPaths 
		++numberOfPaths;
	}
}

// default constructor for the Graph
Graph::Graph()
{
	start = nullptr;      // initialize the start with nullptr
	closedJunctions = {}; // initialize the vector of closed junctions with the empty vector
}

// destructor for the Graph
Graph::~Graph() {
	clear(start);
}

// function which reads the graph from a given file
bool Graph::read(const std::string& filename)
{
	std::ifstream fin(filename);	  // create an object of type ifstream with the filename

	// if the file cannot be read, display a message and return false
	if (!fin) {
		std::cout << "Couldn't open file!\n";
		return false;
	}

	Node* workingJunction = start;    // pointer to the start of the graph with which we will work
	std::string currentJunction = ""; // string with the name of the current junction

	// while we can read from the file
	while (fin) {
		char c = fin.peek(); // take the next symbol

		// if we can continue reading
		if (fin) {
			// if the currentJunction cannot be read, return false
			if (!(fin >> currentJunction)) {
				return false;
			}
			fin.get(c); // take the other symbols of the name of the junction

			// if there is no such junction
			if (find(start, currentJunction, workingJunction) == false) {
				// if junction name starts with "Closed:", we need to read the closed junctions
				if (currentJunction == "Closed:") {
					while (fin && c != '\n') {
						// if the currentJunction cannot be read, return false
						if (!(fin >> currentJunction)) {
							std::cout << "Couldn't read next junction!\n";
							return false;
						} 
						// else insert the juntion in the set of closed junctions and read the next symbols
						closedJunctions.insert(currentJunction);
						fin.get(c);
					}
					return true;
				}
				return false;
			}

			// if there is no root, create a new node with the currentJunction and currentJunction now is the start
			if (start == nullptr) {
				start = new Node(Junction(currentJunction));
				workingJunction = start;
			}

			if (!fin) {
				return true;
			}
			else if (c == '\n') { // if there is a new line, we start with no junctions
				currentJunction = "";
			}
			else if (c == ' ') { // if there is a space, read new junction and the distance, then add a new street
				while (fin && fin.peek() != '\n') { // while we can read from the file and the next symbol is not a new line
					std::string nextJunction = "";
					unsigned distance;

					// read the next junction and the distance
					if (!(fin >> nextJunction >> distance)) {
						if(!fin) {
							return true;
						}
						return false;
					}

					Node* ptrNextJunction = start; // pointer to the next junction
					
					// if the nextJunction is not in the graph, create a new Node with its name and then push it into the children of workingJunction
					if (!find(start, nextJunction, ptrNextJunction)) {
						workingJunction->children.push_back(new Node(Junction(nextJunction)));
					} else {
						workingJunction->children.push_back(ptrNextJunction); // else just push the pointer to the next junction
					}

					workingJunction->data.addStreet(nextJunction, distance); // finally, add a street between the junctions
				}
			}
			else { // if there is an invalid symbol and we cannot read it, display a message for error
				std::cout << "Error! Invalid symbol!\n";
				return false;
			}
		}
	}

	// close the file and return true
	fin.close();
	return true;
}

// function which write a graph in a file
bool Graph::write(std::ostream& out) const
{
	// call the helper function
	return writeHelper(start, out);
}

// function hasPath which checks if there is a path between two given junctions
bool Graph::hasPath(const std::string& firstJunction, const std::string& secondJunction) const
{
	// if there is a closed junction between them, there cannot be a path from it
	if (closedJunctions.count(firstJunction) == 1 || closedJunctions.count(secondJunction) == 1) {
		std::cout << "Cannot construct path! One of the junctions is closed!\n";
		return false;
	}

	// pointers to the start for the junctions
	Node* startJunction = start;
	Node* sndStartJunction = start;

	// check if firstJunction exists
	if (!find(start, firstJunction, startJunction)) {
		std::cout << "Couldn't find " << firstJunction << '\n';
		return false;
	} 

	// check if secondJunction exists
	if (!find(start, secondJunction, sndStartJunction)) {
		std::cout << "Couldn't find " << secondJunction << '\n';
		return false;
	}

	// if there is a path between first and second junction and between second and first junction (two-way street)
	return hasPathHelper(startJunction, secondJunction) || hasPathHelper(sndStartJunction, firstJunction);
}

// function which finds the best three paths from the first given junction to the second one
void Graph::findBestThree(const std::string& firstJunction, const std::string& secondJunction) const
{
	// there cannot has a path between one junction
	if (firstJunction == secondJunction) {
		std::cout << "Invalid arguments. Expected two different junctions. Got: " << firstJunction << '\n';
		return;
	}

	// if there is a closed junction between them, there cannot be a path from it
	if (closedJunctions.count(firstJunction) == 1 || closedJunctions.count(secondJunction) == 1) {
		std::cout << "Cannot construct path! One of the junctions is closed!\n";
		return;
	}

	// pointers to the start for the junctions
	Node* startJunction = start;
	Node* secondStart = start;

	// check if the first junction doesn't exist in the graph
	if (!find(start, firstJunction, startJunction)) {
		std::cout << "Couldn't find " << firstJunction << '\n';
		return;
	}

	// check if the second junction doesn't exist in the graph
	if (!find(start, secondJunction, secondStart)) {
		std::cout << "Couldn't find " << secondJunction << '\n';
		return;
	}

	// call the helper function 
	allPaths(startJunction, secondStart);
}

// function hasCycle which checks if there is a cycle in the graph
bool Graph::hasCycle(const std::string& junctionName) const
{
	// if there is a path from one junction to this junction, going through the other junctions => there is a cycle
	return hasPath(junctionName, junctionName);
}

// function hasTouristPath which checks if there is an Eulirian cycle in the graph
bool Graph::hasTouristPath() const
{
	std::vector<PathPair> crossprod; // this vector contains all possible pairs with names of the streets in the graph
	crossproduct(crossprod);	 

	std::queue<Node*> frontier;    // create a queue for the elements in the graph
	std::set<std::string> visited; // create a set for the visited ones

	// push the current element in the queue
	frontier.push(start);

	// while the queue is not empty
	while (!frontier.empty()) {
		unsigned degree = 0;  // degree of Vertex => shows the edges that enter and go out from a vertex
		Node* frontElement = frontier.front(); // take the first element from the queue and pop it
		frontier.pop();

		// use the current element => for each pair of names =>
		for (PathPair p : crossprod) {
			const unsigned lengthOfTopPath = p.first.size();			// take the length of the top path
			// if the first part of the name contains the name of the frontElement or it the last part of the name contains it => there is an edge => degree++
			//if (p.first = frontElement->data.getName() || p.second = frontElement->data.getName()) {
			//	degree++;
			//}
			for (int i = 0; i < lengthOfTopPath - 1; ++i) {
				for (int j = i + 1; j < lengthOfTopPath; ++j) {
					// if the path already exists in the PathPair, we do not add it in the stack again
					if (p.first[i] == frontElement->data.getName() || p.first[j] == frontElement->data.getName()) {
						degree++;
					}
				}
			}
			p.first.pop_back();
		}

		// if the degree is odd => there is not an Eulirian cycle
		if (degree % 2 != 0) {
			return false;
		}

		// then, look through the children 
		for (Node* node : frontElement->children) {
			if (visited.count(node->data.getName()) == 0) {
				frontier.push(node);
			}
		}

		// insert the visited element in the set
		visited.insert(frontElement->data.getName());
	}

	return true;
}

// function reachJunction which checks if one junction can reach the other ones
bool Graph::reachJunction(const std::string& junctionName) const
{
	// if there is a closed junction between them, there cannot be a path from it
	if (closedJunctions.count(junctionName) == 1) {
		std::cout << "Cannot construct path! The junction is closed!\n";
		return false;
	}

	Node* startJunction = start;

	// check if there is a junction in the graph with the given name
	if (!find(start, junctionName, startJunction)) {
		std::cout << "Couldn't find " << junctionName << '\n';
		return false;
	}

	std::vector<std::string> allJunctions; // this vector contains all junctions + the start one
	getVertices(allJunctions);             // get all junctions

	// for each junction name from allJunctions
	for (const std::string& s : allJunctions) {
		// if startJunction.name is different from the given name and there is no path between startJunction and the given one => return false
		if (startJunction->data.getName() != s && !hasPathHelper(startJunction, s)) {
			return false;
		}
	}

	// there is path between the given junction and all of the others
	return true;
}

// function deadEndStreet which checks if there are any dead-end streets in the graph
void Graph::deadEndStreet() const
{
	// call the helper function
	deadEndStreetHelper(start);
}
