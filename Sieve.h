#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <iterator>
#include <algorithm>
#include <assert.h>

template<typename T>
class Sieve {
public:
	using number_type = T;
	using container_type = std::list<number_type>;

	explicit Sieve(number_type endingNumber);

	container_type getPrimes() const;
	size_t countPrimes() const;

	std::ostream& printPrimes(std::ostream& os, std::string delimeter = " ") const;
	bool savePrimesToFile(std::string filename);

	friend std::ostream& operator<<(std::ostream& os, const Sieve<T>& sieve)
	{
		return sieve.printPrimes(os);
	}
private:
	container_type primes;
	static const number_type startingNumber{ 2 };
};

template<typename T>
Sieve<T>::Sieve(number_type endingNumber)
{
	assert(endingNumber >= startingNumber);

	/* standard sieve of Eratosthenes algorithm */
	container_type numbers{};
	std::generate_n(std::back_inserter(numbers), endingNumber - 1, [n = startingNumber]() mutable { return n++; });

	while (!numbers.empty()) {
		number_type n = numbers.front();
		this->primes.splice(this->primes.end(), numbers, numbers.begin());
		numbers.remove_if([n](const int& number) { return number % n == 0; });
	}
}

template<typename T>
inline typename Sieve<T>::container_type Sieve<T>::getPrimes() const
{
	return this->primes;
}

template<typename T>
inline size_t Sieve<T>::countPrimes() const
{
	return this->primes.size();
}

template<typename T>
std::ostream& Sieve<T>::printPrimes(std::ostream& os, std::string delimeter) const
{
	std::copy(this->primes.begin(),
		this->primes.end(),
		std::ostream_iterator<number_type>(os, delimeter.c_str()));
	return os;
}

template<typename T>
bool Sieve<T>::savePrimesToFile(std::string filename)
{
	std::ofstream file(filename, std::ios::out | std::ios::trunc);
	if (!file) return false;
	printPrimes(file, "\n");
	file.close();
	return true;

}