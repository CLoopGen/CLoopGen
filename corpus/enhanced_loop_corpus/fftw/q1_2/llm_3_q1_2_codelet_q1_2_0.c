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
for (m = mb , W = W + (mb * 2); m < me; m = m + 1 , rio += ms , iio += ms , W += 2) {
    E T1, T2, T4, T6, T7, T8, T9, Ta, Tc, Te, Tf, Tg;
    INT rstride = rs[1];
    INT vstride = vs[1];

    T1 = *(rio + 0);
    T2 = *(rio + rstride);
    T4 = T1 - T2;
    T6 = *(iio + 0);
    T7 = *(iio + rstride);
    T8 = T6 - T7;
    T9 = *(rio + vstride);
    Ta = *(rio + vstride + rstride);
    Tc = T9 - Ta;
    Te = *(iio + vstride);
    Tf = *(iio + vstride + rstride);
    Tg = Te - Tf;

    *(rio + 0) = T1 + T2;
    *(iio + 0) = T6 + T7;
    *(rio + rstride) = T9 + Ta;
    *(iio + rstride) = Te + Tf;

    {
        E Tb = W[0];
        E Td = W[1];
        *(rio + vstride + rstride) = Tb * Tc + Td * Tg;
        *(iio + vstride + rstride) = Tb * Tg - Td * Tc;
        *(rio + vstride) = Tb * T4 + Td * T8;
        *(iio + vstride) = Tb * T8 - Td * T4;
    }
}
}
