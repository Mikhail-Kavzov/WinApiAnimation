#pragma once
#include "Spruce.h"

namespace drawing {
	Spruce::Spruce(int x1, int y1, int a):x1(x1),y1(y1),x2(x1+a),y2(y1+a)
	{	

		int x3centrTr = x1 +( a >> 1);
		int y3firstTr = y1 - (a*3>>1);
		int y3secTr = y3firstTr - a;
		int y3thTr = y3secTr - (a >> 1);
		int starYCentr = y3thTr - (a);

		elements = new IDrawable * [elLen]{
			new Triangle(x1-(a<<1),y1,x2+(a<<1),y1,x3centrTr,y3firstTr,RGB(35,140,35)),
			new Triangle(x3centrTr-(a<<1),y3firstTr,x3centrTr+(a<<1),y3firstTr,x3centrTr,y3secTr, RGB(35, 140, 35)),
			new Triangle(x3centrTr-a,y3secTr,x3centrTr+a,y3secTr,x3centrTr,y3thTr, RGB(35, 140, 35)),
			new Line(x3centrTr,y3thTr,x3centrTr,starYCentr),
			new Star(a,a>>1,x3centrTr,starYCentr,RGB(255,255,0),RGB(255,0,0)),
			new Circle (x3centrTr-a,y3firstTr+a,a>>2,RGB(255,0,0)),
			new Circle(x3centrTr + a, y3firstTr + a, a >> 2,RGB(255,255,0)),
			new Circle(x3centrTr-(a/3), y3firstTr - (a >> 1), a >> 2, RGB(0,0,255))
		};
	}
	void Spruce::Draw(HDC hdc) {
		HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0,0,0)); //black pen
		HBRUSH hBrownBrush = CreateSolidBrush(RGB(140,70,20)); //color root
		SelectObject(hdc, hPen);
		SelectObject(hdc, hBrownBrush);
		Rectangle(hdc, x1, y1, x2, y2);
		DeleteObject(hPen);
		DeleteObject(hBrownBrush);

		for (int i = 0; i < elLen; i++)
		{
			elements[i]->Draw(hdc);
		}
	}
	void Spruce::ChangeBallsColor(COLORREF color[]) {
		
		for (int i = startPosCircle,j=0; i < elLen; i++,j++)
		{
			((Circle*)elements[i])->ChangeColor(color[j]);
			
		}

	}
}