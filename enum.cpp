#include <iostream>
using namespace std;

int main() {
	// Supposedly enums work the following way:
	// enum enum-name { list of names } var-list;
	// But, what is var-list?
	enum color { red, green, blue } c;
	//std::cout << "color: " << color << endl;
	// Perhaps the line above is not how enums work.
	// Maybe enum-name is like the datatype or a class.
	// See: https://stackoverflow.com/questions/33055248/c-print-an-enum-value
	std::cout << "c: " << c << endl; // It looks like at this point c is trash
	c = blue;
	std::cout << "c is blue: " << c << endl;
	// While at this point c = 2, which is the index of the color iterator
	// But, what is blue?
	std::cout << "blue: " << blue << endl;
	// Apparently, everywhere in the code where I use blue, will have the index within its enum

	return 0;
}
