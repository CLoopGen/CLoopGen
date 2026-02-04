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
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (m = mb , W = W + (mb * 2); m < me; m = m + 1 , rio = rio + ms , iio = iio + ms , W = W + 2 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero , (vs) = (vs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T4, T6, T7, T8, T9, Ta, Tc, Te, Tf, Tg;
    INT rsi1 = rs[1];
    INT vsi1 = vs[1];
    INT idx0 = 0;
    INT idx1 = rsi1;
    INT idx2 = vsi1;
    INT idx3 = vsi1 + rsi1;

    T1 = rio[idx0];
    T2 = rio[idx1];
    T4 = T1 - T2;
    T6 = iio[idx0];
    T7 = iio[idx1];
    T8 = T6 - T7;
    T9 = rio[idx2];
    Ta = rio[idx3];
    Tc = T9 - Ta;
    Te = iio[idx2];
    Tf = iio[idx3];
    Tg = Te - Tf;

    rio[idx0] = T1 + T2;
    iio[idx0] = T6 + T7;
    rio[idx1] = T9 + Ta;
    iio[idx1] = Te + Tf;

    {
        E Tb = W[0];
        E Td = W[1];
        rio[idx3] = (Tb * Tc) + (Td * Tg);
        iio[idx3] = (Tb * Tg) - (Td * Tc);

        rio[idx2] = (Tb * T4) + (Td * T8);
        iio[idx2] = (Tb * T8) - (Td * T4);
    }
}
}
