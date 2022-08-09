#pragma once
#include "Circle.h"

namespace drawing {
	Circle::Circle(int x, int y, int r):Circle(x,y,r,RGB(255,255,255))
	{}
	
	Circle::Circle(int x, int y, int r, COLORREF brColor) :x(x), y(y), r(r) {
		this->brColor = brColor;
	}

	void Circle::ChangeColor(COLORREF brColor) {
		this->brColor = brColor;
	}

	void Circle::Draw(HDC hdc)	{	

		HPEN hPen = CreatePen(PS_SOLID, 1, BLACK_PEN);
		HBRUSH hBrush = CreateSolidBrush(brColor);
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrush);
		Ellipse(hdc, x-r, y-r, x+r,y+r);
		DeleteObject(hBrush);
		DeleteObject(hPen);
		
	}
}