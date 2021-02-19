#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// class Junction represents the junctions
class Junction {
private:
	// struct Street represents the street
	struct Street {
		std::string name;  // The street has name
		unsigned distance; // It also has a distance from one junction to another

		// constructor for a street
		Street(const std::string& _name, const unsigned distance); 
	};

	std::string name;				// The junction has name
	std::vector<Street> streets;	// It also has vector of streets
	
public:
	// constructors 
	Junction();
	Junction(const std::string& _name);

	// getters 
	std::string getName() const;  // for the name of the junction
	unsigned getDistanceTo(const std::string& junctionName) const; // for the distance of a street to a given junction

	// function which add a street to the vector of streets
	void addStreet(const std::string& nextJunction, const unsigned distance);

	// printing the steet name and distance
	void printStreets(std::ostream& out) const;

	// operator << which allows to display the junctions
	friend std::ostream& operator<<(std::ostream& out, const Junction& data);
}; // end of class Junction