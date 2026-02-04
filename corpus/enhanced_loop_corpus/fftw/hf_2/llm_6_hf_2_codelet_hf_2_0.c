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
    E T1, T8, T6, T7;
    T1 = cr[0];
    T8 = ci[0];
    {
        E T3, T5, T2, T4;
        T2 = W[0];
        T4 = W[1];
        T3 = cr[(rs[1])];
        T5 = ci[(rs[1])];
        T6 = T2 * T3 + T4 * T5;
        T7 = T2 * T5 - T4 * T3;
    }
    // Introduce temporary variables to break direct write-after-write (WAW) and write-after-read (WAR)
    // by delaying updates until all reads are complete. This preserves semantics but changes data dependency order.
    E new_ci0 = T1 - T6;
    E new_cr0 = T1 + T6;
    E new_cr1 = T7 - T8;
    E new_ci1 = T7 + T8;

    ci[0] = new_ci0;
    cr[0] = new_cr0;
    cr[(rs[1])] = new_cr1;
    ci[(rs[1])] = new_ci1;
}
}
