#include "BackGround.h"

BackGround::BackGround(const wchar_t* InImagePath)
{
    Position.X = 0;
    Position.Y = StartY;

    BGImage = new Gdiplus::Bitmap(InImagePath);
    if (BGImage->GetLastStatus() != Gdiplus::Ok)
    {
        delete BGImage;    
        BGImage = nullptr;
        OutputDebugString(L"플레이어 이미지 로드 실패");
        MessageBox(g_hMainWindow, L"플레이어 이미지 로드 실패", L"오류", MB_OK | MB_ICONERROR);
    }
}

BackGround::~BackGround()
{
}

void BackGround::MoveDown()
{
    Position.Y += Speed;
    if (Position.Y > g_ScreenSize.Y)
    {
        Position.Y = -BGPixelSize;
    }
    InvalidateRect(g_hMainWindow, nullptr, FALSE);
}


void BackGround::Render(Gdiplus::Graphics* InGraphics, int Inx, int Iny)
{
    int MoveX = Position.X + Inx;
    int MoveY = Position.Y + Iny;

    if (BGImage)
    {
        // g_PlayerImage가 로딩되어 있다.
        InGraphics->DrawImage(
            BGImage,          // 그려질 이미지
            static_cast<int>(MoveX),
            static_cast<int>(MoveY),    // 그려질 위치
            BGPixelSize, BGPixelSize);  // 그려질 사이즈
    }
    else
    {
        Gdiplus::SolidBrush RedBrush(Gdiplus::Color(255, 255, 0, 0));
        InGraphics->FillEllipse(
            &RedBrush,
            static_cast<int>(Position.X),    // 그려질 위치
            static_cast<int>(Position.Y),
            BGPixelSize, BGPixelSize);
    }
}
