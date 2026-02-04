#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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
E KP500000000;
INT m;

#define DATA_SIZE (1 << 20)
#define LOOP_COUNT 65536

void init_vars() {
    size_t i;

    Rp = (R*)aligned_alloc(32, sizeof(R) * DATA_SIZE);
    Ip = (R*)aligned_alloc(32, sizeof(R) * DATA_SIZE);
    Rm = (R*)aligned_alloc(32, sizeof(R) * DATA_SIZE);
    Im = (R*)aligned_alloc(32, sizeof(R) * DATA_SIZE);
    W = (R*)aligned_alloc(32, sizeof(R) * 6 * LOOP_COUNT);

    rs = (stride)aligned_alloc(32, sizeof(INT));
    *rs = 1;

    for (i = 0; i < DATA_SIZE; ++i) {
        Rp[i] = sin(i * 0.01);
        Ip[i] = cos(i * 0.01);
        Rm[i] = sin(i * 0.02);
        Im[i] = cos(i * 0.02);
    }

    for (i = 0; i < 6 * LOOP_COUNT; ++i) {
        W[i] = sin(i * 0.1) * 0.5;
    }

    mb = 1;
    me = LOOP_COUNT + 1;
    ms = 1;
    KP500000000 = 0.5;
}