#pragma once
#include "Snowman.h"

namespace drawing {
	Snowman::Snowman(int x, int y, float r) 
	{	
		
		float secRad = r * 3 / 4;
		float thRad = r * 2 / 3;
		int secCircleY = y - r - secRad;
		int thCircleY = secCircleY - secRad - thRad;
		float eyeRad = thRad / 10;
		float halfRad = thRad / 2;
		float yArmEnd = secCircleY + secRad;

		parts = new IDrawable*[partsLength] { new Circle(x, y, r), new Circle(x, secCircleY, secRad), new Circle(x, thCircleY, thRad),
			new Circle(x-halfRad,thCircleY,eyeRad,RGB(0,0,0)), new Circle(x + halfRad,thCircleY,eyeRad,RGB(0,0,0)),
		 new Line(x-secRad,secCircleY,x-secRad*2,yArmEnd), new Line (x+secRad,secCircleY,x+secRad*2,yArmEnd)};
		

	}
	Snowman::~Snowman(){
		delete[] parts;
	}
	

	void Snowman::Draw(HDC hdc)
	{
		for (int i = 0; i < partsLength; i++)
		{
			parts[i]->Draw(hdc);
		}		
	}
}
