#pragma once
#include <unordered_map>
#include "enums.h"
#include "Actor.h"

class Player : public Actor
{

public:

	Player() = delete;
	Player(const wchar_t* InImagePath);	// 무조건 파일 경로를 받아야 생성할 수 있다.

	virtual void OnTick(float InDeltaTime) override;
	virtual void OnRender(Gdiplus::Graphics* InGraphics) override;

	void HandleKeyState(WPARAM InKey, bool InIsPressed);

	inline float GetSpeed() const { return Speed; }
	inline void SetSpeed(float InSpeed) { Speed = InSpeed; }

private:
	// 플레이어의 이동 속도
	float Speed = 200.0f;

	// 플레이어 키 입력 상태
	std::unordered_map<InputDirection, bool> KeyWasPressedMap;
};


/*
실습
1. 플레이어의 움직임이 좌우로 서로 순환되게 만들기
2. 흐르는 배경 만들기
3. 플레이어의 움직이는 속도가 컴퓨터 성능에 영향에 없으려면 어떻게 해야하는가?
*/