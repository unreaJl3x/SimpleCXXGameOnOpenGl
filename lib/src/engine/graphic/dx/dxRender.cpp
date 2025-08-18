/*
#include "dxRender.h"

HWND dxRender::GetHW() { return hWindow; }

dxRender::dxRender(IDirect3DDevice9 *device, HWND handleWindow) {
    if (!device) { cout << "[dxRender constructor]| Invalid device."<<endl; return; }
    this->device = device;
    this->hWindow = handleWindow;
    if (D3DXCreateLine(device, &dxLine) != D3D_OK) { cout<<"[dxRender constructor]| Err? failure creating 'LINE' device."<<endl; }
    dxDefaultFont = dxRender::CreateFontDevice(20,30);
    if (D3DXCreateSprite(device,&dxSprite) != D3D_OK) {cout<<"[dxRender constructor]| Err? failure creating 'SPRITE' device.";}
}

ID3DXFont* dxRender::CreateFontDevice(int h, int w) {
    ID3DXFont* font;
    if (D3DXCreateFontA( device,
                     h,
                     w,
                     FW_HEAVY,
                     1,
                     false,
                     DEFAULT_CHARSET,
                     OUT_TT_ONLY_PRECIS,
                     ANTIALIASED_QUALITY,
                     DEFAULT_PITCH | FF_DONTCARE,
                     "Tahoma",
                     &font)!=D3D_OK) {cout <<"[dxRender constructor]| Err? failure creating 'FONT' device.";}

    return font;
}

dxRender::~dxRender() {
    if (device)     { device->Release(); }
    if (dxLine)     { dxLine->Release(); }
    if (dxSprite)   {  dxLine->Release(); }
    if (dxDefaultFont) { dxLine->Release(); }
}

void dxRender::beginRender() {
    if (device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 0, 0, 0), 1, 0) != D3D_OK) {
        cout<<"[beginRender]| Failed clear scene"<<endl;
    }
    device->BeginScene();
}

void dxRender::endRender() {
    device->EndScene();
    device->Present(NULL, NULL, NULL, NULL);
}

void dxRender::drawLine(POINT* start, POINT* end, D3DCOLOR color, int count) {
    bool vertx = (start->x == end->x);
    bool horiz = (start->y==end->y);
    for(int i = 0; i< count;i++) {
        dxLine->Draw(new D3DXVECTOR2[2]{D3DXVECTOR2((  vertx ? (start->x+i) : (start->x) ),
                                                    horiz ? (start->y+i):(start->y)),
                                        D3DXVECTOR2(vertx ? end->x+i : end->x, horiz?end->y+i:end->y)}, 2, color);
    }
}

void dxRender::drawText(POINT* pos, string text, D3DCOLOR color, ID3DXFont* deviceFont) {
    deviceFont->DrawTextA(NULL, text.c_str(), text.length(), new WRECT(pos->x, pos->y, pos->x,pos->y), DT_LEFT | DT_NOCLIP, color);
}

VOID WINAPI dxRender::ColorFill(D3DXVECTOR4* pOut, const D3DXVECTOR2* pTexCoord, const D3DXVECTOR2* pTexelSize, LPVOID pData){*pOut = D3DXVECTOR4(255.f / 255.f, 255.f / 255.f, 255.f / 255.f, 0.9f);
}
vector<int> dxRender::GetARGBCode(D3DCOLOR input) {
    vector<int> COLOR_ARGB;
    const int mod[4] {16777216,65536,256,1};
    unsigned long colorCode = input;

    int colorCount = 0;
    for (int m : mod) {
        while (colorCode>=m) {
            colorCode-=m;
            colorCount++;
        }
        COLOR_ARGB.push_back(colorCount);
        colorCount = 0;
    }
    return COLOR_ARGB;
}

void dxRender::drawBox(RECT* rect, D3DCOLOR color, IDirect3DTexture9* texture) {
    if (texture==nullptr) {
            const int _size = 5;
            D3DXVECTOR2 mergins[_size]{
                D3DXVECTOR2(rect->left,rect->top),
                D3DXVECTOR2(rect->left,rect->bottom),
                D3DXVECTOR2(rect->right,rect->bottom),
                D3DXVECTOR2(rect->right,rect->top),
                D3DXVECTOR2(rect->left,rect->top)
            };
            dxLine->Draw(mergins, _size, color);
            return;
        }
    else {
            dxSprite->Begin(D3DXSPRITE_ALPHABLEND);
            dxSprite->Draw(texture, NULL, NULL, new D3DXVECTOR3(rect->left+((rect->right-rect->left)/2),rect->top+((rect->bottom-rect->top)/2),0), color);
            dxSprite->End();
            return;
        }
}

IDirect3DTexture9 **dxRender::CreateTexture(RECT rect, std::string path) {
    IDirect3DTexture9 *texture;
    auto check = D3DXCreateTextureFromFileEx(device,
                                path.c_str(),
                                rect.right-rect.left,
                                rect.bottom-rect.top,
                                D3DX_DEFAULT,
                                0,
                                D3DFMT_UNKNOWN ,
                                D3DPOOL_MANAGED, D3DX_DEFAULT,D3DX_DEFAULT,0,NULL,NULL, &texture
    ) == D3D_OK;
    if (!check) {cout<<"[ERR] Cannot create texture with path ("<<path<<")";}
    return &texture;
}*/
