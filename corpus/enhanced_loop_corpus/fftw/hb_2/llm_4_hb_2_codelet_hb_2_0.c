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
    T1 = cr[0];
    T2 = ci[0];
    T6 = T1 - T2;
    T3 = ci[(rs[1])];
    T4 = cr[(rs[1])];
    T8 = T3 + T4;
    // Introduce artificial dependency: make T5 and T7 depend on previous iteration values via accumulation
    static R prev_T6 = 0.0, prev_T8 = 0.0;
    T5 = W[0] + prev_T6 * 0.001;  // Slight modification using prior result (introduces loop-carried dependency)
    T7 = W[1] + prev_T8 * 0.001;
    cr[0] = T1 + T2;
    ci[0] = T3 - T4;
    cr[(rs[1])] = ((T5 * T6) - (T7 * T8));
    ci[(rs[1])] = ((T7 * T6) + (T5 * T8));
    // Update history at end of iteration
    prev_T6 = T6;
    prev_T8 = T8;
}
}
