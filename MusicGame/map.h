#pragma once
#include "head.h"


class map
{
	int* Map;
	int life[LENGTH] = { space };
	int max_life;
	std::vector<std::string> keyP;
	int width;
	int length;

public:
	map(const int x, const int y, const int life) {
		Map = new int[x * y];
		width = x;
		length = y;

		for (int i = 0; i < life; i++) {
			this->life[i] = Life;
		}
		max_life = life;
		for (int i = 0; i < width; i++) {
			*(Map + i + width * (length - 3)) = Note_Chack;
			*(Map + i + width * (length - 2)) = Note_Chack;
			*(Map + i + width * (length - 1)) = DEAD_Z;
		}
		for (int i = 0; i < length; i++) {
			*(Map + i * width) = wall;
			*(Map + i * width + width - 1) = wall;
		}
		
		keyP.push_back("  ");
		keyP.push_back(" Q");
		keyP.push_back(" W");
		keyP.push_back(" E");
		keyP.push_back(" R");
		keyP.push_back("  ");
	}

	auto Print_Map() -> void;
	auto Down_life() -> void;
	auto UP_life() -> void;
	auto Get_life() -> const int;
};

