#include <iostream>

using namespace std;

class Line {
	public:
		int getLength( void );
		Line( int len ); // simple constructor
		Line( const Line &obj ); // copy constructor
		~Line(); // destructor
	private:
		int *ptr; // pointer to an int
};

// Member functions definitions including constructor
// The :: operator is used to define a function outside a class
Line::Line(int len) {
	cout << "Normal constructor allocating ptr" << endl;
	cout << "We are inside the normal constructor. len: " << len << endl;
	
	// allocate memory for the pointer;
	ptr = new int;
	cout << "We are inside the normal constructor. ptr: " << ptr << endl;
	*ptr = len;
	cout << "We are inside the normal constructor. *ptr: " << *ptr << endl;
}

Line::Line(const Line &obj) {
	cout << "Copy constructor allocating ptr." << endl;
	cout << "We are inside the copy constructor. &obj: " << &obj << endl;
	ptr = new int;
	cout << "We are inside the copy constructor. ptr: " << ptr << endl;
	*ptr = *obj.ptr; // copy the value
	cout << "We are inside the copy constructor. *ptr: " << *ptr << endl;
}

Line::~Line(void) {
	cout << "Freeing memory!" << endl;
	delete ptr;
}

int Line::getLength( void ) {
	return *ptr;
}

// When an object of a class is passed to a function by value as an argument, the copy constructor is called
void display(Line obj) {
	cout << "Called display(Line obj)" << endl;
	cout << "Length of line: " << obj.getLength() << endl;
}

// Main function for the program
int main() {
	Line line(10);

	cout << "We are inside the main function. &line: " << &line << endl;

	display(line); // The copy constructor is called here

	return 0;
}
