
#include "TXLib.h"

int SZ_MAX = 20;

void FillArray_ran        (int data [], int sz, int Min = 100, int Max = 999);
void FillArray_Ar_Prog    (int data [], int sz, int nachal, int prib);
void FillArray_Fibbonachi (int data [], int sz);
void Fill1                (int data [], int sz);
void Fill2                (int data [], int sz);
void Fill3                (int data [], int sz);
void Fill4                (int data [], int sz);
void Fill5                (int data [], int sz);
void ROL                  (int data [], int sz);
void ROR                  (int data [], int sz);
void rev                  (int data [], int sz);
void rev_ryadom           (int data [], int sz);
void ROL2                 (int data [], int sz, int sdvig);
void Sravn          (const int data [], int sz, int *Pos_naim, int *Pos_naib);
void PoUmensheniu         (int data [], int sz);
void Chetnoe              (int data [], int sz, int data_Chet [], int *k/*, int data_NeChet [], int *m, int data_Del3 [], int *f*/);
void PrintArray     (const int data [], int sz, const char name [],  unsigned  colors = 0x07);
void PrintArray_Zagruzk                    (int sz);
void MEnyem               (int data [], const int t1, const int t2);

void Nahodim_Naimenshee   (int data [], int Min, int Max, int *Nomer_naim);
void Sort_Vibor           (int data [], int sz);
void Sort_Puzirk          (int data [], int sz);
void Sort_Podschetom      (int data [], int sz);
void Nah_naib_i_men       (int data [], int left, int right, int *Perest);
void Sort_Shek            (int data [], int sz);
void Chast_Quick2         (int data [], int sz, int left2, int right2);
void Quick         (int data [], int left2, int right2);
int rando                 (int mini,    int maxi);

void dz1 ();
void dz2 ();
void dz3 ();
void dz4 ();
void dz5 ();

int main()
    {
    //txCreateWindow (800, 800);

    //PrintArray_Zagruzk (1);
    printf ("*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n\n");

    //----------------------------------------------------
    dz5 ();
    }

void dz1 ()
    {
    int            data_ran [20] = {};
    FillArray_ran (data_ran, 20);
    PrintArray    (data_ran, 20, "Random", 0x09);

    int                data_ar_pr [20] = {};
    FillArray_Ar_Prog (data_ar_pr, 20, rando (10, 99), rando (11, 111));
    PrintArray        (data_ar_pr, 20, "Ar_Prog", 0x0A);

    int                   data_Fibbonachi [45] = {};
    FillArray_Fibbonachi (data_Fibbonachi, 45);
    PrintArray           (data_Fibbonachi, 45, "Fibbonachi", 0x0B);
    }

void dz2 ()
    {
    int         data1 [20] = {};
    Fill1      (data1, 20);
    PrintArray (data1, 20, "123", 0x0C);

    int         data2 [20] = {};
    Fill2      (data2, 20);
    PrintArray (data2, 20, "12321", 0x0D);

    int         data3 [20] = {};
    Fill3      (data3, 20);
    PrintArray (data3, 20, "123321", 0x0E);

    int         data4 [16] = {};
    Fill4      (data4, 16);
    PrintArray (data4, 16, "13579", 0x09);

    int         data5 [18] = {};
    Fill5      (data5, 18);
    PrintArray (data5, 18, "123789", 0x0A);
    }

void dz3 ()
    {
    int szROL = 20;
    int            dataROL [20] = {};
    FillArray_ran (dataROL, szROL);
    PrintArray    (dataROL, szROL, "ROL", 0x0B);
    ROL           (dataROL, szROL);
    PrintArray    (dataROL, szROL, "ROL", 0x0B);

    int szROR = 20;
    int    dataROR [20] = {};
    FillArray_ran (dataROR, 20);
    PrintArray    (dataROR, 20, "ROR", 0x0C);
    ROR           (dataROR, 20);
    PrintArray    (dataROR, 20, "ROR", 0x0C);

    int    data_rev [20] = {};
    FillArray_ran (data_rev, szROR);
    PrintArray    (data_rev, szROR, "rev", 0x0D);
    rev           (data_rev, szROR);
    PrintArray    (data_rev, szROR, "rev", 0x0D);

    int szRev_Ryd = 20;
    int    data_rev_ryadom [20] = {};
    FillArray_ran (data_rev_ryadom, szRev_Ryd);
    PrintArray    (data_rev_ryadom, szRev_Ryd, "rev_ryadom", 0x0E);
    rev_ryadom    (data_rev_ryadom, szRev_Ryd);
    PrintArray    (data_rev_ryadom, szRev_Ryd, "rev_ryadom", 0x0E);

    int szAB = 11;
    int    dataAB [11] = {};
    FillArray_ran (dataAB, szAB);
    PrintArray    (dataAB, szAB, "ROL2", 0x09);
    ROL2          (dataAB, szAB, 5);
    PrintArray    (dataAB, szAB, "ROL2", 0x09);
    }

void dz4 ()
    {
    int szSr = 20;
    int            dataSravn [20] = {};
    FillArray_ran (dataSravn, szSr);
    PrintArray    (dataSravn, szSr, "Сравнение", 0x0A);
    int n = 0;
    int k = 0;
    Sravn         (dataSravn, szSr, &n, &k);
    printf ("\nНаименьшее : %d, Наибольшее : %d \n\n*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*", n + 1, k + 1);

    int szChet = 20;
    int            dataPrimer  [20] = {};
    int            dataChet    [10] = {};
  /*int            dataNeChet  [20] = {};
    int            dataDel3    [20] = {};*/
    FillArray_ran (dataPrimer,  szChet);
    PrintArray    (dataPrimer,  szChet, "Четное", 0x0B);
    /*int j = 0;
    k = 0,*/ n = 0;
    Chetnoe       (dataPrimer,  szChet, dataChet, &n/*, dataNeChet, &k, dataDel3, &j*/);
    PrintArray    (dataChet,    n,  "Четные, слева нечетные, справа четные", 0x0B);
  /*PrintArray    (dataNeChet,  k,  "Нечетные слево от четных", 0x0B);
    PrintArray    (dataDel3,    j,  "Делятся на 3 справо от четных", 0x0B);  */

    int szUmensh = 20;
    int            dataPrimer2 [20] = {};
    FillArray_ran (dataPrimer2, szUmensh);
    PrintArray    (dataPrimer2, szUmensh, "Уменьшение", 0x0C);
    PoUmensheniu  (dataPrimer2, szUmensh);
    PrintArray    (dataPrimer2, szUmensh, "Уменьшение", 0x0C);
    }

void dz5 ()
    {
    int szSortirovka = 20;
    int            Sortirovka [szSortirovka];
    FillArray_ran (Sortirovka, szSortirovka);
    PrintArray    (Sortirovka, szSortirovka, "Selection", 0x0A);
    Sort_Vibor    (Sortirovka, szSortirovka);
    PrintArray    (Sortirovka, szSortirovka, "Selection", 0x0A);

    int szPuzirk = 20;
    int            Puzirk [szPuzirk];
    FillArray_ran (Puzirk, szPuzirk);
    PrintArray    (Puzirk, szPuzirk, "Bubble", 0x0B);
    Sort_Puzirk   (Puzirk, szPuzirk);
    PrintArray    (Puzirk, szPuzirk, "Bubble", 0x0B);

    int szPodschet = 20;
    int              Podschet [szPodschet];
    FillArray_ran   (Podschet, szPodschet, 1, 3);
    PrintArray      (Podschet, szPodschet, "Подсчет", 0x0C);
    Sort_Podschetom (Podschet, szPodschet);
    PrintArray      (Podschet, szPodschet, "Подсчет", 0x0C);

    int szSheker = 20;
    int            Sheker [szSheker];
    FillArray_ran (Sheker, szSheker);
    PrintArray    (Sheker, szSheker, "Шекер", 0x0D);
    Sort_Shek     (Sheker, szSheker);
    PrintArray    (Sheker, szSheker, "Шекер", 0x0D);

    int szQuick = 20;
    int            Quick1 [szQuick];
    FillArray_ran (Quick1, szQuick);
    PrintArray    (Quick1, szQuick, "Quick", 0x0E);
    Quick         (Quick1, 0, szQuick);
    PrintArray    (Quick1, szQuick, "Quick", 0x0E);
    }

void FillArray_Ar_Prog    (int data [], int sz, int nachal, int prib)
    {
    for (int i = 0; i < sz; i ++)
        {
        assert (0 <= i && i < sz);
        data [i] = nachal + prib * i;
        }
    }

void FillArray_Fibbonachi (int data [], int sz)
    {
    data [0] = 1;
    data [1] = 1;
    for (int i = 2; i < sz; i ++)
        {
        assert (0 <= i     && i < sz);
        assert (0 <= i - 1 && i - 1 < sz);
        assert (0 <= i - 2 && i - 2 < sz);
        data [i] = data [i - 1] + data [i - 2];
        }
    }

void FillArray_ran        (int data [], int sz, int Min/*=100*/, int Max/*=999*/)
    {
    for (int i = 0; i < sz; i ++)
        {
        assert (0 <= i && i < sz);
        data [i] = rando (Min, Max);
        }
    }

void PrintArray     (const int data [], int sz, const char name [], unsigned  colors)
    {
    txSetConsoleAttr (colors);
    printf ("\n%s:", name);
    if (sz != 0)
        {
        for (int i = 0; i < sz; i ++)
            {
            assert (0 <= i && i < sz);
            printf ("[%d]:%d,", i, data[i]);
            if (i%8 == 7) printf ("\n");
            }
        }
    else printf ("таких нет");
    printf ("\n");
    printf ("\n*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
    }

void PrintArray_Zagruzk                    (int sz)
    {
    for (int i = 0; i < sz; i ++)
        {
        assert (0 <= i && i < sz);
        for (int i = 0; i < 100; i++)
            {
            txSetConsoleAttr (0x09);
            printf ("*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
            }

        for (int i = 0; i < 100; i++)
            {
            txSetConsoleAttr (0x0A);
            printf ("*Кот*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
            }

        for (int i = 0; i < 100; i++)
            {
            txSetConsoleAttr (0x0B);
            printf ("*Кот*Кот*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
            }

        for (int i = 0; i < 100; i++)
            {
            txSetConsoleAttr (0x0C);
            printf ("*Кот*Кот*Кот*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
            }

        for (int i = 0; i < 100; i++)
            {
            txSetConsoleAttr (0x0D);
            printf ("*Кот*Кот*Кот*Кот*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
            }

        for (int i = 0; i < 100; i++)
            {
            txSetConsoleAttr (0x0E);
            printf ("*Кот*Кот*Кот*Кот*Кот*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
            }

        for (int i = 0; i < 100; i++)
            {
            txSetConsoleAttr (0x09);
            printf ("*Кот*Кот*Кот*Кот*Кот*Кот*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
            }

        for (int i = 0; i < 100; i++)
            {
            txSetConsoleAttr (0x0A);
            printf ("*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
            }

        for (int i = 0; i < 100; i++)
            {
            txSetConsoleAttr (0x0B);
            printf ("*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
            }

        for (int i = 0; i < 100; i++)
            {
            txSetConsoleAttr (0x0C);
            printf ("*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
            }

        for (int i = 0; i < 100; i++)
            {
            txSetConsoleAttr (0x0D);
            printf ("*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
            }

        for (int i = 0; i < 100; i++)
            {
            txSetConsoleAttr (0x0E);
            printf ("*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*Кот*-_-*-_-*-_-*-_-*-_-*-_-*-_-*\n");
            }

        }
    }

int rando (int mini, int maxi)
    {
    return rand() % (maxi - mini + 1) + mini;
    }

void Fill1                (int data [], int sz)
    {
    for (int i = 0; i < sz; i++)
        {
        assert (0 <= i && i < sz);
        data [i] = i%3 + 1;
        }
    }

void Fill2                (int data [], int sz)
    {
    data [0] = 1;
    data [1] = 2;
    for (int i = 2; i < sz; i++)
        {
        assert (0 <= i     &&     i < sz);
        if (i%2 == 1) data [i] = 2;
        else
            {
            assert (0 <= i - 2 && i - 2 < sz);
            if (data [i - 2] == 1) data[i] = 3;
            else data [i] = 1;
            }
        }
    }

void Fill3                (int data [], int sz)
    {
    data [0] = 1;
    data [1] = 2;
    data [2] = 3;
    data [3] = 3;
    for (int i = 4; i < sz; i++)
        {
        assert (0 <= i && i < sz);
        if (i%3 == 1) data [i] = 2;
        else
            {
            assert (0 <= i - 3 && i - 3 < sz);
            assert (0 <= i - 2 && i - 2 < sz);
            assert (0 <= i - 4 && i - 4 < sz);
            if (data [i - 2] == 3 && data [i - 3] == 3 || data [i - 3] == 3 && data [i - 4] == 3) data [i] = 1;
            else data [i] = 3;
            }
        }
    }

void Fill4                (int data [], int sz)
    {
    for (int i = 1, k = 8, n = 0; i < sz; i++, n++)
        {
        if (n%2 == 1) k = -k;
        if (n > 0 && n%2 == 0) k = -k;
        assert (0 <= sz/2 - k && sz/2 - k < sz);
        data [sz/2 - k] = i;
        if (n%2 == 0) k --;
        }
    data [sz / 2] = sz + 0.5;
    }

void Fill5                (int data [], int sz)
    {
    for (int i = 0, k = 0, n = -2; i < sz; i++, k++)
        {
        assert (0 <= i && i < sz);
        if (i < sz/2)
            {
            if (k%3 == 0) n+=3;
            data [i] = n + i;
            }
        if (i >= sz/2)
            {
            if (k%3 == 0) n-=3;
            n-=2;
            data [i] = n + i + 7;
            }
        }
    }

void ROL                  (int data [], int sz)
    {
    for (int i = 0; i < sz; i++)
        {
        int t = data [0];
        assert (0 <= i && i < sz);
        if (i + 1 < sz)
            {
            data [i] = data [i + 1];
            assert (0 <= i + 1 && i + 1 < sz);
            }
        else data [i] = t;
        }
    }

void ROR                  (int data [], int sz)
    {
    for (int i = 0, t = data [sz]; i < sz; i++)
        {
        assert (0 <= sz - i - 1 && sz - i - 1 < sz);
        if (sz - i - 1 > 0) data [sz - i - 1] = data [sz - i - 2];
        else data [0] = t;
        }
    }

void rev                  (int data [], int sz)
    {
    for (int i = 0; i < sz / 2; i++)
        {
        assert (0 <= i          && i          < sz);
        assert (0 <= sz - i - 1 && sz - i - 1 < sz);

        int t = data [i];
                data [i] = data [sz - i - 1];
                           data [sz - i - 1] = t;
        }
    }

void rev_ryadom           (int data [], int sz)
    {
    for (int i = 0, t = 0; i < sz; i+=2)
        {
        assert (0 <= i     && i     < sz);
        assert (0 <= i + 1 && i + 1 < sz);
        t             = data [i];
                        data [i]      = data [i + 1];
                                        data [i + 1]  = t;
        }
    }

void ROL2                 (int data [], int sz, int sdvig)
    {
    int i = sdvig;
    int k = data [0];
    data [0] = data [sdvig];

    for (int n = 0; n < sz - 2; n++)
        {
        assert (0 <=  i             &&  i             < sz);
        assert (0 <= (i + sdvig)%sz && (i + sdvig)%sz < sz);

        data [i] = data [(i + sdvig)%sz];

        if (i + sdvig < sz)i = i + sdvig;
        else               i = i + sdvig - sz;
        }

    data [i] = k;
    }

void Sravn          (const int data [], int sz, int *Pos_naim, int *Pos_naib)
    {
    int naim = data [0];
    int naib = data [0];

    for (int i = 0; i < sz; i++)
        {
        assert (0 <= i && i < sz);

        if (data [i] >= naib) *Pos_naib = i, naib = data [i];
        if (data [i] <= naim) *Pos_naim = i, naim = data [i];
        }
    }

void Chetnoe              (int data [], int sz, int data_Chet [], int *k/*, int data_NeChet [], int *m, int data_Del3 [], int *f*/)
    {
    int Chet = 0;
    /*int h = 0;
    int j = 0;*/
    for (int i = 1; i < sz - 1; i++)
        {
        assert (0 <= i     && i     < sz + 1);
        assert (0 <= i - 1 && i - 1 < sz + 1);
        assert (0 <= i + 1 && i + 1 < sz + 1);
        if (data [i]%2 == 0 && data [i - 1]%2 == 1 && data [i + 1]%3 == 0)
            {
            assert (0 <= Chet && Chet < sz);
            data_Chet [Chet] = i + 1;
            Chet++;
            /*if (i > 0 && data [i - 1]%2 == 1)
                {
                assert (0 <= h && h < sz);
                data_NeChet [h] = i;
                h++;
                }
            if (i < sz - 1 && data [i + 1]%3 == 0)
                {
                assert (0 <= j && j < sz);
                data_Del3 [j] = i + 2;
                j++;
                } */
            }
        }
    *k = Chet;
    /*m = h;
    *f = j;*/
    }

void MEnyem               (int data [], const int t1, const int t2)
    {
    assert (0 <= t1 && t1 < SZ_MAX);
    assert (0 <= t2 && t2 < SZ_MAX);
    int t =     data [t1];
    data [t1] = data [t2];
    data [t2] = t;
    }

void PoUmensheniu         (int data [], int sz)
    {
    for (int i = 0, naim = 0, s = 0; i < sz; i++)
        {
        assert (0 <= sz - i - 1 && sz - i - 1 < sz);
        assert (0 <= naim       && naim       < sz);
        Sravn  (data, sz - i - 1, &naim, &s);
        MEnyem (data, naim, sz - i - 1);
        }
    }

void Nahodim_Naimenshee   (int data [], int Min, int Max, int *Nomer_naim)
    {
    int naim = data [Min];

    for (int i = Min; i < Max; i++)
        {
        assert (0 <= i && i < SZ_MAX);
        if (data [i] <= naim) *Nomer_naim = i, naim = data [i];
        }
    }

void Nah_naib_i_men       (int data[], int left, int right, int *Perest)
    {
    if (left <= right)
        {
        for (int i = left + 1; i < right; i++)
            {
            assert (0 <= i     && i     < SZ_MAX);
            assert (0 <= i - 1 && i - 1 < SZ_MAX);
            if (data [i] < data [i - 1])
                {
                MEnyem (data, i - 1, i);
                Perest ++;
                }
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
                MEnyem (data, i + 1, i);
                Perest++;
                }
            }
        }
    }

void Sort_Vibor           (int data [], int sz)
    {
    int Min = 0;
    int Naim = 0;
    for (int i = 0; i < sz; i++)
        {
        Nahodim_Naimenshee (data, Min, sz, &Naim);
        MEnyem (data, Naim, i);
        Min ++;
        }
    }

void Sort_Puzirk          (int data [], int sz)
    {
    int t = sz;
    int per = 1;
    for (int i = 0; i < sz; i++)
        {
        Nah_naib_i_men (data, 0, t--, &per);
        if (per <= 0) break;
        }
    }

void Sort_Podschetom      (int data [], int sz)
    {
    int Kol_vo1 = 0, Kol_vo2 = 0;
    for (int i = 0; i < sz; i ++)
        {
        assert (0 <= i && i < sz);
        if (data [i] == 1)
            {
            Kol_vo1 ++;
            }
        if (data [i] == 2)
            {
            Kol_vo2 ++;
            }
        }
    int Kol_vo3 = sz - Kol_vo1 - Kol_vo2;
    printf ("%d, %d, %d.", Kol_vo1, Kol_vo2, Kol_vo3);
    for (int i = 0; i < sz; i++)
        {
        assert (0 <= i && i < sz);
        if (i < Kol_vo1) data [i] = 1;
        if (i < Kol_vo2 + Kol_vo1 && Kol_vo1 <= i)data [i] = 2;
        if (i >= Kol_vo2 + Kol_vo1 && i < sz)data [i] = 3;
        }
    }

void Sort_Shek            (int data [], int sz)
    {
    int per = 0;
    int left = 0, right = sz;
    for (int i = 0; i < sz / 2; i++)
        {
        Nah_naib_i_men (data, left,  right --, &per);
        Nah_naib_i_men (data, right, left  ++, &per);
        if (per = 0) break;
        }
    }

void Chast_Quick2          (int data [], int sz, int left2, int right2)
    {
    int left = left2;
    int right = right2 - 1;
    int centr = (right + left + 1) / 2;

    while (left < right)
        {
        if (centr == right) centr = left;
        if (centr == left)  centr = right;
        while (data[left]  < data[centr] && left <= right2)
            {left ++; }
        while (data[right] > data[centr] && right >= left2)
            {right--; }

        if (left <= right)
            {
            MEnyem(data, left, right);
            }
        }
    }

void Quick                 (int data [], int left, int right)
    {
    int t_left 	= left;
    int t_right = right;
    int centr = data[(t_left + t_right) / 2];

    for (int i = 0; t_left <= t_right; i++)
        {
        while (data[t_left]  < centr /*&& t_left  <= right*/) t_left++;
        while (data[t_right] > centr /*&& t_right >= left*/)  t_right--;

        if (t_left <= t_right)
            {
            MEnyem (data, t_right, t_left);
            t_left++;
            t_right--;
            }
        }

        if (t_right > left) Quick (data, left, t_right);
        if (t_left < right) Quick (data, t_left, right);

    }

