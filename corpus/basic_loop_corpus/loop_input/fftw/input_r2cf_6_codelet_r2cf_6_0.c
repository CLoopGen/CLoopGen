#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

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
E KP500000000;
E KP866025403;
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    const INT vector_length = data_size / (sizeof(R) * 4); // Using 4 arrays: R0, R1, Cr, Ci

    v = (vector_length > 0) ? vector_length : 1;

    ivs = 1;
    ovs = 1;

    KP500000000 = 0.5;
    KP866025403 = sin(M_PI / 3.0); // Approx 0.866025403

    R0 = (R*)aligned_alloc(64, sizeof(R) * data_size / (sizeof(R) * 4) * 3);
    R1 = (R*)aligned_alloc(64, sizeof(R) * data_size / (sizeof(R) * 4) * 3);
    Cr = (R*)aligned_alloc(64, sizeof(R) * data_size / (sizeof(R) * 4) * 4);
    Ci = (R*)aligned_alloc(64, sizeof(R) * data_size / (sizeof(R) * 4) * 4);

    rs = (stride)aligned_alloc(64, sizeof(INT) * 3);
    csr = (stride)aligned_alloc(64, sizeof(INT) * 4);
    csi = (stride)aligned_alloc(64, sizeof(INT) * 3);

    rs[0] = 0; rs[1] = 1; rs[2] = 2;
    csr[0] = 0; csr[1] = 1; csr[2] = 2; csr[3] = 3;
    csi[1] = 1; csi[2] = 2;

    for (INT j = 0; j < v * ivs * 3; ++j) {
        R0[j] = rand() / (R)RAND_MAX;
        R1[j] = rand() / (R)RAND_MAX;
    }
    for (INT j = 0; j < v * ovs * 4; ++j) {
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }
}