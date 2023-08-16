#pragma once
#include <iostream>
#include <list>
#include <string>

class Sieve {
public:
	using number_type = unsigned long long;
	using container_type = std::list<number_type>;

	explicit Sieve(number_type endingNumber);
	container_type getPrimes() const;
	size_t countPrimes() const;

	std::ostream& printPrimes(std::ostream& os, std::string delimeter = " ") const;
	bool savePrimesToFile(std::string filename);
	friend std::ostream& operator<<(std::ostream& os, const Sieve& sieve);

private:
	container_type primes;
	static const number_type startingNumber{ 2 };
};




