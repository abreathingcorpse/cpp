#include <iostream>

int main() {

	std::cout << "Type the couple of numbers that you'd like to multiply:" << std::endl;

	int var1, var2 = 0;

	std::cin >> var1 >> var2;

	std::cout << "The numbers " << var1 << " * " << var2 << " equals: " << var1 * var2
		  << std::endl;

	return 0;
	
}
