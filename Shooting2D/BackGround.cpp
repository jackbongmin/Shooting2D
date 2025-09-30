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
        OutputDebugString(L"�÷��̾� �̹��� �ε� ����");
        MessageBox(g_hMainWindow, L"�÷��̾� �̹��� �ε� ����", L"����", MB_OK | MB_ICONERROR);
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
        // g_PlayerImage�� �ε��Ǿ� �ִ�.
        InGraphics->DrawImage(
            BGImage,          // �׷��� �̹���
            static_cast<int>(MoveX),
            static_cast<int>(MoveY),    // �׷��� ��ġ
            BGPixelSize, BGPixelSize);  // �׷��� ������
    }
    else
    {
        Gdiplus::SolidBrush RedBrush(Gdiplus::Color(255, 255, 0, 0));
        InGraphics->FillEllipse(
            &RedBrush,
            static_cast<int>(Position.X),    // �׷��� ��ġ
            static_cast<int>(Position.Y),
            BGPixelSize, BGPixelSize);
    }
}
