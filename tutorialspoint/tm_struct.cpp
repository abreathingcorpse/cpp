#include <iostream>
#include <ctime>

using namespace std;

int main() {
	// current date/time based on current system
	time_t now = time(0);

	cout << "Number of sec since January 1, 1970 is:: " << now << endl;
	
	tm *ltm = localtime(&now); // ltm is a pointer, gmtime is receiving the reference (memory address) of now

	// print various components of tm structure.
	// ltm is a pointer, tm_year is a member of the tm struct. In order to access a member of a pointer, you need to use the -> operator	
	cout << "Year:" << 1900 + ltm->tm_year << endl; // years since 1900
	cout << "Month:" << 1 + ltm->tm_mon << endl; // Unix epoch starts at 1970-01-01, perhaps that's why one needs to add 1 month? 
	cout << "Day:" << ltm->tm_mday << endl; 
	cout << "Time:" << 5 + ltm->tm_hour << ":"; // It looks like that's actually not required on my end 
	cout << 30 + ltm->tm_min << ":"; // It looks like that's actually not required on my end
	cout << ltm->tm_sec << endl; 

	cout << "What happens if I do not use the numbers that add to the members?:" << endl;
	cout << "Year:" << ltm->tm_year << endl; // years since 1900 
	cout << "Month:" << ltm->tm_mon << endl; 
	cout << "Day:" << ltm->tm_mday << endl; 
	cout << "Time:" << ltm->tm_hour << ":"; 
	cout << ltm->tm_min << ":"; 
	cout << ltm->tm_sec << endl; 

	cout << "I would be calling it on my system like this:" << endl;
	cout << "Year:" << 1900 + ltm->tm_year << endl; // years since 1900
	cout << "Month:" << 1 + ltm->tm_mon << endl; // Unix epoch starts at 1970-01-01, perhaps that's why one needs to add 1 month? 
	cout << "Day:" << ltm->tm_mday << endl; 
	cout << "Time:" << ltm->tm_hour << ":"; 
	cout << ltm->tm_min << ":"; 
	cout << ltm->tm_sec << endl; 

	return 0;
}
