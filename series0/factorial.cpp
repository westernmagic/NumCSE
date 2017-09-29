#include "backward.hpp"
#include <iostream>
#include <iomanip>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <functional>
#include <random>
#include <algorithm>
#include <cassert>

using ull = unsigned long long;

template<typename T>
T recurFact(T n) {
	static_assert(std::is_unsigned<T>::value, "");

	n = std::trunc(n);
	if (n <= 1) {
		return T{1};
	} else {
		return n * recurFact(n - 1);
	}
}

template<typename T>
T iterFact(T n) {
	static_assert(std::is_unsigned<T>::value, "");

	n = std::trunc(n);
	T result{1};
	while (n > 1) {
		result *= n--;
	}

	return result;
}

template<typename Iterator, typename R>
auto funcTimer(std::function<R(typename std::iterator_traits<Iterator>::value_type)> f, const Iterator&& begin, const Iterator&& end) {
	using clock = std::chrono::high_resolution_clock;

	auto start_time = clock::now();
	for (auto it = begin; it != end; ++it) {
		f(*it);
	}
	auto end_time = clock::now();
	return end_time - start_time;
}

std::vector<ull> createRandNums(unsigned int N, unsigned int k1, unsigned int k2) {
	assert(k1 < k2);

	std::mt19937_64 generator{N};
	std::uniform_int_distribution<unsigned int> distribution{k1, k2};

	std::vector<ull> result{};
	result.resize(N);

	std::generate_n(std::begin(result), N, [&](){return distribution(generator);});

	return result;
}

int main() {
	long double n;
	std::cin >> n;

	auto input = createRandNums(n, 5, 25);

	auto time_recursive = funcTimer(
		static_cast<std::function<ull(ull)>>(recurFact<ull>),
		std::begin(input),
		std::end(input)
	);

	auto time_iterative = funcTimer(
		static_cast<std::function<ull(ull)>>(iterFact<ull>),
		std::begin(input),
		std::end(input)
	);

	std::cout << "Recursive: " << std::chrono::duration_cast<std::chrono::seconds>(time_recursive).count() << "s\n";
	std::cout << "Iterative: " << std::chrono::duration_cast<std::chrono::seconds>(time_iterative).count() << "s\n";

	return EXIT_SUCCESS;
}
