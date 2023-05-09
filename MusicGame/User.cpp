#include "User.h"

auto User::INPUT() -> int
{
	if (GetAsyncKeyState(VK_Q)) {
		return Q;
	}
	else if (GetAsyncKeyState(VK_W)) {
		return W;
	}
	else if (GetAsyncKeyState(VK_E)) {
		return E;
	}
	else if (GetAsyncKeyState(VK_R)) {
		return R;
	}
}
