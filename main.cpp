#include <iostream> // header in the system path
#include "support.h" // header in the working directory

// This program was to be compiled with the support.cpp, like so:
// $g++ main.cpp support.cpp -o write
int count ;
extern void write_extern();

int main() {
	count = 5;
	write_extern();

	return 0;
}
