#pragma once
#include "Common.h"

class Actor
{
public:
	Actor() = delete;
	Actor(const wchar_t* InImagePath);
	~Actor();

	virtual void Tick(float InDeltaTime);
	virtual void Render(Gdiplus::Graphics* InGraphics);

	float GetSpeed() const { return Speed; }
	PointF GetPosition() const { return Position; }
	PointF GetPivot() const { return Pivot; }

private:
	static constexpr int PixelSize = 64;

	PointF Position = { 0.0f, 0.0f };

	PointF Pivot = { 0.5f, 0.5f };

	float Speed = 0.0f;

	Gdiplus::Bitmap* Image = nullptr;

	float Offset = 0.0f;
};

