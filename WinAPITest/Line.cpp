#pragma once
#include "Line.h"

namespace drawing {
	Line::Line(int x1, int y1, int x2, int y2):Line(x1,y1,x2,y2,RGB(0,0,0),1)
	{}
	Line::Line(int x1, int y1, int x2, int y2,COLORREF penColor, int width):width(width){

		point[0].x = x1;
		point[0].y = y1;
		point[1].x = x2;
		point[1].y = y2;
		this->penColor = penColor;		
	}
	void Line::Draw(HDC hdc) {
		HPEN hpen = CreatePen(PS_SOLID, width, penColor);
		SelectObject(hdc, hpen);
		MoveToEx(hdc,point[0].x,  point[0].y, (LPPOINT)NULL);
		LineTo(hdc, point[1].x,point[1].y);
		DeleteObject(hpen);
	}
	Line::~Line(){
		delete [] point;
	}
}