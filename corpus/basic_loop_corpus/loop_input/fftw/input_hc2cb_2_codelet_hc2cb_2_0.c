#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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

void init_vars() {
    const size_t data_size = 1 << 23; // ~16 million elements, roughly 128MB for doubles
    Rp = (R*)aligned_alloc(32, data_size * sizeof(R));
    Ip = (R*)aligned_alloc(32, data_size * sizeof(R));
    Rm = (R*)aligned_alloc(32, data_size * sizeof(R));
    Im = (R*)aligned_alloc(32, data_size * sizeof(R));
    W = (R*)aligned_alloc(32, (data_size * 2) * sizeof(R));

    rs = (stride)malloc(sizeof(INT));
    *rs = 1;

    for (size_t i = 0; i < data_size; ++i) {
        Rp[i] = (R)(rand()) / RAND_MAX;
        Ip[i] = (R)(rand()) / RAND_MAX;
        Rm[i] = (R)(rand()) / RAND_MAX;
        Im[i] = (R)(rand()) / RAND_MAX;
    }

    for (size_t i = 0; i < data_size * 2; ++i) {
        W[i] = (R)(rand()) / RAND_MAX;
    }

    mb = 1;
    me = data_size - 1;
    ms = 1;

    if (me - mb > data_size / 2) {
        me = mb + (data_size / 2);
    }
}