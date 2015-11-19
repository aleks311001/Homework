#include "TXLib.h"
double XWindow = GetSystemMetrics (SM_CXSCREEN), YWindow = GetSystemMetrics (SM_CYSCREEN);

int main ()
    {
    _txWindowStyle &= ~ WS_CAPTION;

    txCreateWindow (XWindow, YWindow);

    HDC Kart = txLoadImage ("Image//Sova.bmp");

    txBitBlt (txDC (), 0, 0, 1440, 1080, Kart, 0, 0);

    for (int x = 0; x < XWindow; x++)
        {
        for (int y = 0; y < YWindow; y++)
            {
            COLORREF color = txGetPixel (x, y);
            txSetPixel (x, y, pow (2, 24) - 1 - color);/*RGB(255 - (color      ) & 0xFF,
                                  255 - (color >> 8 ) & 0xFF,
                                  255 - (color >> 16) & 0xFF));  */
            }
        }

    txDeleteDC (Kart);
    }
