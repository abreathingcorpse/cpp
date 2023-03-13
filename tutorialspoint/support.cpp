#include <iostream>
// This program is to be compiled with the main.cpp, like so:
// $g++ main.cpp support.cpp -o write
extern int count;

void write_extern(void) {
	std::cout << "Count is " << count << std::endl;
}
