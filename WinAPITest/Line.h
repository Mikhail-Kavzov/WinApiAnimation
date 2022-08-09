#pragma once
#include "IDrawable.h"

namespace drawing {
	class Line :public IDrawable {
	private: POINT* point = new POINT[2];
		   COLORREF penColor;
		   int width;
	public:
		Line(int x1, int y1, int x2, int y2, COLORREF penColor, int width);
		Line(int x1, int y1, int x2, int y2);
		void Draw(HDC hdc) override;
		 ~Line();
	};
}