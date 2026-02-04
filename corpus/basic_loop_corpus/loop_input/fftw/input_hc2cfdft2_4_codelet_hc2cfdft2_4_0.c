#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP500000000;
INT m;

void init_vars() {
    // Set data size to get around 0.01 seconds runtime
    // Based on typical performance, use ~32M elements to target this range
    const INT N = 1 << 24;  // ~16M complex pairs, about 128MB total data

    // Allocate aligned memory for better performance and FFT-like access patterns
    Rp = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Ip = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Rm = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Im = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), (N * 4) * sizeof(R)); // W uses 4-element strides
    rs = (INT*)aligned_alloc(sizeof(INT), N * sizeof(INT));

    // Initialize scalar values
    ms = 1;  // typical stride step
    mb = 1;  // loop starts at mb
    me = N - 1;  // ensure we don't go out of bounds
    KP500000000 = 0.5;  // common scaling factor in FFTs

    // Initialize rs array: set all stride values to 1 for regular access
    for (INT i = 0; i < N; ++i) {
        rs[i] = 1;
    }

    // Initialize data arrays with non-zero values to allow meaningful computation
    for (INT i = 0; i < N; ++i) {
        Rp[i] = (R)(i & 1 ? 1.0 : -1.0);
        Ip[i] = (R)((i + 1) % 3 == 0 ? 0.5 : 0.0);
        Rm[i] = (R)(i % 5 ? 0.25 : -0.25);
        Im[i] = (R)((i + 2) % 7 == 0 ? 0.75 : 0.0);
    }

    // Initialize W array: simulate twiddle factors (cos/sin pairs)
    for (INT i = 0; i < N * 4; ++i) {
        W[i] = (R)(i % 4 == 0 || i % 4 == 2 ? 1.0 : 0.5);
    }
}