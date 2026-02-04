#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *ri;
R *ii;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP222520933;
E KP900968867;
E KP623489801;
E KP433883739;
E KP781831482;
E KP974927912;
INT m;

void init_vars() {
    const size_t N = (1 << 20) * 32; // ~256MB of data (each double is 8 bytes)
    ri = (R*)aligned_alloc(64, sizeof(R) * N);
    ii = (R*)aligned_alloc(64, sizeof(R) * N);
    W = (R*)aligned_alloc(64, sizeof(R) * 12 * (N / 6)); 

    rs = (INT*)aligned_alloc(64, sizeof(INT) * 8);
    for (int i = 0; i < 8; i++) {
        rs[i] = i * 2;
    }

    mb = 0;
    ms = 1;
    me = N / 6;

    KP222520933 = 0.222520933;
    KP900968867 = 0.900968867;
    KP623489801 = 0.623489801;
    KP433883739 = 0.433883739;
    KP781831482 = 0.781831482;
    KP974927912 = 0.974927912;

    for (size_t i = 0; i < N; i++) {
        ri[i] = (R)(i % 100) / 100.0;
        ii[i] = (R)((i + 10) % 100) / 100.0;
    }

    for (size_t i = 0; i < 12 * (me - mb); i++) {
        W[i] = (R)(i % 50) / 50.0;
    }
}