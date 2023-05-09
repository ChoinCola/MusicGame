#pragma once

class Math
{

public:
	static const int Random(const int& min, const int& max);

private:

	static std::random_device rd;
	static std::mt19937 mt;

};