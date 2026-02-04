#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *ri;
R *ii;
R *ro;
R *io;
stride is;
stride os;
INT v;
INT ivs;
INT ovs;
INT i;

void init_vars() {
    const size_t N = 1 << 20; // ~8MB per array (double), total ~32MB for data arrays

    ri = (R*)aligned_alloc(32, N * sizeof(R));
    ii = (R*)aligned_alloc(32, N * sizeof(R));
    ro = (R*)aligned_alloc(32, N * sizeof(R));
    io = (R*)aligned_alloc(32, N * sizeof(R));

    is = (INT*)aligned_alloc(32, 4 * sizeof(INT));
    os = (INT*)aligned_alloc(32, 4 * sizeof(INT));

    // Set stride values to valid indices within bounds
    is[0] = 0;
    is[1] = 1;
    is[2] = 2;
    is[3] = 3;

    os[0] = 0;
    os[1] = 1;
    os[2] = 2;
    os[3] = 3;

    // Initialize data arrays
    for (size_t j = 0; j < N; j++) {
        ri[j] = (R)(j + 1);
        ii[j] = (R)(-(ptrdiff_t)j);
        ro[j] = 0.0;
        io[j] = 0.0;
    }

    // Configure loop parameters
    v = N / 4;          // Each iteration advances by 4 elements implicitly via strides
    ivs = 4;            // Input vector stride increment
    ovs = 4;            // Output vector stride increment
}