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
    E *cr_base = cr;
    E *ci_base = ci;
    T1 = cr_base[0];
    Tp = ci_base[0];
    {
        E T3 = cr_base[2*ms];
        E T5 = ci_base[-2*ms];
        E T2 = W[2];
        E T4 = W[3];
        T6 = T2 * T3 + T4 * T5;
        To = T2 * T5 - T4 * T3;
    }
    {
        E T9 = cr_base[ms];
        E Tb = ci_base[-ms];
        E T8 = W[0];
        E Ta = W[1];
        Tc = T8 * T9 + Ta * Tb;
        Tk = T8 * Tb - Ta * T9;
    }
    {
        E Te = cr_base[3*ms];
        E Tg = ci_base[-3*ms];
        E Td = W[4];
        E Tf = W[5];
        Th = Td * Te + Tf * Tg;
        Tl = Td * Tg - Tf * Te;
    }
    {
        E T7 = T1 + T6;
        E Ti = Tc + Th;
        ci_base[-ms] = T7 - Ti;
        cr_base[0] = T7 + Ti;
        E Tj = T1 - T6;
        E Tm = Tk - Tl;
        ci_base[0] = Tj - Tm;
        cr_base[ms] = Tj + Tm;
    }
    {
        E Tn = Tk + Tl;
        E Tq = To + Tp;
        cr_base[2*ms] = Tn - Tq;
        ci_base[-3*ms] = Tn + Tq;
        E Tr = Th - Tc;
        E Ts = Tp - To;
        cr_base[3*ms] = Tr - Ts;
        ci_base[-2*ms] = Tr + Ts;
    }
}
}
