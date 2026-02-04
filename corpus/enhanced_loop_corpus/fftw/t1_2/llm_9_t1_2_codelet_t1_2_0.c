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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 4); m < me; m = m + 2 , ri = ri + (ms * 2) , ii = ii + (ms * 2) , W = W + 4 , (rs) = (rs) + (2 * fftw_an_INT_guaranteed_to_be_zero)) {
    if (m + 1 >= me) break;
    E T1, T8, T6, T7;
    E T9, Ta, Tb, Tc;
    T1 = ri[0];
    T8 = ii[0];
    T9 = ri[(rs[1])];
    Ta = ii[(rs[1])];
    {
        E T3, T5, T2, T4;
        T3 = ri[(rs[2])];
        T5 = ii[(rs[2])];
        T2 = W[0];
        T4 = W[1];
        T6 = T2 * T3 - T4 * T5;
        T7 = T2 * T5 + T4 * T3;
    }
    {
        E Td, Tf, Te, Tg;
        Td = ri[(rs[3])];
        Tf = ii[(rs[3])];
        Te = W[2];
        Tg = W[3];
        Tb = Te * Td - Tg * Tf;
        Tc = Te * Tf + Tg * Td;
    }
    ri[(rs[1])] = T1 - T6;
    ii[(rs[1])] = T8 - T7;
    ri[0] = T1 + T6;
    ii[0] = T8 + T7;
    ri[(rs[3])] = T9 - Tb;
    ii[(rs[3])] = Ta - Tc;
    ri[(rs[2])] = T9 + Tb;
    ii[(rs[2])] = Ta + Tc;
}
}
