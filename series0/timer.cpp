#include <iostream>
#include <chrono>
#include <functional>

template<typename R, typename T>
double funcTimer(std::function<R(T)> f, T arr[]) {
	using clock = std::chrono::high_resolution_clock;

	auto start = clock::now();
	for (auto it = std::begin(arr); it != std::end(arr); ++it) {
		f(*it);
	}
	auto end = clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(start - end).count();
}

