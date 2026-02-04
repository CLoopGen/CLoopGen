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
E KP2_000000000;
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of data to target ~0.01s runtime
    const size_t count = data_size / (sizeof(R) * 4); // Four arrays: R0, R1, Cr, Ci

    R0 = (R*)aligned_alloc(32, count * sizeof(R));
    R1 = (R*)aligned_alloc(32, count * sizeof(R));
    Cr = (R*)aligned_alloc(32, count * sizeof(R));
    Ci = (R*)aligned_alloc(32, count * sizeof(R));

    rs = (stride)malloc(sizeof(INT));
    csr = (stride)malloc(sizeof(INT));
    csi = (stride)malloc(sizeof(INT));

    *rs = 1;
    *csr = 1;
    *csi = 1;

    v = count;
    ivs = 1;
    ovs = 1;
    KP2_000000000 = 2.0;

    for (size_t idx = 0; idx < count; ++idx) {
        Cr[idx] = (R)(idx % 1000) / 1000.0;
        Ci[idx] = (R)((idx + 500) % 1000) / 1000.0;
        R0[idx] = 0.0;
        R1[idx] = 0.0;
    }
}