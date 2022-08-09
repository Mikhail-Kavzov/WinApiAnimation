#pragma once
#include "IDrawable.h"
#include "Triangle.h"
#include "Circle.h"
#include "Star.h"
#include "Line.h"

namespace drawing {
	class Spruce :public IDrawable {
		private:
			int x1, y1, x2, y2; //coords of root
			IDrawable** elements;
			
		public:
			static const int elLen = 8;
			static const int startPosCircle = 5;

			Spruce(int x1, int y1, int a); //coords upper-left root and distance
			void ChangeBallsColor(COLORREF color[]);
			~Spruce(){ delete[] elements;}
			void Draw(HDC hdc) override;
	};
}