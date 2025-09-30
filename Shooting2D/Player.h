#pragma once
#include <unordered_map>
#include <Windows.h>
#include <gdiplus.h>
#include "enums.h"

//extern : �ڿ� �ִ� ������ �ٸ� ���Ͽ� ���� �Ǿ� �ִ�.
extern HWND g_hMainWindow; // g_hMainWindow�� �ٸ� ���Ͽ� �ִٴ� ���� �˷���
extern Gdiplus::Point g_ScreenSize;

using PointF = Gdiplus::PointF;
class Player
{
	/*
		�Ǻ� ��ġ�� �Ѱ��(float 2��)
		�̹����� ǥ��
		Ű���� �Է����� �¿� �̵�
		�÷��̾ ȭ���� ����� �ʰ� �ϱ�
	*/

public:

	Player() = delete;
	Player(const wchar_t* InImagePath);	// ������ ���� ��θ� �޾ƾ� ������ �� �ִ�.
	~Player();

	void Render(Gdiplus::Graphics* InGraphics);

	void HandleKeyState(WPARAM InKey, bool InIsPressed);

private:

	// �÷��̾� Ű �Է� ����
	std::unordered_map<InputDirection, bool> KeyWasPressedMap;
	
	// �÷��̾� �̹����� ������� ��Ʈ��
	Gdiplus::Bitmap* Image = nullptr;   // �÷��̾ �׷��� ����
	
	// �÷��̾ �׷��� ũ��
	static constexpr int PixelSize = 64;

	// �÷��̾��� �߽���
	PointF Pivot = { 0.5f, 0.5f };	// Pivot �⺻���� �Ѱ��

	// �÷��̾��� ��ġ
	PointF Position = { 0.0f, 0.0f };

	// �÷��̾��� �̵��ӵ�
	float Speed = 10.0f;
};


/*
�ǽ�
1. �÷��̾��� �������� �¿�� ���� ��ȯ�ǰ� �����
2. �帣�� ��� �����
3. �÷��̾��� �����̴� �ӵ��� ��ǻ�� ���ɿ� ���⿡ �������� ��� �ؾ��ϴ°�?
*/