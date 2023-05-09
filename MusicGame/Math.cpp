#include "head.h"
#include "Math.h"

std::random_device Math::rd;
std::mt19937 Math::mt(rd());

const int Math::Random(const int& min, const int& max)
{
	return std::uniform_int_distribution<int>{min, max}(mt);
}