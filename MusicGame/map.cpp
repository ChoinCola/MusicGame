#include "map.h"

auto print_set(const int def) -> void
{
	switch (def)
	{
	case space :
	{
		printf("  ");
		break;
	}
	case wall:
	{
		printf("бс");
		break;
	}
	case Note_Chack:
	{
		printf("бр");
		break;
	}
	case Life:
	{
		printf("в╛");
		break;
	}
	default:
		printf("  ");
		break;
	}
}

auto map::Print_Map() -> void
{
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++ ) {
			print_set(*(Map + j + i * this->width));
		}
		print_set(life[length - i - 1]);
		printf("\n");
	}
	for (std::string element : keyP) { std::cout << element; }
}

auto map::Down_life() -> void
{
	life[max_life] = 0;
	max_life--;
}

auto map::UP_life() -> void
{
	if (max_life < length) {
		life[max_life] = 1;
		max_life++;
	}
}

auto map::Get_life() -> const int
{
	return max_life;
}
