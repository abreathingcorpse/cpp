#include <iostream>
#include "Sales_item.h"

int main() {

	Sales_item book1, book2;
	
	std::cin >> book1 >> book2;

	if ( book1.isbn() == book2.isbn() )
		std::cout << "The sum of the two transactions is:"  << std::endl
			  << book1 + book2 << std::endl;
	else
		std::cout << "The ISBN code for both transactions is not the same." << std::endl;

	return 0;
}
