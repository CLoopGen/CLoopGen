#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
INT m;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB for cr and ci (each double is 8 bytes)
    const INT max_stride_index = 3;
    
    cr = (R*)aligned_alloc(64, sizeof(R) * data_size);
    ci = (R*)aligned_alloc(64, sizeof(R) * data_size);
    W = (R*)aligned_alloc(64, sizeof(R) * 6 * (data_size / 4 + 1));

    rs = (INT*)aligned_alloc(64, sizeof(INT) * (max_stride_index + 1));
    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;

    ms = 1;
    mb = 1;
    me = (data_size / 4) - 1; 

    for (size_t i = 0; i < data_size; ++i) {
        cr[i] = (R)(i % 100) / 100.0;
        ci[i] = (R)((i + 10) % 100) / 100.0;
    }

    for (size_t i = 0; i < (size_t)(me - mb + 2); ++i) {
        size_t w_idx = i * 6;
        W[w_idx + 0] = 1.0;
        W[w_idx + 1] = 0.0;
        W[w_idx + 2] = 0.707;
        W[w_idx + 3] = 0.707;
        W[w_idx + 4] = -0.707;
        W[w_idx + 5] = 0.707;
    }
}