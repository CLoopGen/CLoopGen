#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *rio;
extern R *iio;
extern  R *W;
extern stride rs;
extern stride vs;
extern INT mb;
extern INT me;
extern INT ms;
extern  E KP866025403;
extern  E KP500000000;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 4); m < me; m = m + 1 , rio = rio + ms , iio = iio + ms , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T4, T6, Tc, Td, Te, Tf, T9;
    E Ta, Tg, T5, Tb;
    T1 = rio[0];
    T4 = rio[(rs[1])] + rio[(rs[2])];
    T6 = T1 - KP500000000 * T4;
    Tc = KP866025403 * (rio[(rs[2])] - rio[(rs[1])]);
    Td = iio[0];
    Te = iio[(rs[1])] + iio[(rs[2])];
    Tf = Td - KP500000000 * Te;
    T9 = KP866025403 * (iio[(rs[1])] - iio[(rs[2])]);
    Ta = T6 + T9;
    Tg = Tc + Tf;
    T5 = W[0];
    Tb = W[1];
    rio[0] = T1 + T4;
    iio[0] = Td + Te;
    rio[(vs[1])] = T5 * Ta + Tb * Tg;
    iio[(vs[1])] = T5 * Tg - Tb * Ta;
}
}
