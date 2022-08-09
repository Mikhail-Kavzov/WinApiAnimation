#pragma once
#include"MainWindow.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow)
{
    MainWindow win;

    if (!win.Create(L"Animation", WS_OVERLAPPEDWINDOW))
    {
        return 0;
    }
    
    ShowWindow(win.Window(), nCmdShow);
    
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

