#pragma once
#include "IDrawable.h"

namespace drawing {
	class Triangle :public IDrawable {
	private:
		int x1, y1, x2, y2, x3, y3;
		COLORREF brColor;
	public:
		Triangle(int x1, int y1, int x2, int y2, int x3, int y3, COLORREF brColor);
		void Draw(HDC hdc) override;
	};
}