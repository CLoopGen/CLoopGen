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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + ((mb - 1) * 6); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 6 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Tp, T6, To, Tc, Tk, Th, Tl;
    T1 = cr[0];
    Tp = ci[0];

    {
        E T3, T5, T2, T4;
        T3 = cr[(rs[2])];
        T5 = ci[(rs[2])];
        T2 = W[2];
        T4 = W[3];
        T6 = T2 * T3 + T4 * T5;
        To = T2 * T5 - T4 * T3;
    }

    {
        E T9, Tb, T8, Ta;
        T9 = cr[(rs[1])];
        Tb = ci[(rs[1])];
        T8 = W[0];
        Ta = W[1];
        Tc = T8 * T9 + Ta * Tb;
        Tk = T8 * Tb - Ta * T9;
    }

    {
        E Te, Tg, Td, Tf;
        Te = cr[(rs[3])];
        Tg = ci[(rs[3])];
        Td = W[4];
        Tf = W[5];
        Th = Td * Te + Tf * Tg;
        Tl = Td * Tg - Tf * Te;
    }

    E sum_ch = T1 + T6 + Tc + Th;
    E diff_cT = (T1 - T6) + (Tk - Tl);
    E sum_TkTp = Tk + Tl + Tp + To;
    E diff_hc = (Th - Tc) + (Tp - To);

    cr[0] = sum_ch;
    ci[(rs[1])] = (T1 + T6) - (Tc + Th);
    ci[0] = (T1 - T6) - (Tk - Tl);
    cr[(rs[1])] = diff_cT;

    cr[(rs[2])] = (Tk + Tl) - (To + Tp);
    ci[(rs[3])] = sum_TkTp;
    cr[(rs[3])] = (Th - Tc) - (Tp - To);
    ci[(rs[2])] = diff_hc;
}
}
