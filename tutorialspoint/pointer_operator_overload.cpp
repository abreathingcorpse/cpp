#include <iostream>
#include <vector>
using namespace std;

// Consider an actual class.
class Obj {
	static int i, j, x; // The static variables are being shared throughout all of the instances of this class

public:
	// Apparently you are able to modify a static member if it's defined
	void f() const { cout << i++ << endl; }  
	void g() const { cout << j++ << endl; }  

	// Test the const function, it should not be able to modify the members
	// Apparently you are able to modify a static member if it's defined, though
	int get_x() const {
		x++;
		cout << "x inside the get_x() function: " << x << endl;
		return x;
	}
};

// Static member definitions:
int Obj::i = 10;
int Obj::j = 12;
int Obj::x = 0; // Maybe I need to define it?

// Implement a container for the above class
class ObjContainer {
	vector<Obj*> a; // Think of a Vector as a Python list, except that this one will only hold pointers

	public:
		void add(Obj* obj) {
			a.push_back(obj); // call vector's standard method
			// Think of push_back as Python's append() method
		}

		// This statement declares all member functions of the SmartPointer class as friends
		// In other words, its methods will have access to all private and protected members of this class
		friend class SmartPointer; 
};

// implement smart pointer to access member of Obj class.
class SmartPointer {
	ObjContainer oc;
	int index;
	int test_int; // Figuring out if all integers will advance by one whenever the ++ operator is called

	public:
		SmartPointer(ObjContainer& objc) { // ObjContainer& objc should be the reference address to objc
		// cout << "Constructor called." << endl;
		oc = objc;
		index = 0;	
		test_int = 0;	
	}
		// Trying to figure out why is index increased
		int get_index() {
			return index;
		}
		int get_test_int() {
			return test_int;
		}

	// Return value indicates end of list:
	bool operator++() { // Prefix version
		// cout << "++ Prefix version overload called." << endl;
		// cout << "Beginning of the ++ overload. index:  " << index << endl; 
		// cout << "index: " << index <<  " vs oc.a.size()" << oc.a.size() << endl; 
		// cout << "++index: " << ++index <<  " vs oc.a[index]" << oc.a[index] << endl; 
		// sp has access to oc, because it's given on its constructor
		if ( index >= oc.a.size() ) {
			cout << "Inside the first if statement. index: " << index << endl; 
			return false;
		}
		// Why does this work? Does vector return 0
		// if trying to access a value outside of its size?
		if ( oc.a[++index] == 0 ) { 
		// The test is always called and ++index = index + 1 (don't forget the assignment)
			cout << "Inside the second if statement. index: " << index << endl; 
			return false; 
		}
		// cout << "End of the ++ overload. index:  " << index << endl; 
		return true;
	}

	// When calling the Postfix version, you are actually calling the Prefix version
	bool operator++(int) { // Postfix version
		// cout << "++ Postfix version overload called." << endl;
		return operator++();  
	}


	// overload operator ->
	Obj* operator->() const {
		// It looks like index is being increased for some reason
		// cout << "index inside the -> operator overload: " << index << endl;

		// What is oc.a[index] ?
		// It is a reference address value from the vector a for a given index
		// cout << "oc.a[index]: " << oc.a[index] << endl; 
		// Trying to understand what happens when the index is
		// It looks like the reference address is 0 out of bounds
		// cout << "oc.a[10+index]: " << oc.a[10+index] << endl; 

		if(!oc.a[index]) {
			cout << "Zero value" << endl;	
			return (Obj*)0; // This is a C-style cast. We are casting 0 as an Obj*
		}	
		
		return oc.a[index]; // Passes the reference value of a[index]
	}
};

int main() {
	const int sz = 10;
	Obj o[sz]; // This is an array of objects
	ObjContainer oc;

	// Test the const function
	/* Obj obj_test;
	cout << obj_test.get_x() << endl; */ // get_x() was actually able to modify the value of x, once x was defined

	// Test NULL pointer
	/* Obj* test_null_pointer = (Obj*)0;
	cout << "null pointer: " << test_null_pointer << endl;

	ObjContainer null_oc;
	null_oc.add(test_null_pointer);
	SmartPointer null_sp(null_oc);
	null_sp->f(); */

	for (int i=0; i < sz; i++) {
		//cout << "&o[" << i << "]: " << &o[i] << endl;	
		oc.add(&o[i]); // &o[i] is the reference address
	}

	// Calls the constructor of the SmartPointer class
	SmartPointer sp(oc); // Create an iterator
	do {
		// I'm trying to figure out why the index increased
		// cout << "sp.index: " << sp.get_index() << endl;
		// cout << "sp.test_int: " << sp.get_test_int() << endl;
		// Use the overloaded -> operator
		sp->f(); // smart pointer call
		sp->g();
	} while (sp++); // Use the ++ operator overload but, which one is it? ++x or x++? It should be x++ only 

	return 0;
}
