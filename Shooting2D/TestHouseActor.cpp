#include "TestHouseActor.h"

TestHouseActor::TestHouseActor()
    : Actor(nullptr)
{
    GreenPen = new Gdiplus::Pen(Gdiplus::Color(255, 0, 255, 0), 2.0f);

    int Max = -1;
    for (PointF Pos : HouseVertices)
    {
        if (Max < Pos.X)
        {
            Max = Pos.X;
        }
    }
    Size = Max;
}

TestHouseActor::~TestHouseActor()
{
    delete GreenPen;
    GreenPen = nullptr;
}

void TestHouseActor::OnRender(Gdiplus::Graphics* InGraphics)
{
    //static_cast<int>(Position.X - Size * Pivot.X),    // 그려질 위치
    //    static_cast<int>(Position.Y - Size * Pivot.Y),

    PointF Positions[HouseVerticesCount];
    for (int i = 0; i < HouseVerticesCount; i++)
    {
        Positions[i] = Position + HouseVertices[i];
        Positions[i].X -= Size * Pivot.X;
        Positions[i].Y -= Size * Pivot.Y;
    }
    InGraphics->DrawPolygon(GreenPen, Positions, HouseVerticesCount);
    //g_BackBufferGraphics->FillPolygon(GreenBrush, Positions, g_HouseVerticesCount);
}