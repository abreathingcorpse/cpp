#include <iostream>

using namespace std;
const int MAX = 3;

int main() {
	int var[MAX] = {10, 100, 200}; // Define an array of size 3. Therefore size var[2]

	for( int i = 0; i < MAX; i++ ) {
		cout << "i: " << i << endl;
		*var = i; // *var is the pointer for var[0]. Therefore var[0]=i
		cout << "*var: " << *var << endl;
		cout << "var[0]: " << var[0] << endl;
	}

	*(var + 2) = 500; // We are changing the value of var[2]
	cout << "var[2]: " << var[2] << endl;
	
	return 0;
}
