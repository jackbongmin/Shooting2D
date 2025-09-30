#pragma once

#include <unordered_map>
#include <Windows.h>
#include <gdiplus.h>
#include "enums.h"

extern HWND g_hMainWindow;
extern Gdiplus::Point g_ScreenSize;
using PointF = Gdiplus::PointF;
class BackGround
{
public:

	BackGround() = default;
	BackGround(const wchar_t* InImagePath);
	~BackGround();

	void MoveDown();

	void Render(Gdiplus::Graphics* InGraphics, int Inx, int Iny);

private:

	const int StartY = 0;
	Gdiplus::Bitmap* BGImage = nullptr;
	static constexpr int BGPixelSize = 64;
	PointF Position = { 0.0f, 0.0f };
	PointF Pivot = { 1.0f, 1.0f };

	float Speed = 10.0f;
};