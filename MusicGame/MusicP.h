#pragma once

class MusicP
{
	int x;
	int y;
public:
	auto Down_P() -> void;
	auto Get_x() -> const int;
	auto Get_y() -> const int;
	auto Set_x(const int x) -> MusicP&;
	auto Set_y(const int y) -> MusicP&;
};

