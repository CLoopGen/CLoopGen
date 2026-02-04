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
for (m = mb , W = W + ((mb - 1) * 4); m < me && m < mb + 1; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T7, T9, T8, Ta, Tb, Td;
    T7 = W[0];
    T9 = W[1];
    T8 = W[2];
    Ta = W[3];
    Tb = T7 * T8 + T9 * Ta;
    Td = T7 * Ta - T9 * T8;

    E T3, Tl, T6, To, Tg, Tp, Tj, Tm, Tc, Tk;

    T3 = cr[0] + ci[(rs[1])];
    Tl = cr[0] - ci[(rs[1])];
    T6 = cr[(rs[1])] + ci[0];
    To = cr[(rs[1])] - ci[0];

    Tg = ci[(rs[3])] - cr[(rs[2])];
    Tp = ci[(rs[3])] + cr[(rs[2])];
    Tj = ci[(rs[2])] - cr[(rs[3])];
    Tm = ci[(rs[2])] + cr[(rs[3])];

    cr[0] = T3 + T6;
    ci[0] = Tg + Tj;
    Tc = T3 - T6;
    Tk = Tg - Tj;
    cr[(rs[2])] = Tb * Tc - Td * Tk;
    ci[(rs[2])] = Td * Tc + Tb * Tk;

    E Tn = Tl - Tm;
    E Tq = To + Tp;
    cr[(rs[1])] = T7 * Tn - T9 * Tq;
    ci[(rs[1])] = T7 * Tq + T9 * Tn;

    E Tr = Tl + Tm;
    E Ts = Tp - To;
    cr[(rs[3])] = T8 * Tr - Ta * Ts;
    ci[(rs[3])] = T8 * Ts + Ta * Tr;
}
}
