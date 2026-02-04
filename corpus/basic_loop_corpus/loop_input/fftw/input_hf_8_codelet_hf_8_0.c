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
R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP707106781;
INT m;

#define DATA_SIZE (1 << 20)
#define ALIGNMENT 64

void init_vars() {
    const size_t alignment = ALIGNMENT;
    const INT n = 8;
    const INT stride_size = n;
    const INT w_size = 14 * n;
    const INT total_data_size = DATA_SIZE / sizeof(R);
    
    KP707106781 = 0.707106781;

    posix_memalign((void**)&cr, alignment, total_data_size * sizeof(R));
    posix_memalign((void**)&ci, alignment, total_data_size * sizeof(R));
    posix_memalign((void**)&W, alignment, w_size * sizeof(R));
    posix_memalign((void**)&rs, alignment, stride_size * sizeof(INT));

    for (size_t i = 0; i < total_data_size; ++i) {
        cr[i] = (R)(rand() % 1000) / 100.0;
        ci[i] = (R)(rand() % 1000) / 100.0;
    }

    for (INT i = 0; i < w_size; ++i) {
        W[i] = (R)(rand() % 1000) / 1000.0;
    }

    for (INT i = 0; i < stride_size; ++i) {
        rs[i] = (i + 1) * 8; 
    }

    ms = 1;
    mb = 1;
    me = n - 1;

    if (me > total_data_size / (n * 2)) {
        me = total_data_size / (n * 2);
    }
}