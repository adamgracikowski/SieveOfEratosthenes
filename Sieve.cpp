#include "Sieve.h"
#include <fstream>
#include <algorithm>
#include <iterator>
#include <cassert>

using namespace std;

Sieve::Sieve(number_type endingNumber)
{
	assert(endingNumber >= startingNumber);

	container_type numbers{};
	generate_n(back_inserter(numbers), endingNumber - 1, [n = startingNumber]() mutable { return n++; });

	while (!numbers.empty()) {
		number_type n = numbers.front();
		primes.splice(primes.end(), numbers, numbers.begin());
		numbers.remove_if([n](const int& number) { return number % n == 0; });
	}
}

Sieve::container_type Sieve::getPrimes() const
{
	return primes;
}

size_t Sieve::countPrimes() const
{
	return primes.size();
}

std::ostream& Sieve::printPrimes(std::ostream& os, std::string delimeter) const
{
	copy(primes.begin(),
		primes.end(),
		ostream_iterator<number_type>(os, delimeter.c_str()));
	return os;
}

bool Sieve::savePrimesToFile(std::string filename)
{
	ofstream file(filename);
	if (!file) return false;
	printPrimes(file, "\n");
	file.close();
	return true;
}

std::ostream& operator<<(std::ostream& os, const Sieve& sieve)
{
	return sieve.printPrimes(os);
}
