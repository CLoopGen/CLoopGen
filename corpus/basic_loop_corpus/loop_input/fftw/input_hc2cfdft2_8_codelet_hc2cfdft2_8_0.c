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
E KP353553390;
E KP500000000;
INT m;

#define DATA_SIZE_MB 64
#define TOTAL_ELEMENTS ((DATA_SIZE_MB * 1024 * 1024) / sizeof(R))

static R *alloc_aligned(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(R)) != 0) {
        exit(1);
    }
    return (R*)ptr;
}

void init_vars() {
    KP353553390 = 0.353553390;
    KP500000000 = 0.500000000;

    ms = 1;
    mb = 1;
    me = (TOTAL_ELEMENTS / 8) - 1;

    Rp = alloc_aligned(TOTAL_ELEMENTS);
    Ip = alloc_aligned(TOTAL_ELEMENTS);
    Rm = alloc_aligned(TOTAL_ELEMENTS);
    Im = alloc_aligned(TOTAL_ELEMENTS);
    W = alloc_aligned(me * 6 + 10);

    rs = (stride)malloc(sizeof(INT) * 4);
    rs[0] = 0;
    rs[1] = 1 * ms;
    rs[2] = 2 * ms;
    rs[3] = 3 * ms;

    for (INT i = 0; i < TOTAL_ELEMENTS; i++) {
        Rp[i] = sin(i * 0.01);
        Ip[i] = cos(i * 0.01);
        Rm[i] = sin(i * 0.02);
        Im[i] = cos(i * 0.02);
    }

    for (INT i = 0; i < me * 6 + 10; i++) {
        W[i] = sin(i * 0.1) * 0.5 + 1.0;
    }
}