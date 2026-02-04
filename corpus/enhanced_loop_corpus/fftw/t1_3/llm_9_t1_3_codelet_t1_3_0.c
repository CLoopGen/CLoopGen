#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP866025403;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 4); m < me && m < mb + 1; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, Ti, T6, Te, Tb, Tf, Tc, Th;
    T1 = ri[0];
    Ti = ii[0];

    for (INT unroll_factor = 0; unroll_factor < 3; ++unroll_factor) {
        E Tr, Ti_temp;
        E T3, T5, T2, T4;
        E T8, Ta, T7, T9;
        E Td, Tg, Tj, Tk;

        INT idx_r = (unroll_factor == 0) ? 0 : (unroll_factor == 1) ? rs[1] : rs[2];
        INT idx_i = (unroll_factor == 0) ? 0 : (unroll_factor == 1) ? rs[1] : rs[2];

        Tr = ri[idx_r];
        Ti_temp = ii[idx_i];

        T3 = ri[(rs[1])];
        T5 = ii[(rs[1])];
        T2 = W[0];
        T4 = W[1];
        T6 = (((T2) * (T3)) + (T4 * T5));
        Te = ((T2 * T5) - ((T4) * (T3)));

        T8 = ri[(rs[2])];
        Ta = ii[(rs[2])];
        T7 = W[2];
        T9 = W[3];
        Tb = (((T7) * (T8)) + (T9 * Ta));
        Tf = ((T7 * Ta) - ((T9) * (T8)));

        Tc = T6 + Tb;
        Th = Te + Tf;

        ri[idx_r] = Tr + Tc;
        ii[idx_i] = Th + Ti_temp;

        Td = ((Tr) - ((KP500000000) * (Tc)));
        Tg = KP866025403 * (Te - Tf);
        Tj = KP866025403 * (Tb - T6);
        Tk = ((Ti_temp) - ((KP500000000) * (Th)));

        if (unroll_factor == 1) {
            ri[(rs[2])] = Td - Tg;
            ri[(rs[1])] = Td + Tg;
            ii[(rs[1])] = Tj + Tk;
            ii[(rs[2])] = Tk - Tj;
        }
    }
}
}
