#pragma once
#include <vector>
#include "IDrawable.h"
#include "BaseWindow.h"
#include "Snowman.h"
#include "Spruce.h"

class MainWindow : public BaseWindow<MainWindow>
{
private:
 
    void    OnPaint();
  //  void    Resize();
   std::vector<IDrawable*> canvaEl;
    const int ColorCount = 7;
    static const int Timer_IDT = 924;
    const int TimerInterval = 300;
    const Color colors[7] = { Color::Magenta,Color::LightBlue,Color::Blue,Color::Red,Color::Yellow,Color::Purple,Color::Orange };

public:
    MainWindow();
    ~MainWindow();
    void RandomColor();
    PCWSTR  ClassName() const { return L"Window Class"; }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

};