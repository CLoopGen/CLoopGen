#include <stdio.h>
#include <inttypes.h>
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
INT m;

static const size_t DATA_SIZE = 1 << 20; // ~8MB per array (double)
static const INT LOOP_COUNT = 100000;

void init_vars() {
    mb = 1;
    me = LOOP_COUNT;
    ms = 2;
    
    rs = (stride)aligned_alloc(64, sizeof(INT));
    *rs = 1;

    size_t total_size = DATA_SIZE + (me - mb) * 4 + 100;
    
    Rp = (R*)aligned_alloc(64, total_size * sizeof(R));
    Ip = (R*)aligned_alloc(64, total_size * sizeof(R));
    Rm = (R*)aligned_alloc(64, total_size * sizeof(R));
    Im = (R*)aligned_alloc(64, total_size * sizeof(R));
    W = (R*)aligned_alloc(64, (LOOP_COUNT * 4 + 10) * sizeof(R));

    for (size_t i = 0; i < total_size; i++) {
        Rp[i] = (R)(i & 255) / 255.0;
        Ip[i] = (R)((i + 1) & 255) / 255.0;
        Rm[i] = (R)((i + 2) & 255) / 255.0;
        Im[i] = (R)((i + 3) & 255) / 255.0;
    }

    for (INT i = 0; i < LOOP_COUNT * 4 + 10; i++) {
        W[i] = (R)((i + 4) & 255) / 127.0;
    }
}