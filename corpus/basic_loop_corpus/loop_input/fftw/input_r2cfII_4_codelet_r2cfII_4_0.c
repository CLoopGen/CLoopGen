#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *R0;
R *R1;
R *Cr;
R *Ci;
stride rs;
stride csr;
stride csi;
INT v;
INT ivs;
INT ovs;
E KP707106781;
INT i;

void init_vars() {
    const size_t data_size = 1 << 20; // ~8MB of total data (adjustable)
    const INT vector_length = 100000; // Adjust to target ~0.01 sec runtime

    R0 = (R*)aligned_alloc(32, data_size * sizeof(R));
    R1 = (R*)aligned_alloc(32, data_size * sizeof(R));
    Cr = (R*)aligned_alloc(32, data_size * sizeof(R));
    Ci = (R*)aligned_alloc(32, data_size * sizeof(R));

    rs = (stride)aligned_alloc(32, 2 * sizeof(INT));
    csr = (stride)aligned_alloc(32, 2 * sizeof(INT));
    csi = (stride)aligned_alloc(32, 2 * sizeof(INT));

    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = (R)(rand()) / RAND_MAX;
        R1[idx] = (R)(rand()) / RAND_MAX;
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    rs[0] = 0;
    rs[1] = 1;
    csr[0] = 0;
    csr[1] = 1;
    csi[0] = 0;
    csi[1] = 1;

    v = vector_length;
    ivs = 1;
    ovs = 1;
    KP707106781 = 0.707106781; // Approximation of 1/sqrt(2)

    // Ensure memory accesses in loop stay within bounds:
    // Max index used: R0[rs[1]] -> R0[1], Cr[csr[1]] -> Cr[1], etc.
    // So arrays need at least 2 elements of valid space per access
    // Our allocation satisfies this with large padding
}