#pragma once

#include "framework.h"

class Player
{
public:

	Player(int StartX)
		:X(StartX)
	{
		PlayerImage = new Gdiplus::Bitmap(L"./Images/Airplane.png");
	}
	void MoveLeft();
	void MoveRight();


private:
	int X;
	const int StartX = 400;
	const int StartY = 550;
	Gdiplus::Bitmap* PlayerImage = nullptr;

	const int ScreenWidthSize = 800;
	const int ScreenHeightSize = 600;

	void ClampScreen();

	// 좌우이동, 이미지, 이동 최댓값, 피봇위치, 
};

