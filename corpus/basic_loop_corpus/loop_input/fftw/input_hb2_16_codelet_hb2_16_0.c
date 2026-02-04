#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
E KP382683432 = 0.382683432;
E KP923879532 = 0.923879532;
E KP707106781 = 0.707106781;
INT m;

void init_vars() {
    const size_t N = 1 << 20; // ~8MB per array, total ~24MB
    cr = (R*)aligned_alloc(64, N * sizeof(R));
    ci = (R*)aligned_alloc(64, N * sizeof(R));
    W = (R*)aligned_alloc(64, (N + 8) * sizeof(R));

    rs = (stride)malloc(16 * sizeof(INT));
    
    // Initialize stride values to valid offsets
    for (int i = 0; i < 16; i++) {
        rs[i] = i * 1LL; // Ensure non-zero strides but within bounds
    }

    // Initialize data arrays with random-like values
    srand((unsigned int)time(NULL));
    for (size_t i = 0; i < N; i++) {
        cr[i] = (R)(rand() % 1000) / 100.0;
        ci[i] = (R)(rand() % 1000) / 100.0;
    }
    for (size_t i = 0; i < N + 8; i++) {
        W[i] = (R)(rand() % 1000) / 100.0;
    }

    // Set loop bounds so that all memory accesses stay within [0, N)
    // Largest index used: rs[15] -> offset up to 15*stride_value
    // We require: base_index + max_offset < N
    // Also ensure m goes from mb to me-1 safely

    mb = 1;
    me = N / 16 - 1; // Conservative bound to prevent out-of-bounds via rs indexing
    ms = 1;

    // Ensure that during loop:
    //   cr + ms*(m-mb) and ci - ms*(m-mb) stay in bounds
    // With m starting at mb=1 and ending at me-1, and me ~ N/16,
    // the pointer arithmetic won't exceed bounds given initial N allocation.
}