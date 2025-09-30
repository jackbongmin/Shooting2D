#pragma once
#include <unordered_map>
#include <Windows.h>
#include <gdiplus.h>
#include "enums.h"

//extern : 뒤에 있는 변수가 다른 파일에 선언 되어 있다.
extern HWND g_hMainWindow; // g_hMainWindow가 다른 파일에 있다는 것을 알려줌
extern Gdiplus::Point g_ScreenSize;

using PointF = Gdiplus::PointF;
class Player
{
	/*
		피봇 위치는 한가운데(float 2개)
		이미지로 표시
		키보드 입력으로 좌우 이동
		플레이어가 화면을 벗어나지 않게 하기
	*/

public:

	Player() = delete;
	Player(const wchar_t* InImagePath);	// 무조건 파일 경로를 받아야 생성할 수 있다.
	~Player();

	void Render(Gdiplus::Graphics* InGraphics);

	void HandleKeyState(WPARAM InKey, bool InIsPressed);

private:

	// 플레이어 키 입력 상태
	std::unordered_map<InputDirection, bool> KeyWasPressedMap;
	
	// 플레이어 이미지가 들어있을 비트맵
	Gdiplus::Bitmap* Image = nullptr;   // 플레이어가 그려질 종이
	
	// 플레이어가 그려질 크기
	static constexpr int PixelSize = 64;

	// 플레이어의 중심점
	PointF Pivot = { 0.5f, 0.5f };	// Pivot 기본값은 한가운데

	// 플레이어의 위치
	PointF Position = { 0.0f, 0.0f };

	// 플레이어의 이동속도
	float Speed = 10.0f;
};


/*
실습
1. 플레이어의 움직임이 좌우로 서로 순환되게 만들기
2. 흐르는 배경 만들기
3. 플레이어의 움직이는 속도가 컴퓨터 성능에 영향에 없으려면 어떻게 해야하는가?
*/