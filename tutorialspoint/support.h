#include <iostream>
// This is a header file, so it's to be taken by the main.cpp during compilation automatically

extern int count;

void write_extern(void) {
	std::cout << "Count is " << count << std::endl;
}
