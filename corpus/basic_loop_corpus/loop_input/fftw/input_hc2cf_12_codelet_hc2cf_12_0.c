#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

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
E KP500000000 = 0.5;
E KP866025403 = 0.8660254037844386; // Approximation of sqrt(3)/2

INT m;

void init_vars() {
    const INT N = 1 << 18; // ~262k elements, large enough for measurable runtime (~0.01 sec)
    const INT stride_count = 6; // Maximum rs[i] used: rs[5]

    // Allocate arrays with padding to prevent out-of-bounds access
    Rp = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Ip = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Rm = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Im = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), (N + 22) * sizeof(R)); // W accessed up to index 21 + offset

    // Allocate and initialize stride array
    rs = (stride)malloc(sizeof(INT) * stride_count);
    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;
    rs[4] = 4;
    rs[5] = 5;

    // Set loop parameters
    ms = 1; // typical stride step
    mb = 1;
    me = (N / 6) - 1; // ensure rs[5] indexing stays within bounds: m*ms + rs[5] < N

    // Initialize data arrays with non-zero values to simulate real computation
    for (INT i = 0; i < N; ++i) {
        Rp[i] = sin(i * 0.01);
        Ip[i] = cos(i * 0.01);
        Rm[i] = sin(i * 0.02);
        Im[i] = cos(i * 0.02);
    }

    for (INT i = 0; i < (INT)(N + 22); ++i) {
        W[i] = sin(i * 0.1) * 0.5 + 0.5;
    }
}