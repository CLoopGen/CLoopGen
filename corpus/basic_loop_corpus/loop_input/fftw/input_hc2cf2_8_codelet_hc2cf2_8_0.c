#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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
E KP707106781;
INT m;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS (DATA_SIZE_MB * (1 << 20) / sizeof(R))

static void init_arrays(size_t n) {
    Rp = (R*)aligned_alloc(64, n * sizeof(R));
    Ip = (R*)aligned_alloc(64, n * sizeof(R));
    Rm = (R*)aligned_alloc(64, n * sizeof(R));
    Im = (R*)aligned_alloc(64, n * sizeof(R));
    W = (R*)aligned_alloc(64, (me - mb + 1) * 6 * sizeof(R));

    for (size_t i = 0; i < n; i++) {
        Rp[i] = sin(i * 0.01);
        Ip[i] = cos(i * 0.01);
        Rm[i] = sin(i * 0.02);
        Im[i] = cos(i * 0.02);
    }

    size_t w_size = (me - mb + 1) * 6;
    for (size_t i = 0; i < w_size; i++) {
        W[i] = sin(i * 0.1) * 0.5 + 0.5;
    }
}

void init_vars() {
    KP707106781 = 0.707106781; 

    ms = 1;
    mb = 1;
    me = (INT)(TOTAL_ELEMENTS / 8); 
    if (me < 1000) me = 1000;
    if (me > 1000000) me = 1000000;

    rs = (stride)aligned_alloc(64, 4 * sizeof(INT));
    rs[0] = 0;
    rs[1] = 1 * ms;
    rs[2] = 2 * ms;
    rs[3] = 3 * ms;

    size_t required_elements = (me - mb) * ms * 4 + 4 * ms;
    if ((size_t)required_elements > TOTAL_ELEMENTS / 2) {
        required_elements = TOTAL_ELEMENTS / 2;
        me = mb + (INT)(required_elements / (4 * ms));
    }

    init_arrays(required_elements);
}