#include <iostream>
#include "Sales_item.h"

int main() {
	
	Sales_item book, currentBook;

	// Most of this process has been taken from the exercise 1.18

	if (std::cin >> currentBook) {

		int count = 1;

		while(std::cin >> book) {
			if (currentBook.isbn() == book.isbn())
				count++;
			else {
				std::cout << "The count for " << currentBook.isbn() << " is: "
					  << count << std::endl;
				currentBook = book;
				count = 1;
			}
		} // while cin>>book
		std::cout << "The count for " << currentBook.isbn() << " is: "  << count
			  << std::endl;

	} // if cin>>currentBook

	return 0;
}
