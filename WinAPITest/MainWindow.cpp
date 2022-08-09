#pragma once
#include "MainWindow.h"

using namespace drawing;

MainWindow::MainWindow()
{
    canvaEl.push_back(new drawing::Spruce(400, 500, 80));
    canvaEl.push_back(new drawing::Snowman(900, 500, 80));
   
}

MainWindow::~MainWindow() {
    KillTimer(m_hwnd, Timer_IDT);
    for (std::vector<IDrawable*>::iterator pointer = canvaEl.begin();
        pointer != canvaEl.end(); ++pointer)
    {
        delete* pointer;
    }
}

void MainWindow::OnPaint()
{     
        PAINTSTRUCT ps;
        HDC hdc=BeginPaint(m_hwnd, &ps);
        int len = canvaEl.size();
        for (auto canv:canvaEl)
        {
            canv->Draw(hdc);
        } 
        EndPaint(m_hwnd, &ps);
       
}

void MainWindow::RandomColor()
{   
    const int len = Spruce::elLen - Spruce::startPosCircle;
    Color clRand[len];
    for (int i = 0; i < len; i++) 
    {
        int elRand = rand() % ColorCount;
        clRand[i] = colors[elRand];
    }
    ((Spruce*)canvaEl[0])->ChangeBallsColor((COLORREF*)clRand);  
    InvalidateRect(m_hwnd, NULL, FALSE);
   
}

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {

    case WM_CREATE:
        SetTimer(m_hwnd, Timer_IDT, TimerInterval, NULL);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);   
        return 0;

    case WM_PAINT:
       OnPaint();
        return 0;
    case WM_TIMER:
    {
        switch (wParam) {
        case Timer_IDT:
            RandomColor();
            return 0;
        }
    }

    
    }
    return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}
