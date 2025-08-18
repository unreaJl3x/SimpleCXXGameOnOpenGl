/*
#ifndef UNTITLEDWARE_DXOVERLAY_H
#define UNTITLEDWARE_DXOVERLAY_H

#include <iostream>
#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>
#include <dwmapi.h>
#include "dxRender.h"
#include "WRECT.h"
#include "WPOINT.h"
using namespace std;

class dxOverlay {
private:
    IDirect3D9* iDirectD3D9X;
    IDirect3DDevice9* iDirectD3D9XDevice;
    static HWND hWindow;

    bool CreateDXOverlay(char*, RECT* = nullptr);
    void InitDirectX9();

    static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

public:
    static WRECT GetWindowRectMY(HWND);
    HWND GetWindowHandle();

    dxRender CreateRender();

    dxOverlay(string);
    dxOverlay(string, unsigned short int width,unsigned short int height, POINT startPos=WPOINT(0,0));
    ~dxOverlay();
};


#endif //UNTITLEDWARE_DXOVERLAY_H*/
