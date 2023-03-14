#include <iostream>

int main() {

	std::cout << "Type the couple of numbers that you'd like to multiply:" << std::endl;

	int var1, var2 = 0;

	std::cin >> var1 >> var2;

	std::cout << "The numbers ";
	std::cout << var1;
	std::cout << " * ";
	std::cout << var2 ;
	std::cout << " equals: ";
	std::cout << var1 * var2;
	std::cout << std::endl;

	return 0;
	
}
