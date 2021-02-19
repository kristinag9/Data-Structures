#include "Junction.h"

// parametric constructor for the struct Street
Junction::Street::Street(const std::string& _name, const unsigned _distance)
{
	name = _name;			// initialize the name with _name
	distance = _distance;	// initialize the distance with _distance
}

// default constructor for class Junction which initialize the junction with N/A by default
Junction::Junction() : Junction("N/A")
{ }

// parametric constructor for the class Junction
Junction::Junction(const std::string& _name)
{
	name = _name;	// initialize the name with _name
	streets = {};	// initialize the vector with {} -> there aren't any streets in the vector yet
}

// getter for the name of the junction
std::string Junction::getName() const
{
	// just return the name
	return name;
}

// getter for the distance of a street to a given junction
unsigned Junction::getDistanceTo(const std::string& junctionName) const
{
	// for all streets which are in the vector of streets
	for (const Junction::Street& s : streets) {
		// if there is a street to this junction, returns its distance
		if (s.name == junctionName) {
			return s.distance;
		}
	}

	// if there is no street in the vector
	return 0;
}

// add a street to the vector of streets 
void Junction::addStreet(const std::string& nextJunction, const unsigned distance)
{
	// push the name of the next junction and the distance to it
	streets.push_back(Street(nextJunction, distance));
}

// display the information about the streets
void Junction::printStreets(std::ostream& out) const
{
	// for all streets in the vector of streets display their names and distance
	for (const Junction::Street& s : streets) {
		out << '\t' << s.name << ' ' << s.distance << ' ' << '\n';
	}
}

// operator <<
std::ostream& operator<<(std::ostream& out, const Junction& junction)
{
	// display the name of the junction
	out << junction.name << ":\n";
	
	// for all streets in the vector of streets display their names and distance
	for (const Junction::Street& s : junction.streets) {
		out << '\t' << s.name << ' ' << s.distance << '\n';
	}

	// return the result
	return out;
}