#pragma once
#include "Triangle.h"

namespace drawing {
		
	Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3, COLORREF brColor):x1(x1),y1(y1),x2(x2),y2(y2),x3(x3),y3(y3) {
			this->brColor = brColor;
		}
	void Triangle::Draw(HDC hdc) {

		HPEN hpen = CreatePen(PS_SOLID, 1, RGB(0,0,0));
		HBRUSH hBrush = CreateSolidBrush(brColor);
		SelectObject(hdc, hpen);
		SelectObject(hdc, hBrush);
		MoveToEx(hdc, x1,y1, (LPPOINT)NULL);
		LineTo(hdc, x2,y2);
		LineTo(hdc,x3, y3);
		LineTo(hdc,x1, y1);
		FloodFill(hdc, (float)(x1 + x2 + x3) / 3, (float)(y1 + y2 + y3) / 3, RGB(0,0,0));
		DeleteObject(hpen);
		DeleteObject(hBrush);
	}
	
}