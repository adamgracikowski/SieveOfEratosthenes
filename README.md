# Sieve Of Eratosthenes:

## Table of Contents:

- [What is the sieve of Eratosthenes?](##what-is-the-sieve-of-eratosthenes?)
- [About the Implementation](##about-the-implementation)
- [Features](##features)
- [Author](##author)
- [Contributing](##contributing)
- [Show your support](##show-your-support)

## [What is the sieve of Eratosthenes?](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes)
In mathematics, the sieve of Eratosthenes is an ancient algorithm for finding all prime numbers up to any given limit.

It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with the first prime number, 2. The multiples of a given prime are generated as a sequence of numbers starting from that prime, with constant difference between them that is equal to that prime. This is the sieve's key distinction from using trial division to sequentially test each candidate number for divisibility by each prime. Once all the multiples of each discovered prime have been marked as composites, the remaining unmarked numbers are primes.

One of a number of prime number sieves, it is one of the most efficient ways to find all of the smaller primes. It may be used to find primes in arithmetic progressions.

<p align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/9/94/Animation_Sieve_of_Eratosth.gif" alt="Animation_Sieve_of_Eratosthenes" />
</p>

## About the Implementation:

The Sieve class was implemented as a class template with one template parameter. It supports arithmetic types such as short, int, long, long long etc.

The main objective of the project was to make an intensive use of STL features such as containers, algorithms and iterators. 

As for the data structure used in the Sieve class, the std::list was chosen due to the discontinuous memory area that it occupies.

## Features:

All the public methods of the Sieve class with a short explanation are correlated in the table below:

| Method: | Explanation: |
|---|---|
| **explicit Sieve(number_type endingNumber)** | A public constructor where endingNumber is the last number taken into account in the sieve algorithm. |
| **container_type getPrimes() const** | Returns a copy of the inner container which holds the prime numbers. |
| **size_t countPrimes() const** | Returns the number of primes found between 2 and endingNumber inclusive. |
| **std::ostream& printPrimes(std::ostream& os, std::string delimeter = " ") const** | Prints the prime numbers to the os output stream. |
| **bool savePrimesToFile(std::string filename)** | Creates a text file and saves the prime numbers to the file. |
| **friend std::ostream& operator<<(std::ostream& os, const Sieve<T>& sieve)** | The overloaded operator<< |

## Author:

My GitHub: [@adamgracikowski](https://github.com/adamgracikowski)

## Contributing:

All contributions, issues, and feature requests are welcome! 🤝

## Show your support:

Give a ⭐️ if you like this project and its documentation!
