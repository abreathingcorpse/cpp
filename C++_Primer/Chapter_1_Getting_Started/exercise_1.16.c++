#include <iostream>

using namespace std;

void sum_integers() {
	int input, sum = 0;

	while(cin >> input)
		sum += input;

	cout << "The final sum is: " << sum << endl;
}

int main() {
	
	sum_integers();	

	return 0;
}
