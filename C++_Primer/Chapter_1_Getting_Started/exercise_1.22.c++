#include <iostream>
#include "Sales_item.h"

int main() {

	Sales_item book, sum;

	while (std::cin >> book) {
		sum += book;	
	}	

	std::cout << sum << std::endl;

	return 0;
}
