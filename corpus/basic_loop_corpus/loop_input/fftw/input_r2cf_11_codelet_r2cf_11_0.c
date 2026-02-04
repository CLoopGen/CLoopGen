#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *R0 = NULL;
R *R1 = NULL;
R *Cr = NULL;
R *Ci = NULL;
stride rs = NULL;
stride csr = NULL;
stride csi = NULL;
INT v = 0;
INT ivs = 0;
INT ovs = 0;

E KP654860733 = 0.654860733;
E KP142314838 = 0.142314838;
E KP959492973 = 0.959492973;
E KP415415013 = 0.415415013;
E KP841253532 = 0.841253532;
E KP989821441 = 0.989821441;
E KP909631995 = 0.909631995;
E KP281732556 = 0.281732556;
E KP540640817 = 0.540640817;
E KP755749574 = 0.755749574;

INT i = 0;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data
    const size_t align = 32;

    R0 = aligned_alloc(align, data_size);
    R1 = aligned_alloc(align, data_size);
    Cr = aligned_alloc(align, data_size);
    Ci = aligned_alloc(align, data_size);

    rs = aligned_alloc(align, 8 * sizeof(INT));
    csr = aligned_alloc(align, 8 * sizeof(INT));
    csi = aligned_alloc(align, 8 * sizeof(INT));

    ivs = 1;
    ovs = 1;

    for (size_t idx = 0; idx < data_size / sizeof(R); ++idx) {
        R0[idx] = (R)(idx % 100) * 0.01;
        R1[idx] = (R)((idx + 10) % 100) * 0.01;
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    for (int idx = 0; idx < 8; ++idx) {
        rs[idx] = idx * 8;
        csr[idx] = idx * 8;
        csi[idx] = idx * 8;
    }

    v = 8192;

    i = 0;
}