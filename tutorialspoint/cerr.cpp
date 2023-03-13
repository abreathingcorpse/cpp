#include <iostream>

using namespace std;

int main() {
	string error_msg = "Unable to read...";

	// cerr is un-buffered, that means that it prints everything on the screen without waiting for the buffer to be filled or emptied
	cerr << "Error message: " << error_msg << endl; 

	return 1;
}
