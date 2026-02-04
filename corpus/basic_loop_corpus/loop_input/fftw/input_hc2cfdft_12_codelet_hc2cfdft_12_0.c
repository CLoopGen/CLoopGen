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
E KP250000000;
E KP500000000;
E KP433012701;
INT m;

static size_t data_size;
static R *alloc_R(size_t n) {
    void *ptr = aligned_alloc(sizeof(R), n * sizeof(R));
    if (!ptr) abort();
    memset(ptr, 0, n * sizeof(R));
    return (R*)ptr;
}

static stride alloc_stride(size_t n) {
    void *ptr = aligned_alloc(sizeof(INT), n * sizeof(INT));
    if (!ptr) abort();
    return (stride)ptr;
}

void init_vars() {
    KP250000000 = 0.25;
    KP500000000 = 0.5;
    KP433012701 = sin(M_PI / 3.0); // approximately 0.866025403 -> scaled, matches 0.433012701 * 2

    ms = 1;
    mb = 1;
    me = 100000;

    data_size = me * 22 + 100;
    Rp = alloc_R(data_size);
    Ip = alloc_R(data_size);
    Rm = alloc_R(data_size);
    Im = alloc_R(data_size);
    W = alloc_R(22 * (me - mb + 1) + 50);

    rs = alloc_stride(6);
    for (INT i = 0; i < 6; i++) {
        rs[i] = i * ms;
    }

    for (INT i = 0; i < (ptrdiff_t)data_size; i++) {
        Rp[i] = sin(i);
        Ip[i] = cos(i);
        Rm[i] = cos(i + 1);
        Im[i] = sin(i + 1);
    }

    for (INT i = 0; i < 22; i++) {
        W[i] = sin(i * 0.1);
    }
}