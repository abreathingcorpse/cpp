#include <iostream>
using namespace std;

// first name space
namespace first_space {
	void func() {
		cout << "Inside the first_space" << endl;
	}

	// second name space
	namespace second_space {
		void func() {
			cout << "Inside second_space" << endl;
		}
	}
}

// using namespace first_space::second_space; // func belongs to the second_space
// using namespace first_space; // One has access to the second_space as well second_space::func()

int main () {
	// This calls function from second name space.
	// func();

	// When using first_space
	// func();
	// second_space::func();

	// Without using any namespace
	first_space::func();
	first_space::second_space::func();

	return 0;
}
