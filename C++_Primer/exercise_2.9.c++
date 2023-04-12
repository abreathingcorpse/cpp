#include <iostream>

int main() {

	
//	std::cin >> int input_value; Error: Expected primary-expression before int.
	int input_value;
	std::cin >>  input_value;
	std::cout << input_value << std::endl;	

//	int i = { 3.14 }; Error: narrowing conversion from double to int
//	std::cout << i << std::endl;	

//	double salary = wage = 9999.99;
	double wage = 9999.99, salary = wage;
	std::cout << salary <<  std::endl;	
	
	int i = 3.14;
	std::cout << i << std::endl;	

	return 0;
}
