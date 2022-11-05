#include <iostream>
#include <limits>
using namespace std;

int main() {
	std::cout << "Int Min " << std::numeric_limits<int>::min() << endl;
	std::cout << "Unsigned Int Max " << std::numeric_limits<unsigned int>::max() << endl;
	std::cout << "Long Int Max " << std::numeric_limits<long int>::max() << endl;
	std::cout << "Unsigned Long Int Max " << std::numeric_limits<unsigned long int>::max() << endl;

	return 0;
}
