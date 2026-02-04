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
E KP293892626;
E KP475528258;
E KP125000000;
E KP500000000;
E KP279508497;
INT m;

#define DATA_SIZE (1 << 20)
#define ALIGNMENT 64

void init_vars() {
    mb = 1;
    me = DATA_SIZE + 1;
    ms = 1;
    
    KP293892626 = 0.293892626;
    KP475528258 = 0.475528258;
    KP125000000 = 0.125000000;
    KP500000000 = 0.500000000;
    KP279508497 = 0.279508497;

    size_t total_size = (size_t)(me - mb + 5) * abs(ms);
    size_t w_size = ((me - mb) * 18) + 18;

    Rp = aligned_alloc(ALIGNMENT, total_size * sizeof(R));
    Ip = aligned_alloc(ALIGNMENT, total_size * sizeof(R));
    Rm = aligned_alloc(ALIGNMENT, total_size * sizeof(R));
    Im = aligned_alloc(ALIGNMENT, total_size * sizeof(R));
    W = aligned_alloc(ALIGNMENT, w_size * sizeof(R));

    rs = malloc(sizeof(INT) * 5);
    for (int i = 0; i < 5; i++) {
        rs[i] = i * ms;
    }

    for (size_t i = 0; i < total_size; i++) {
        Rp[i] = sin(i * 0.01);
        Ip[i] = cos(i * 0.01);
        Rm[i] = sin(i * 0.02);
        Im[i] = cos(i * 0.02);
    }

    for (size_t i = 0; i < w_size; i++) {
        W[i] = sin(i * 0.1) * 0.9 + 0.1;
    }
}