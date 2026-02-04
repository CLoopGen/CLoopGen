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
E KP707106781;
INT m;

static size_t data_size;
static void init_arrays() {
    data_size = (1 << 23) / sizeof(R); // ~8MB of data per array, adjust as needed for timing
    Rp = (R*)aligned_alloc(64, data_size * sizeof(R));
    Ip = (R*)aligned_alloc(64, data_size * sizeof(R));
    Rm = (R*)aligned_alloc(64, data_size * sizeof(R));
    Im = (R*)aligned_alloc(64, data_size * sizeof(R));
    W = (R*)aligned_alloc(64, 14 * sizeof(R));
    rs = (INT*)aligned_alloc(64, 4 * sizeof(INT));

    for (size_t i = 0; i < data_size; ++i) {
        Rp[i] = (R)(rand() % 100) / 100.0;
        Ip[i] = (R)(rand() % 100) / 100.0;
        Rm[i] = (R)(rand() % 100) / 100.0;
        Im[i] = (R)(rand() % 100) / 100.0;
    }
    for (int i = 0; i < 14; ++i) {
        W[i] = (R)(rand() % 100) / 100.0;
    }
    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;

    KP707106781 = 0.707106781;
    mb = 1;
    me = (data_size > 4 ? 4 : data_size);
    ms = 1;
}

void init_vars() {
    init_arrays();
}