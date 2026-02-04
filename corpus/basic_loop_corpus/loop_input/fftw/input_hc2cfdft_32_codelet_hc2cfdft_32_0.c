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
E KP277785116;
E KP415734806;
E KP097545161;
E KP490392640;
E KP707106781;
E KP191341716;
E KP461939766;
E KP353553390;
E KP500000000;
INT m;

void init_vars() {
    const size_t N = 16;
    const size_t total_size = 1 << 20; // ~1MB of data per array
    const size_t count = total_size / (N * sizeof(R));
    
    mb = 1;
    me = count + 1;
    ms = 1;

    Rp = (R*)aligned_alloc(64, total_size);
    Ip = (R*)aligned_alloc(64, total_size);
    Rm = (R*)aligned_alloc(64, total_size);
    Im = (R*)aligned_alloc(64, total_size);
    W = (R*)aligned_alloc(64, count * 62 * sizeof(R));
    rs = (stride)malloc(sizeof(INT) * N);

    for (size_t i = 0; i < N; ++i) {
        rs[i] = i * (ptrdiff_t)count;
    }

    KP277785116 = 0.277785116;
    KP415734806 = 0.415734806;
    KP097545161 = 0.097545161;
    KP490392640 = 0.490392640;
    KP707106781 = 0.707106781;
    KP191341716 = 0.191341716;
    KP461939766 = 0.461939766;
    KP353553390 = 0.353553390;
    KP500000000 = 0.500000000;

    for (size_t i = 0; i < total_size / sizeof(R); ++i) {
        Rp[i] = (R)(rand() % 1000) / 100.0;
        Ip[i] = (R)(rand() % 1000) / 100.0;
        Rm[i] = (R)(rand() % 1000) / 100.0;
        Im[i] = (R)(rand() % 1000) / 100.0;
    }

    for (size_t i = 0; i < count * 62; ++i) {
        W[i] = (R)(rand() % 1000) / 100.0;
    }
}