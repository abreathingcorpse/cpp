#include <iostream>

using namespace std;
void printBook ( struct Books *book );

struct Books {
	string title;
	int book_id;
} amazing_book; // You may define variables which will be of the type struct Books here

int main () {
	struct Books Book1; // Declare Book1 of type Book

	// book 1 specification
	Book1.title = "Learn C++ Programming";
	Book1.book_id = 1;
	
	// amazing book specification
	amazing_book.title = "Les Miserables";
	amazing_book.book_id = 2;

	// Print Book1 info
	cout << "Book 1 title: " << Book1.title << endl;
	cout << "Book 1 id: " << Book1.book_id << endl;
	
	// Print Book1 info
	cout << "Amazing Book title: " << amazing_book.title << endl;
	cout << "Amazing Book id: " << amazing_book.book_id << endl;

	return 0;
}
