#include <iostream>
using namespace std;

double division (int a, int b) {
	if (b==0) {
		throw "Division by zero condition!"; // Why is this of type const char*?
	}

	// Testing if all throw strings go to the same place
	if (a==b) {
		throw "I mean, you should know the answer...";
	}

	// Testing what happens with integers
	if (a % b == 0) {
		throw 0;
	}

	return (a/b);
}

int main () {
	int x=25;
	int y=50;
	double z=0;
	
	try {
		z = division(x,y);
		cout << z << endl;
	} catch (const char* msg) { // This can't be of type char* alone
				    // When the throw took place it tells me its of type char const*
		cerr << msg << endl;
	} catch (const int err_code) { // What's the type for thrown integers?
		cout << "Error Code:" << endl; // This isn't called
		cerr << err_code <<endl;
	}

	return 0;
}
