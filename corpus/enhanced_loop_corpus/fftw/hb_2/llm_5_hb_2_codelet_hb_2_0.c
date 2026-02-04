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
    // Reorder independent loads to change data dependency ordering (eliminate some RAW by preloading)
    T5 = W[0];
    T7 = W[1];
    T1 = cr[0];
    T2 = ci[0];
    T3 = ci[(rs[1])];
    T4 = cr[(rs[1])];
    // Break original WAW/RAW chain by computing all temps before any store
    T6 = T1 - T2;
    T8 = T3 + T4;
    // Remove potential WAR hazard by delaying stores until all reads are done
    E result_cr0 = T1 + T2;
    E result_ci0 = T3 - T4;
    E result_cr1 = (T5 * T6) - (T7 * T8);
    E result_ci1 = (T7 * T6) + (T5 * T8);
    // Perform all stores after all computations
    cr[0] = result_cr0;
    ci[0] = result_ci0;
    cr[(rs[1])] = result_cr1;
    ci[(rs[1])] = result_ci1;
}
}
