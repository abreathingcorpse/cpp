#include <iostream>
#include <vector>
using namespace std;

// Consider an actual class.
class Obj {
	static int i, j, x; // The static variables are being shared throughout all of the instances of this class

public:
	void f() const { cout << i++ << endl; } // Constant functions should not be able to modify members, so why does this one work?
	void g() const { cout << j++ << endl; } // Constant functions should not be able to modify members, so why does this one work?

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

	public:
		SmartPointer(ObjContainer& objc) { // ObjContainer& objc should be the reference address to objc
		// cout << "Constructor called." << endl;
		oc = objc;
		index = 0;	
	}

	// Return value indicates end of list:
	bool operator++() { // Prefix version
		if ( index >= oc.a.size() ) return false; // oc has access to a, because of the friend class SmartPointer statement within the ObjContainer class
		if ( oc.a[++index] == 0 ) return false; // Why does this work? Does vector return 0 if trying to access a value outside of its size?
		return true;
	}

	bool operator++(int) { // Postfix version
		return operator++(); // Not sure what does this return. Did nothing got altered here?
	}

	// overload operator ->
	Obj* operator->() const {
		// It looks like index is being increased for some reason
		// cout << "Index: " << index << endl;
		// What is oc.a[index] ?
		//cout << "oc.a[index]" << oc.a[index] << endl; // It is a reference address value from the vector a for a given index
		// Don't understand anything here
		if(!oc.a[index]) {
			cout << "Zero value";	
			return (Obj*)0;
		}	
		
		return oc.a[index]; // This one is straightforward, though. Simply passes the value of a[index]
	}
};

int main() {
	const int sz = 10;
	Obj o[sz]; // This is an array of objects
	ObjContainer oc;

	// Test the const function
	Obj obj_test;
	cout << obj_test.get_x() << endl; // get_x() was actually able to modify the value of x

	for (int i=0; i < sz; i++) {
		//cout << "&o[" << i << "]: " << &o[i] << endl;	
		oc.add(&o[i]); // &o[i] is the reference address
	}
		
	// Calls the constructor of the SmartPointer class
	SmartPointer sp(oc); // Create an iterator
	do {
		// Use the overloaded -> operator
		sp->f(); // smart pointer call
		sp->g();
		//sp->get_x(); // In order for get_x() to be callable, we need to have x defined
	} while (sp++); // Use the ++ operator overload but, which one is it? ++x or x++? It should be x++ only

	return 0;
}
