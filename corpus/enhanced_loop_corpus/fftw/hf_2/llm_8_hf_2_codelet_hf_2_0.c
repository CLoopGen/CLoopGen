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
for (m = mb , W = W + ((mb - 1) * 2); m < me; m = m + 2 , cr = cr + ms * 2 , ci = ci - ms * 2 , W = W + 4 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    if (m + 1 >= me) break;
    E T1, T8, T6, T7;
    E T9, T16, T14, T15;

    T1 = cr[0];
    T8 = ci[0];
    T9 = cr[ms];
    T16 = ci[ms];

    {
        E T3, T5, T2, T4;
        T3 = cr[(rs[1])];
        T5 = ci[(rs[1])];
        T2 = W[0];
        T4 = W[1];
        T6 = ((T2) * (T3)) + (T4 * T5);
        T7 = (T2 * T5) - ((T4) * (T3));
    }
    {
        E T11, T13, T10, T12;
        T11 = cr[ms + (rs[1])];
        T13 = ci[ms + (rs[1])];
        T10 = W[2];
        T12 = W[3];
        T14 = (T10 * T11) + (T12 * T13);
        T15 = (T10 * T13) - (T12 * T11);
    }

    ci[0] = T1 - T6;
    cr[0] = T1 + T6;
    cr[(rs[1])] = T7 - T8;
    ci[(rs[1])] = T7 + T8;

    ci[ms] = T9 - T14;
    cr[ms] = T9 + T14;
    cr[ms + (rs[1])] = T15 - T16;
    ci[ms + (rs[1])] = T15 + T16;
}
}
