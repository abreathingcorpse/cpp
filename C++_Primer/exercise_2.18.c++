#include <iostream>

int main() {

    int i, j; // defined inside of the main function, therefore it's undefined
    std::cout << "i: " << i << ", j: " << j << std::endl;
    int *pi = &i;
    std::cout << "Pointer points to i" << std::endl;
    // Change the value of a pointer (memory address)
    pi = &j;
    std::cout << "Pointer points to j" << std::endl;
    // Change the value to which the pointer points 
    *pi = 4;
    std::cout << "i: " << i << ", j: " << j << std::endl;
    return 0;
}