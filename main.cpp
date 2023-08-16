#include "Sieve.h"
#include <iostream>

using namespace std;

int main() {

	Sieve sieve(1000UL);
	if (sieve.savePrimesToFile("primesUpTo1000.txt"))
	{
		cout << "Success" << endl;
	}
	else {
		cout << "Failure" << endl;
	}

}