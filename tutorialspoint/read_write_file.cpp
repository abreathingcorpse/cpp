#include <fstream>
#include <iostream>
using namespace std;

int main () {
	char data[10]; // declare a C-style string

	// open a file in write mode.
	ofstream outfile;
	outfile.open("afile.dat");

	cout << "Writing to the file" << endl;
	cout << "Enter your name: "; // Careful: Name shouldn't be bigger than 10
				     // Othewise you'd get the following error:
				     // *** stack smashing detected ***: terminated
				     // Aborted (core dumped)
	// We fill the string
	cin.getline(data, 100); // getline(char* s, streamsize n, char delim = \n)
				// ref: cout << "Writing to the file" << endl;

	// write inputted data into the file.
	outfile << data << endl;

	cout << "Enter your age: ";
	cin >> data;
	cin.ignore(); // Extracts characters from the input sequence and discards them
		      // ref: https://cplusplus.com/reference/istream/istream/ignore/
	// I honestly don't think it does anything here, since the issues that I've seen
	// happen before a getline, which there is no further calll here

	// again write inputted data into the file.
	outfile << data << endl;

	// close the opened file.
	outfile.close();

	// open a file in read mode.
	ifstream infile;
	infile.open("afile.dat");

	cout << "Reading from the file" << endl;
	infile >> data;

	// write the data at the screen.
	cout << "Printing first record." << endl;
	cout << data << endl;

	// again read the data from the file and display it.
	cout << "Gotta call again, so that we print the second record." << endl;
	infile >> data;
	cout << data << endl;

	// close the opened file.
	infile.close();

	return 0;
}
