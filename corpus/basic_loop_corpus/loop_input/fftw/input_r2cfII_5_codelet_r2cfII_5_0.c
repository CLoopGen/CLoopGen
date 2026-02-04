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
E KP250000000 = 0.25;
E KP559016994 = 0.559016994;
E KP951056516 = 0.951056516;
E KP587785252 = 0.587785252;
INT i = 0;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64M elements, adjust for ~0.01 sec runtime
    const size_t num_vectors = data_size / (sizeof(R) * 4); // Estimate for vector size

    R0 = (R*)aligned_alloc(32, data_size);
    R1 = (R*)aligned_alloc(32, data_size);
    Cr = (R*)aligned_alloc(32, data_size);
    Ci = (R*)aligned_alloc(32, data_size);

    rs = (INT*)aligned_alloc(32, 3 * sizeof(INT));
    csr = (INT*)aligned_alloc(32, 3 * sizeof(INT));
    csi = (INT*)aligned_alloc(32, 3 * sizeof(INT));

    if (!R0 || !R1 || !Cr || !Ci || !rs || !csr || !csi) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (size_t i = 0; i < data_size / sizeof(R); ++i) {
        R0[i] = (R)(i % 100) * 0.1;
        R1[i] = (R)((i + 1) % 100) * 0.1;
        Cr[i] = 0.0;
        Ci[i] = 0.0;
    }

    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;

    csr[0] = 0;
    csr[1] = 1;
    csr[2] = 2;

    csi[0] = 0;
    csi[1] = 1;
    csi[2] = 2;

    ivs = 1;
    ovs = 1;

    v = num_vectors > 0 ? num_vectors : 1;

    KP250000000 = 0.25;
    KP559016994 = 0.55901699437494745;
    KP951056516 = 0.95105651629515357;
    KP587785252 = 0.58778525229247314;
}