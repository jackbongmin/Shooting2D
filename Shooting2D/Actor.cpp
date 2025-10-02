#include "Actor.h"
#include "GameManager.h"
#include "ResourceManager.h"

Actor::Actor(ResourceID InID)
{
    //if (InImagePath)
    //{
    //    Image = new Gdiplus::Bitmap(InImagePath); // �̹��� �ε�
    //    if (Image->GetLastStatus() != Gdiplus::Ok)
    //    {
    //        // ���������� ���� �ε��� �ȉ��.
    //        delete Image;       // ���������� ��� ����
    //        Image = nullptr;
    //        OutputDebugString(L"�÷��̾� �̹��� �ε� ����");
    //        MessageBox(GameManager::Get().GetMainWindowHandle(),
    //            L"�÷��̾� �̹��� �ε� ����", L"����", MB_OK | MB_ICONERROR);
    //    }
    //}

    Image = ResourceManager::Get().GetImage(InID);

}

void Actor::DestroyActor()
{
    if (!IsPendingDestroy)
    {
        IsPendingDestroy = true;
    }
}

void Actor::OnTick(float InDeltaTime)
{
}

void Actor::OnRender(Gdiplus::Graphics* InGraphics)
{
    if (!InGraphics) return;
    if (!Image) return;

    // Image�� �ε��Ǿ� �ִ�.
    InGraphics->DrawImage(
        Image,          // �׷��� �̹���
        static_cast<int>(Position.X - Size * Pivot.X),    // �׷��� ��ġ
        static_cast<int>(Position.Y - Size * Pivot.Y),
        Size, Size);  // �׷��� ������
}
