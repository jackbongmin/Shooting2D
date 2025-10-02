#pragma once
#include <cstdint>
#include <Windows.h>

enum class InputDirection : uint8_t
{
	None = 0,
	Up = VK_UP,
	Down = VK_DOWN,
	Left = VK_LEFT,
	Right = VK_RIGHT
};

enum class RenderLayer
{
	Background = 0,
	Player,
	Bomb,
	UI,
	Test,
	Misc
};

enum class ResourceID : uint8_t
{
	None = 0,
	Player,
	Bomb,
	Background,
	Number0,
	Number1,
	Number2,
	Number3,
	Number4,
	Number5,
	Number6,
	Number7,
	Number8,
	Number9,
	Dot,
	// �̹����� �߰��Ǹ� enum �߰�
};