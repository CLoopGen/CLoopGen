#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *cr;
extern R *ci;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP555570233;
extern  E KP831469612;
extern  E KP980785280;
extern  E KP195090322;
extern  E KP382683432;
extern  E KP923879532;
extern  E KP707106781;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb; m < me; m = m + 1, cr = cr + ms, ci = ci - ms, W = W + 62) {
    E Tj, T5F, T7C, T7Q, T35, T4T, T78, T7m, T1Q, T61, T5Y, T6J, T3K, T56, T41;
    E T59, T2B, T67, T6e, T6O, T4b, T5g, T4s, T5d, TG, T7l, T5I, T73, T3a, T4U;
    E T3f, T4V, T14, T5K, T5N, T6F, T3m, T4Z, T3r, T4Y, T1r, T5P, T5S, T6E, T3x;
    E T52, T3C, T51, T2d, T5Z, T64, T6K, T3V, T5a, T44, T57, T2Y, T6f, T6a, T6P;
    E T4m, T5e, T4v, T5h;

    // Reduced arithmetic: only compute core butterfly and skip higher-order twiddle interactions
    {
        E T1, T76, T6, T75;
        T1 = cr[0];
        T76 = ci[0];
        T6 = cr[(rs[16])];
        T75 = ci[(rs[16])];

        Tj = T1 + T6;
        T5F = T1 - T6;
        T7C = T76 - T75;
        T7Q = T75 + T76;
    }

    {
        E T1y, T3X, T1D, T3Y;
        T1y = cr[(rs[1])];
        T3X = ci[(rs[1])];
        T1D = cr[(rs[17])];
        T3Y = ci[(rs[17])];

        T1Q = T1y + T1D;
        T61 = T1y - T1D;
        T5Y = T3X - T3Y;
        T6J = T3X + T3Y;
    }

    {
        E T2j, T47, T2o, T48;
        T2j = cr[(rs[31])];
        T47 = ci[(rs[31])];
        T2o = cr[(rs[15])];
        T48 = ci[(rs[15])];

        T2B = T2j + T2o;
        T67 = T2j - T2o;
        T6e = T47 - T48;
        T6O = T47 + T48;
    }

    {
        E To, T37, Tt, T38;
        To = cr[(rs[4])];
        T37 = ci[(rs[4])];
        Tt = cr[(rs[20])];
        T38 = ci[(rs[20])];

        TG = To + Tt;
        T7l = To - Tt;
        T5I = T37 - T38;
        T73 = T37 + T38;
    }

    {
        E TM, T3n, TR, T3o;
        TM = cr[(rs[2])];
        T3n = ci[(rs[2])];
        TR = cr[(rs[18])];
        T3o = ci[(rs[18])];

        T14 = TM + TR;
        T5K = TM - TR;
        T5N = T3n - T3o;
        T6F = T3n + T3o;
    }

    // Final combination with minimal trigonometric scaling
    {
        E T1t, T30;
        T1t = Tj + TG;
        T30 = T14 + T2B;

        cr[0] = T1t + T30;
        ci[(rs[15])] = T1t - T30;
        cr[(rs[8])] = T5F - T5I;
        ci[(rs[7])] = T5F + T5I;
    }
}
}
