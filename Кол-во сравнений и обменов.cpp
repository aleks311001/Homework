
#include "TXLib.h"

typedef void (Srav_Obm_t) (int mass[], int sz, int *Obshee_Kol_vo_Sr, int *Obshee_Obmenov);

struct Knop
    {
    double x, y;
    double ZoomX;
    double ZoomY;
    HDC vkl, vikl;
    COLORREF color;
    Srav_Obm_t * KOL_VO;
    const char* tekst;
    };

const double XWindow = 1000, YWindow = 800;

const int SZ_MAX = 201;

int Ob_Quick = 0, Sr_Quick = 0;

void Draw_Graf          (int Mass [], Srav_Obm_t Kol_vo, double ZoomX, double ZoomY, COLORREF color);
void Draw_Graf_Raz      (double x, double y, double ZoomX, double ZoomY, int sz, int Ob);
void MEnyem             (int data [], const int t1, const int t2);
int  Nahodim_Naimenshee (int data [], int Min, int Max, int *Nomer_naim);
void Nah_naib_i_men     (int data [], int left, int right, int *Perest, int *Sr, int *Ob);
void Selection          (int mass [], int sz, int *Obshee_Kol_vo_Sr, int *Obshee_Obmenov);
void Bubble             (int data [], int sz, int *Obshee_Kol_vo_Sr, int *Obshee_Obmenov);
void Shaker             (int data [], int sz, int *Obshee_Kol_vo_Sr, int *Obshee_Obmenov);
void Quick              (int data [], int sz, int *Obshee_Kol_vo_Sr, int *Obshee_Obmenov);
void Quick0             (int data [], int left, int right);
void FillArray_ran      (int data [], int sz, int Min = 100, int Max = 999);
void Knopka  (Knop * Kn, int Data []);
void text (const char * text, double x, double y);
void VSE ();

int main()
    {
    txCreateWindow (XWindow, YWindow);

    VSE ();

    return 0;
    }

void VSE ()
    {
    HDC Knopka_Vkl  = txLoadImage ("Image//Knopka_Vkl.bmp");
    HDC Knopka_Vikl = txLoadImage ("Image//Knopka_Vikl.bmp");
    HDC Fon         = txLoadImage ("Image//‘ÓÌ.bmp");
    Knop Kn[4]   = {{250, 60, 1.75, 0.1, Knopka_Vkl, Knopka_Vikl, RGB(255, 0,   0)  , Selection,  "Selection"},
                    {380, 60, 1.75, 0.1, Knopka_Vkl, Knopka_Vikl, RGB(0,   255, 0)  , Bubble   ,  "Bubble"   },
                    {510, 60, 1.75, 0.1, Knopka_Vkl, Knopka_Vikl, RGB(0,   0,   255), Shaker   ,  "Shaker"   },
                    {640, 60, 1.75, 0.1, Knopka_Vkl, Knopka_Vikl, RGB(255,   255, 0), Quick    ,  "Quick"    }};

    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txBegin();
        txTransparentBlt (txDC(), 0, 0, XWindow, YWindow, Fon, 0, 0, TX_BLACK);
        Draw_Graf_Raz (74,               726, 1.75, 0.1, 201,  6270);
        Draw_Graf_Raz (XWindow / 2 + 59, 726, 1.75, 0.1, 201,  6270);

        int Data  [201] = {};
        FillArray_ran (Data , 201, 100, 999);

        Knopka (&Kn[0], Data);

        //int Data2 [201] = {};
        FillArray_ran (Data, 201, 100, 999);

        Knopka (&Kn[1], Data);

        //int Data3 [201] = {};
        FillArray_ran (Data, 201, 100, 999);

        Knopka (&Kn[2], Data);

        //int Data4 [201] = {};
        FillArray_ran (Data, 201, 100, 999);

        Knopka (&Kn[3], Data);
        txEnd();
        }
    }

void Draw_Graf (int Mass[], Srav_Obm_t Kol_vo, double ZoomX, double ZoomY, COLORREF color)
    {
    int Sr = 0;
    int Ob = 0;
    for (int sz = 1; sz < SZ_MAX; sz++)
        {
        assert (0 <= sz && sz < SZ_MAX);
        Kol_vo (Mass, sz, &Sr, &Ob);
        FillArray_ran (Mass, sz, 100, 999);
        txSetColor (color);
        txSetFillColor (color);
        txCircle (sz * ZoomX + 74              , -Sr * ZoomY + YWindow - 74, 2);
        txCircle (sz * ZoomX + XWindow / 2 + 59, -Ob * ZoomY + YWindow - 74, 2);
        Sr = 0;
        Ob = 0;
        //txSleep (0);
        }
    }

void Draw_Graf_Raz (double x, double y, double ZoomX, double ZoomY, int sz, int Ob)
    {
    txSetColor (TX_BLACK);
    for (int i = 0; i <= sz; i += (sz/4))
        {
        txLine (x + ZoomX * i, y, x + ZoomX * i, y + 5);
        text ("ewr", x + ZoomX * i - 10, y + 5);
        }
    for (int i = 0; i <= Ob; i += (Ob/4))
        {
        txLine (x, y - ZoomY * i, x - 5, y - ZoomY * i);
        text ("sdt", x - 40,  -ZoomY * i + y);
        }
    }

int  Nahodim_Naimenshee (int data [], int Min, int Max, int *Nomer_naim)
    {
    int naim = data [Min];
    int Kol_vo_Sravn = 0;

    for (int i = Min; i < Max; i++)
        {
        assert (0 <= i && i < SZ_MAX);
        if (data [i] <= naim) *Nomer_naim = i, naim = data [i];
        Kol_vo_Sravn ++;
        }
    return Kol_vo_Sravn;
    }

void MEnyem             (int data [], const int t1, const int t2)
    {
    assert (0 <= t1 && t1 < SZ_MAX);
    assert (0 <= t2 && t2 < SZ_MAX);
    int t =     data [t1];
    data [t1] = data [t2];
    data [t2] = t;
    }

void Nah_naib_i_men     (int data[], int left, int right, int *Perest, int *Sr, int *Ob)
    {
    int Sr2 = 0;
    int Ob2 = 0;
    if (left <= right)
        {
        for (int i = left + 1; i < right; i++)
            {
            assert (0 <= i     && i     < SZ_MAX);
            assert (0 <= i - 1 && i - 1 < SZ_MAX);
            if (data [i] < data [i - 1])
                {
                Ob2 ++;
                MEnyem (data, i - 1, i);
                Perest ++;
                }
            //if (data [i] <= data [i - 1]) Ob2 ++;
            Sr2 ++;
            }
        }
    else
        {
        for (int i = left - 1; i >= right; i--)
            {
            assert (0 <= i     && i     < SZ_MAX);
            assert (0 <= i + 1 && i + 1 < SZ_MAX);
            if (data [i] > data [i + 1])
                {
                Ob2 ++;
                MEnyem (data, i + 1, i);
                Perest++;
                }
            //if (data [i] >= data [i + 1]) Ob2 ++;
            Sr2 ++;
            }
        }
    *Sr  = Sr2;
    *Ob += Ob2;
    }

void Selection          (int mass [], int sz, int *Obshee_Kol_vo_Sr, int *Obshee_Obmenov)
    {
    int Naim = 0;
    *Obshee_Kol_vo_Sr = 0;
    int Obm  = 0;

    for (int i = 0, Min = 0; i < sz; i++, Min ++)
        {
        assert (0 <= i && i < sz);
        *Obshee_Kol_vo_Sr += Nahodim_Naimenshee (mass, Min, sz, &Naim);
        MEnyem (mass, Naim, i);
        Obm ++;
        }
    *Obshee_Obmenov = Obm;
    }

void Bubble             (int data [], int sz, int *Obshee_Kol_vo_Sr, int *Obshee_Obmenov)
    {
    int t = sz;
    int per = 1;
    int Ob = 0;

    for (int i = 0, Sr = 0; i < sz; i++)
        {
        assert (0 <= i && i < sz);
        Nah_naib_i_men (data, 0, t--, &per, &Sr, &Ob);
        *Obshee_Obmenov += Ob;
        *Obshee_Kol_vo_Sr += Sr;
        if (per = 0) break;
        }
    }

void Shaker             (int data [], int sz, int *Obshee_Kol_vo_Sr, int *Obshee_Obmenov)
    {
    int per = 0;
    int left = 0, right = sz;
    int Sr = 0, Ob = 0;

    for (int i = 0; i < sz / 2; i++)
        {
        Nah_naib_i_men (data, left,  right --, &per, &Sr, &Ob);
        *Obshee_Kol_vo_Sr += Sr;
        *Obshee_Obmenov += Ob;
        Nah_naib_i_men (data, right, left  ++, &per, &Sr, &Ob);
        *Obshee_Kol_vo_Sr += Sr;
        *Obshee_Obmenov += Ob;
        if (per = 0) break;
        }
    }

void Quick0             (int data [], int left, int right)
    {
    int t_left 	= left;
    int t_right = right;
    int centr = data[(t_left + t_right) / 2];

    while (t_left <= t_right)
        {
        while (data[t_left]  < centr) {t_left++; Sr_Quick ++;}
        while (data[t_right] > centr) {t_right--; Sr_Quick ++;}

        if (t_left <= t_right)
            {
            MEnyem (data, t_right, t_left);
            Ob_Quick ++;
            t_left++;
            t_right--;
            }
        }

        if (t_right > left)  Quick0 (data, left, t_right);
        if (t_left  < right) Quick0 (data, t_left, right);
    }

void Quick              (int data [], int sz, int *Obshee_Kol_vo_Sr, int *Obshee_Obmenov)
    {
    Sr_Quick = 0, Ob_Quick = 0;
    Quick0 (data, 0, sz);
    //printf ("[%d] %d | ", sz, Sr_Quick);
    *Obshee_Kol_vo_Sr = Sr_Quick;
    *Obshee_Obmenov   = Ob_Quick;
    }

void FillArray_ran      (int data [], int sz, int Min/*=100*/, int Max/*=999*/)
    {
    for (int i = 0; i < sz; i ++)
        {
        assert (0 <= i && i < sz);
        data [i] = random (Min, Max);
        }
    }

void text (const char * text, double x, double y)
    {
    txSelectFont ("Comic Sans MS", 15, 7, 0, false, false, false, 0);
    txTextOut (x, y, text);
    }

void Knopka (Knop * Kn, int Data [])
    {
    HDC dc = NULL;

    if (txMouseX() < Kn->x + 50 && txMouseX() > Kn->x - 50 && txMouseY() < Kn->y + 25 && txMouseY() > Kn->y - 25)
        {
        if (txMouseButtons() == 1)
            {
            Draw_Graf (Data, Kn->KOL_VO, Kn->ZoomX, Kn->ZoomY, Kn->color);
            }
        dc = Kn->vkl;
        }
    else
        {
        dc = Kn->vikl;
        }
    txBitBlt (txDC(), Kn->x - 50, Kn->y - 25, 100, 50, dc, 0, 0);
    txSetColor (TX_BLACK);
    text (Kn->tekst, Kn->x - 43, Kn->y - 17);
    }
