#include "Sieve.h"
using namespace std;

int main() {
	// Sieve class exemplary usage:

	// constructor:
	int endingNumber{ 1000 };
	Sieve<int> sieve(endingNumber);

	cout << "There are " << sieve.countPrimes() << " prime numbers from 1 to " << endingNumber << "." << endl;

	// to extract primes from the object use getPrimes:
	auto primes = sieve.getPrimes(); // std::list<int> int this example

	// to save the result in a file use saveToFile:
	string filename("primes.txt");
	if (sieve.savePrimesToFile(filename)) {
		cout << "The file was saved successfully." << endl;
	}
	else {
		cout << "Error while saving to a file..." << endl;
	}

	// to print the primes to stdout use printPrimes with std::cout or operator<<
	//sieve.printPrimes(cout, "\n"); // beware that this would print all the primes to stdout :)

	system("pause");
}