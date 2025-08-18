/*
#ifndef UNTITLEDWARE_DXRENDER_H
#define UNTITLEDWARE_DXRENDER_H

#include <iostream>
#include <d3d9.h>
#include <d3dx9core.h>
#include <windows.h>
#include <vector>
#include "lib/d3dx9tex.h"
#include "WRECT.h"

using namespace std;

class dxRender {
private:
    IDirect3DDevice9* device;
    ID3DXSprite* dxSprite;
    ID3DXLine* dxLine;
    static inline ID3DXFont* dxDefaultFont = nullptr;
    vector<int> keys = vector<int>();
    HWND hWindow;   // local window handle


public:
         dxRender            ( IDirect3DDevice9*, HWND );
         ~dxRender           (   );

    void beginRender    (   );
    void endRender      (   );

    void drawLine       ( POINT*, POINT*, D3DCOLOR, int = 1 );
    void drawBox        ( RECT* rect, D3DCOLOR color, IDirect3DTexture9* texture);
    IDirect3DTexture9** CreateTexture(RECT rect, string path);
    void drawText       ( POINT*, std::string, D3DCOLOR, ID3DXFont* fontDevice = dxDefaultFont);

    HWND GetHW();

    ID3DXFont* CreateFontDevice(int h,int w);

    static vector<int> GetARGBCode  ( D3DCOLOR );

    struct COLOR {
        static D3DCOLOR* CREATECOLOR(vector<int> color) { return new D3DCOLOR( D3DCOLOR_ARGB(color[0],color[1],color[2],color[3])); }
        static D3DCOLOR* CREATECOLOR(DWORD c) { return new D3DCOLOR(c); }
        static const inline D3DCOLOR RED =          D3DCOLOR_ARGB(255, 255, 0  , 0  );
        static const inline D3DCOLOR GREEN =        D3DCOLOR_ARGB(255, 0  , 255, 0  );
        static const inline D3DCOLOR YELLOW =       D3DCOLOR_ARGB(255, 238, 255, 0  );
        static const inline D3DCOLOR BLUE =         D3DCOLOR_ARGB(255, 0  , 0  , 255);
        static const inline D3DCOLOR WHITE =        D3DCOLOR_ARGB(255, 255, 255, 255);
        static const inline D3DCOLOR BLACK =        D3DCOLOR_ARGB(255, 0  , 0  , 0  );
        static const inline D3DCOLOR WHITEBLUE =    D3DCOLOR_ARGB(255, 0  , 183, 255);
        static const inline D3DCOLOR PURPLE =       D3DCOLOR_ARGB(255, 0  , 183, 255);
        static const inline D3DCOLOR ORANGE =       D3DCOLOR_ARGB(255, 255, 132, 0  );
        static const inline D3DCOLOR PINK =         D3DCOLOR_ARGB(255, 255, 148, 216);
        static const inline D3DCOLOR GRAY =         D3DCOLOR_ARGB(255, 125, 125, 125);
        static const inline D3DCOLOR BLACKGRAY =    D3DCOLOR_ARGB(255, 41 , 41 , 41 );
        static const inline D3DCOLOR VERYBLACKGRAY= D3DCOLOR_ARGB(255, 23 , 23 , 23 );
        static const inline D3DCOLOR BLACKBLUE =    D3DCOLOR_ARGB(255, 2  , 29 , 77 );
        static D3DCOLOR* RANDOM() {
            srand(time(NULL));
            return CREATECOLOR(vector<int>{255, rand()%255, rand()%255, rand()%255});
        }
        static void Rainbow(D3DCOLOR* scolor) {
            vector<int> color = GetARGBCode(*scolor);
            if (color[1] == 255) {
                if (color[2]==255) {
                    color[1]--;
                }
                else if (color[3]!=0) {
                    color[3]--;
                }
                else {
                    color[2]++;
                }
            }
            else if (color[2] == 255) {
                if (color[1]!=0) {
                    color[1]--;
                } else {
                    if (color[3]==255) {
                        color[2]--;
                    } else {
                        color[3]++;
                    }
                }
            }
            else if (color[3] == 255){
                if (color[2]!=0) {
                    color[2]--;
                } else {
                    if (color[1]==255) {
                        color[3]--;
                    } else {
                        color[1]++;
                    }
                }
            }
            if (color[1] !=255 && color[2]!=255 && color[3]!=255) {color[rand()%3+1]=255;}
            *scolor = *CREATECOLOR(color);
        }
        static void PULSE(D3DCOLOR* start,int speed = 10) {
            vector<int> color = GetARGBCode(*start);
            static bool up = false;
            up = color[0] == 0 || (color[0] == 255 ? false : up);
            color[0] += up ? 1*speed : -1*speed;
            color[0] = color[0] < 0 ? 0 : (color[0]>255? 255 : color[0]);
            *start=* CREATECOLOR(color);
        }
    };

private:
    static VOID WINAPI ColorFill (D3DXVECTOR4* pOut, const D3DXVECTOR2* pTexCoord,const D3DXVECTOR2* pTexelSize, LPVOID pData);
};

#endif*/
