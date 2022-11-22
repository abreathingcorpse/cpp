#include <iostream>
#include <string>

template <class Derived>
class Equality {};

template <class Derived>
bool operator == (Equality<Derived> const& op1, Equality<Derived> const& op2) {
	Derived const& d1 = static_cast<Derived const&>(op1);
	Derived const& d2 = static_cast<Derived const&>(op2);
	return !(d1 < d2) && !(d2 < d1);
}

template <class Derived>
bool operator != (Equality<Derived> const& op1, Equality<Derived> const& op2) {
	Derived const& d1 = static_cast<Derived const&>(op1);
	Derived const& d2 = static_cast<Derived const&>(op2);
	return !(op1 == op2);
}

struct Apple : public Equality<Apple>{
	Apple(int s): size{s}{};
	int size;
};

bool operator < (Apple const& a1, Apple const& a2) {
	std::cout << "Inside the < operator overload." << std::endl;
	std::cout << "a1.size: " << a1.size << std::endl;
	std::cout << "a2.size: " << a2.size << std::endl;
	return a1.size < a2.size;
}

struct Man : public Equality<Man> {
	Man(std::string n): name{n}{};
	std::string name;
};

bool operator < (Man const& m1, Man const& m2) {
	return m1.name < m2.name;
}

int main(){
	// With boolalpha the booleans are printed as true/false instead of 0/1
	// ref: https://cplusplus.com/reference/ios/boolalpha/ 
	std::cout << std::boolalpha << std::endl;

	Apple apple1{10};
	Apple apple2{5};
	std::cout << "apple1 == apple2: " << (apple1 == apple2) << std::endl;

	Man man1{"grimm"};
	Man man2{"jaud"};
	std::cout << "man1 != man2: " << (man1 != man2) << std::endl;

	std::cout << std::endl;
}
