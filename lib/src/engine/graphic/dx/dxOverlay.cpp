/*
#include "dxOverlay.h"
#define CLASS (string(windowName)+"Class").c_str()
#define DEFAULTWINDOW WRECT(0,0,800,600)

HWND dxOverlay::hWindow;

dxOverlay::dxOverlay(string nameWindow) {
    CreateDXOverlay(const_cast<char *>(nameWindow.c_str()));
}
dxOverlay::dxOverlay(string nameWindow, unsigned short int w, unsigned short int h, POINT start) {
    CreateDXOverlay(const_cast<char *>(nameWindow.c_str()),new WRECT(start.x,start.y,start.x+w,start.y+h));
}

dxOverlay::~dxOverlay() {
    if ( iDirectD3D9X ) { iDirectD3D9X->Release(); }
    if ( iDirectD3D9XDevice ) { iDirectD3D9XDevice->Release(); }
    if ( hWindow ) { DestroyWindow(hWindow); }
}

bool dxOverlay::CreateDXOverlay(char* windowName, RECT* r) {
    WNDCLASSEX ovrlWindowClass;
    string _class = (string(windowName)+string("Class"));
    ovrlWindowClass.cbSize = sizeof(ovrlWindowClass);
    ovrlWindowClass.style = CS_HREDRAW | CS_VREDRAW | CS_NOCLOSE;
    ovrlWindowClass.lpfnWndProc = WindowProc;//https://learn.microsoft.com/ru-ru/windows/win32/learnwin32/writing-the-window-procedure
    ovrlWindowClass.cbClsExtra = 0;
    ovrlWindowClass.cbWndExtra = 0;
    ovrlWindowClass.hInstance = NULL;
    ovrlWindowClass.hIcon = LoadIconA(NULL,IDI_SHIELD);
    ovrlWindowClass.hCursor = LoadCursorA(NULL, IDC_ARROW);
    ovrlWindowClass.hbrBackground = HBRUSH(RGB(0, 0, 0));
    ovrlWindowClass.lpszMenuName = windowName;
    ovrlWindowClass.lpszClassName = _class.c_str();
    ovrlWindowClass.hIconSm = NULL;

    if (RegisterClassExA(&ovrlWindowClass) == 0) {
        cout<<"[CreateDXOverlay]| Can't Register overlay class."<<endl;
        return false;
    }

    WRECT window = !r?DEFAULTWINDOW:*r;

    hWindow = CreateWindowExA(
            WS_EX_TOPMOST  | WS_EX_TRANSPARENT,
            CLASS,
            windowName,
              WS_BORDER,
            window.left,
            window.top,
            window.width(),
            window.height(),
            NULL,
            NULL,
            NULL,
            NULL
    );
   if (!hWindow) { cout<<"[CreateDXOverlay]| Window has't created."<<endl; }
    _MARGINS margins;
            margins.cxLeftWidth = window.left;
            margins.cxRightWidth = window.right;
            margins.cyTopHeight = window.top;
            margins.cyBottomHeight = window.bottom;

    DwmExtendFrameIntoClientArea(hWindow, &margins);

    SetLayeredWindowAttributes(hWindow, RGB(0, 0, 0), 255, LWA_ALPHA);

    ShowWindow(hWindow, SW_SHOW);

    InitDirectX9();

    return true;
}
void dxOverlay::InitDirectX9() {
    iDirectD3D9X = Direct3DCreate9(D3D_SDK_VERSION);
    if (!iDirectD3D9X) { cout<<"[InitDirectX9]| Failed Direct3DCreate9."<<endl; return; }
    D3DPRESENT_PARAMETERS d3Params;

    ZeroMemory(&d3Params, sizeof(d3Params));

    WRECT window = WRECT(0,0,800,600);

    d3Params.Windowed = true;
    d3Params.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3Params.BackBufferFormat = D3DFMT_A8R8G8B8;
    d3Params.BackBufferHeight = window.height();
    d3Params.BackBufferWidth = window.width();
    d3Params.hDeviceWindow = hWindow;
    d3Params.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;


    if ( iDirectD3D9X->CreateDevice(
                    D3DADAPTER_DEFAULT,
                    D3DDEVTYPE_HAL,
                    hWindow,
                    D3DCREATE_HARDWARE_VERTEXPROCESSING,
                    &d3Params,
                    &iDirectD3D9XDevice
            )!= D3D_OK) {
        cout<<"[InitDirectX9]| Error in device"<<endl;
        iDirectD3D9X->Release();
    }
}

LRESULT CALLBACK dxOverlay::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) { return DefWindowProc(hwnd, uMsg, wParam, lParam); }

dxRender dxOverlay::CreateRender() { return dxRender(iDirectD3D9XDevice, hWindow); }

HWND dxOverlay::GetWindowHandle() { return hWindow; }

WRECT dxOverlay::GetWindowRectMY(HWND hwnd) {
    WRECT rect;
    GetWindowRect(hwnd,&rect);rect.top += 20;rect.bottom += 20;
    return rect;
}*/
