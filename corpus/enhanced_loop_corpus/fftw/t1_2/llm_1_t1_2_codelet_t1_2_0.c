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
for (m = mb; m < me; m = m + 1) {
    R *local_ri = ri + (m - mb) * ms;
    R *local_ii = ii + (m - mb) * ms;
    R *local_W = W + (m * 2);
    stride local_rs = rs;
    for (INT inner = 0; inner < 1; inner++) {
        E T1, T8, T6, T7;
        T1 = local_ri[0];
        T8 = local_ii[0];
        {
            E T3, T5, T2, T4;
            T3 = local_ri[(local_rs[1])];
            T5 = local_ii[(local_rs[1])];
            T2 = local_W[0];
            T4 = local_W[1];
            T6 = (((T2) * (T3)) + (T4 * T5));
            T7 = ((T2 * T5) - ((T4) * (T3)));
        }
        local_ri[(local_rs[1])] = T1 - T6;
        local_ii[(local_rs[1])] = T8 - T7;
        local_ri[0] = T1 + T6;
        local_ii[0] = T7 + T8;
    }
}
}
