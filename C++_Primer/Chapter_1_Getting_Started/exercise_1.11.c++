#include <iostream>

int main() {

	// Declare the values, val3 is only required if val1 > val2, in order to swap them up
	int val1, val2, val3;

	std::cout << "Please type the two integers you'd like to print a range of: " << std::endl;

	// Request the two range values
	std::cin >> val1 >> val2;

	// Swap the values if val1 > val2
	if(val1>val2) {
		val3 = val2;
		val2 = val1;
		val1 = val3;
	}

	// Print the range values on the screen
	while(val1 <= val2) {
		std::cout << val1 << std::endl;
		++val1;
	}

	return 0;
}
