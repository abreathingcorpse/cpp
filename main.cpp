#include <iostream>
// This program is to be compiled with the support.cpp, like so:
// $g++ main.cpp support.cpp -o write
int count ;
extern void write_extern();

int main() {
	count = 5;
	write_extern();

	return 0;
}
