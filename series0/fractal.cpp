#include "backward.hpp"
#include <iostream>
#include <memory>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cassert>
#include "mgl2/mgl.h"

class Point {
	private:
	public:
		const double x;
		const double y;
		std::unique_ptr<Point> next = nullptr;

	public:
		Point(const double&& x, const double&& y, std::unique_ptr<Point> next = nullptr) : x{x}, y{y}, next{std::move(next)} {}

		~Point() {
			while (next) {
				Point *second = next.get();
				next = std::move(second->next);
				second->next.release();
			}
		}

		double length() {
			double result = 0;
			for (Point *node = this; node->next; node = node->next.get()) {
				result += std::sqrt(std::pow(node->next->x - node->x, 2) + std::pow(node->next->y - node->y, 2));
			}
			return result;
		}

		void plot() {
			Point *node = this;
			std::vector<double> xs;
			std::vector<double> ys;

			do {
				xs.emplace_back(node->x);
				ys.emplace_back(node->y);
				node = node->next.get();
			} while (node);

			mglGraph canvas;
			canvas.SetRanges(0, 1, 0, 1);
			canvas.Plot(
				mglData{xs.data(), static_cast<int>(xs.size())},
				mglData{ys.data(), static_cast<int>(ys.size())}
			);
			canvas.WriteEPS("fractal.eps");
		}

		void fractalize() {
			Point *node = this;
			Point *tail = node;
			while (node->next) {
				tail = node->next.get();
				node->fractalizeSegment();
				node = tail;
			}
		}
		

	private:
		void fractalizeSegment() {
			assert(next);
			double x1 = 1.0 / 3.0 * (next->x - x);
			double y1 = 1.0 / 3.0 * (next->y - y);
			double x2 = 2 * x1;
			double y2 = 2 * y1;

			double x_half = 0.5 * (x2 - x1);
			double y_half = 0.5 * (y2 - y1);

			double x_mid = x1 + x_half - std::sqrt(3) * y_half;
			double y_mid = y1 + y_half + std::sqrt(3) * x_half;

			next = std::make_unique<Point>(
				x + x1, y + y1,
				std::make_unique<Point>(
					x + x_mid, y + y_mid,
					std::make_unique<Point>(
						x + x2, y + y2,
						std::move(next)
					)
				)
			);
	}
};

int main() {
	auto segment = std::make_unique<Point>(0, 0,std::make_unique<Point>(1, 0));

	for (int i = 1; i <= 12; ++i) {
		segment->fractalize();
		std::cout << i << " " << segment->length() << std::endl;
	}

	segment->plot();

	return EXIT_SUCCESS;
}
