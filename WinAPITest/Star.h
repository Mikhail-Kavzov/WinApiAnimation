#pragma once
#include <math.h>
#include "IDrawable.h"

namespace drawing {
	class Star :public IDrawable {
	private:
		POINT point[10];
		COLORREF brColor, penColor;
		const double PI = 3.14159265359;
		int R1, R2, Xc, Yc;  //Radiuses to vertexes and star centre
	public:
		Star(int R1, int R2, int Xc, int Yc, COLORREF brColor, COLORREF penColor); 
		void Draw(HDC hdc) override;
	};
}