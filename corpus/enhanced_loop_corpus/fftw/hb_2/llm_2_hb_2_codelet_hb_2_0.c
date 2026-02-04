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
for (m = mb , W = W + ((mb - 1) * 2); m < me; m = m + 1 , cr = cr + ms , ci = ci - ms , W = W + 2 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T2, T6, T3, T4, T8, T5, T7;
    INT idx1 = 0;
    INT idx2 = rs[1];
    T1 = cr[idx1];
    T2 = ci[idx1];
    T6 = T1 - T2;
    T3 = ci[idx2];
    T4 = cr[idx2];
    T8 = T3 + T4;
    cr[idx1] = T1 + T2;
    ci[idx1] = T3 - T4;
    T5 = W[0];
    T7 = W[1];
    cr[idx2] = (T5 * T6) - (T7 * T8);
    ci[idx2] = (T7 * T6) + (T5 * T8);
}
}
