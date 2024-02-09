#include <iostream>

int main() {

	int sum = 0;

	// Rewrite for exercise 1.9
	for(int i = 50; i <= 100; ++i)
		sum += i;

	std::cout << "Sum of 50 to 100 inclusive is: " << sum << std::endl;

	// Rewrite for exercise 1.10
	for(int i = 10; i >= 0; --i)
		std::cout << i << std::endl;

	return 0;
}
