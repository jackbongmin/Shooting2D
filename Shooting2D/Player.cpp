#include "Player.h"
#include "Shooting2D.h"
extern Gdiplus::Point g_ScreenSize;


void Player::MoveLeft()
{
	X -= 10;
	ClampScreen();
}

void Player::MoveRight()
{
	X += 10;
	ClampScreen();
}

void Player::ClampScreen()
{
	if (X < 0)
	{
		X = 0;
	}

	if (X > g_ScreenSize.X)
	{
		X = g_ScreenSize.X;
	}
}
