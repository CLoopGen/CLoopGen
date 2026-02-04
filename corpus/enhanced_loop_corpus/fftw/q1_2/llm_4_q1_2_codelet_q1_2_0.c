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
    T1 = rio[0];
    T2 = rio[(rs[1])];
    T4 = T1 - T2;
    T6 = iio[0];
    T7 = iio[(rs[1])];
    T8 = T6 - T7;
    T9 = rio[(vs[1])];
    Ta = rio[(vs[1]) + (rs[1])];
    Tc = T9 - Ta;
    Te = iio[(vs[1])];
    Tf = iio[(vs[1]) + (rs[1])];
    Tg = Te - Tf;
    // Introduce WAW dependency: reorder updates to rio[0] and use intermediate variables
    E temp_rio0 = T1 + T2;
    E temp_iio0 = T6 + T7;
    rio[(vs[1]) + (rs[1])] = ((W[0]) * (Tc)) + (W[1] * Tg);
    iio[(vs[1]) + (rs[1])] = (W[0] * Tg) - ((W[1]) * (Tc));
    rio[(vs[1])] = ((W[0]) * (T4)) + (W[1] * T8);
    iio[(vs[1])] = (W[0] * T8) - ((W[1]) * (T4));
    rio[0] = temp_rio0;
    iio[0] = temp_iio0;
    rio[(rs[1])] = T9 + Ta;
    iio[(rs[1])] = Te + Tf;
}
}
