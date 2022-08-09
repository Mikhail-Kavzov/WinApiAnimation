#pragma once
#include "Colors.h"

using namespace MColor;
	class IDrawable { // Interface for drawing
	public:
		virtual ~IDrawable() { }
		virtual void Draw(HDC hdc) = 0;
	};


	