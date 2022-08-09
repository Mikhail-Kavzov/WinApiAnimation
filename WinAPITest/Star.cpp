#include "Star.h"

namespace drawing {
    
    Star::Star(int R1, int R2,int Xc, int Yc, COLORREF brColor,COLORREF penColor):R1(R1),R2(R2),Xc(Xc),Yc(Yc)
    {
        this->brColor = brColor;
        this->penColor = penColor;

        int count = -1;
        double step = 0.2 * PI, angle = 1.6 * PI;

        while (++count < 10)
        {
            point[count].x = Xc + R1 * sin(angle);
            point[count].y = Yc - R1 * cos(angle);
            angle += step;
            point[++count].x = Xc + R2 * sin(angle);
            point[count].y = Yc - R2 * cos(angle);
            angle += step;
        }
    }
    void Star::Draw(HDC hdc)
    {
        HPEN hPen = CreatePen(PS_SOLID, 2, penColor);
        HBRUSH hBrush = CreateSolidBrush(brColor);
        SelectObject(hdc, hPen);
        SelectObject(hdc, hBrush);

        Polygon(hdc, point, 10);

        DeleteObject(hPen);
        DeleteObject(hBrush);
    }
}