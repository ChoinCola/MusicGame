#include "MusicP.h"

auto MusicP::Down_P() -> void
{
	this->y++;
}

auto MusicP::Get_x() -> const int
{
	return this->x;
}

auto MusicP::Get_y() -> const int
{
	return this->y;
}

auto MusicP::Set_x(const int x) -> MusicP&
{
	this->x = x;
	return *this;
}

auto MusicP::Set_y(const int y) -> MusicP&
{
	this->y = y;
	return *this;
}
