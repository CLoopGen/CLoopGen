#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef ptrdiff_t INT;

typedef double R;

typedef INT *stride;

typedef R E;

extern const INT fftw_an_INT_guaranteed_to_be_zero;
extern R *ri;
extern R *ii;
extern  R *W;
extern stride rs;
extern INT mb;
extern INT me;
extern INT ms;
extern INT m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Change memory access pattern: unroll by 2 with consecutive access where possible
// Assumes mb is even and me = mb + 2*k for some k; handles two iterations per loop
for (m = mb , W = W + (mb * 2); m < me; m = m + 2 , ri = ri + 2*ms , ii = ii + 2*ms , W = W + 4 , (rs) = (rs) + 2*fftw_an_INT_guaranteed_to_be_zero) {
    E T1a, T8a, T6a, T7a;
    E T1b, T8b, T6b, T7b;
    INT idx1a = rs[1];
    INT idx1b = rs[2]; // Assume stride array has enough elements

    // First iteration (current m)
    T1a = ri[0];
    T8a = ii[0];
    {
        E T3 = ri[idx1a], T5 = ii[idx1a], T2 = W[0], T4 = W[1];
        T6a = T2 * T3 + T4 * T5;
        T7a = T2 * T5 - T4 * T3;
    }
    ri[idx1a] = T1a - T6a;
    ii[idx1a] = T8a - T7a;
    ri[0] = T1a + T6a;
    ii[0] = T8a + T7a;

    // Second iteration (m+1), offset by ms in ri/ii, 2 in W
    T1b = ri[ms];
    T8b = ii[ms];
    {
        E T3 = ri[ms + idx1b], T5 = ii[ms + idx1b], T2 = W[2], T4 = W[3];
        T6b = T2 * T3 + T4 * T5;
        T7b = T2 * T5 - T4 * T3;
    }
    ri[ms + idx1b] = T1b - T6b;
    ii[ms + idx1b] = T8b - T7b;
    ri[ms] = T1b + T6b;
    ii[ms] = T8b + T7b;
}
}
