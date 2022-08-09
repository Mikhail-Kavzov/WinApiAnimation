#pragma once
#include "Circle.h"
#include "Line.h"

namespace drawing {
	class Snowman : public IDrawable {
	private: IDrawable** parts;
		     const int partsLength = 7;

	public: 

		  Snowman(int x,int y,float r); //x,y - coords of the biggest circle, r - its radius
		  void Draw(HDC hdc) override;
		  ~Snowman();
	};
}