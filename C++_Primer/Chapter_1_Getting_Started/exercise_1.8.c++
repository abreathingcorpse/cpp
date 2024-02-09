#include <iostream>

/*
 * This won't compile but, it's to verify my answers from exercise_1.8.txt
 */
int main() {
	std::cout << "/*";			// Legal
	std::cout << "*/";			// Legal
//	std::cout << /* "*/" */;		// Not legal
	std::cout << /* "*/" /* "/*" */;	// Legal
	
	return 0;
}
