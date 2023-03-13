#include <iostream>
using namespace std;

int main () {
	double* pvalue = NULL; // Pointer initialized with null
	cout << "pvalue should be null: " << pvalue << endl;

	// Request memory for the variable
	// Good practice: Check if the memory has been allocated successfuly
	if ( !(pvalue = new double)) { // There's an assignment here, so this does take place
				       // This is similar to the ++index on the pointer_operator_overload.cpp
		cout << "Error: out of memory." << endl;
		exit(1);
	}
	cout << "pvalue after the memory request:  " << pvalue << endl;

	*pvalue = 29494.99; // Store value at allocated adderss
	cout << "Value of pvalue: " << *pvalue << endl;

	delete pvalue; // free up the memory.

	return 0;
}
