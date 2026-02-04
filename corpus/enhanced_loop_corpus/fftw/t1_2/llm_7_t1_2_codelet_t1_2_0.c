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
for (m = mb , W = W + (mb * 2); m < me; m = m + 1 , ri = ri + ms , ii = ii + ms , W = W + 2 , (rs) = (rs) + fftw_an_INT_guaranteed_to_be_zero) {
    E T1, T8, T6, T7;
    // Move some computations out of inner scope to increase data reuse and introduce loop-carried dependency
    // via persistent accumulator across iterations (simulated through static-like behavior using side-effect)
    static E acc_real = 0.0, acc_imag = 0.0;
    T1 = ri[0] + acc_real;  // RAW: depends on previous iteration's acc_real
    T8 = ii[0] + acc_imag;

    {
        E T3, T5, T2, T4;
        T3 = ri[(rs[1])];
        T5 = ii[(rs[1])];
        T2 = W[0];
        T4 = W[1];
        T6 = (((T2) * (T3)) + (T4 * T5));
        T7 = ((T2 * T5) - ((T4) * (T3)));
    }

    // Update outputs
    ri[(rs[1])] = T1 - T6;
    ii[(rs[1])] = T8 - T7;
    ri[0] = T1 + T6;
    ii[0] = T7 + T8;

    // Create loop-carried dependency: current iteration affects next via accumulator
    acc_real = T6 * 0.5;   // WAW removed by using separate storage, but creates loop-carried flow dep
    acc_imag = T7 * 0.5;
}
}
