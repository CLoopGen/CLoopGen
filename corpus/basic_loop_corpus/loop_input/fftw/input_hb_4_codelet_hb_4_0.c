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

static void *alloc_aligned(size_t alignment, size_t size) {
    void *ptr;
    if (posix_memalign(&ptr, alignment, size) != 0) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    return ptr;
}

void init_vars() {
    const INT vector_width = 4;
    const INT data_size_mb = 64;
    const INT total_elements = (data_size_mb * (1 << 20)) / sizeof(R);
    
    cr = (R*)alloc_aligned(32, total_elements * sizeof(R));
    ci = (R*)alloc_aligned(32, total_elements * sizeof(R));
    W = (R*)alloc_aligned(32, (total_elements / vector_width) * 6 * sizeof(R));

    rs = (stride)alloc_aligned(32, 4 * sizeof(INT));
    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;

    for (INT i = 0; i < total_elements; ++i) {
        cr[i] = (R)(i % 128) / 64.0 - 1.0;
        ci[i] = (R)((i + 17) % 128) / 64.0 - 1.0;
    }

    for (INT i = 0; i < (total_elements / vector_width) * 6; ++i) {
        W[i] = (R)(i % 100) / 50.0 - 1.0;
    }

    mb = 1;
    me = total_elements / vector_width;
    ms = 1;
    m = mb;
}