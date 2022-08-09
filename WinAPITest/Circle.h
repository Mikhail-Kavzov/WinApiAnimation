#pragma once
#include "IDrawable.h"

namespace drawing  {
	class Circle:public IDrawable {
	private:
		int x, y, r;
		COLORREF brColor;
	public:

		Circle(int x, int y, int r);
		Circle(int x, int y, int r,COLORREF brColor);
		void ChangeColor(COLORREF brColor);
		void Draw(HDC hdc) override;
	};
}