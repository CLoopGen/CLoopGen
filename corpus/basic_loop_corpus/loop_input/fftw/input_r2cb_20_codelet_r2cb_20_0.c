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

E KP1_118033988 = 1.118033988;
E KP500000000 = 0.500000000;
E KP1_902113032 = 1.902113032;
E KP1_175570504 = 1.175570504;
E KP2_000000000 = 2.000000000;

INT i;

void init_vars() {
    const size_t data_size = 16 * 1024 * 1024; // ~16MB of complex data
    const INT vector_length = 11; // indices go up to [10], so need at least 11 elements

    R0 = (R*)aligned_alloc(32, data_size * sizeof(R));
    R1 = (R*)aligned_alloc(32, data_size * sizeof(R));
    Cr = (R*)aligned_alloc(32, data_size * sizeof(R));
    Ci = (R*)aligned_alloc(32, data_size * sizeof(R));

    if (!R0 || !R1 || !Cr || !Ci) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    rs = (stride)malloc(vector_length * sizeof(INT));
    csr = (stride)malloc(vector_length * sizeof(INT));
    csi = (stride)malloc(vector_length * sizeof(INT));

    if (!rs || !csr || !csi) {
        fprintf(stderr, "Stride allocation failed\n");
        exit(1);
    }

    for (INT j = 0; j < vector_length; ++j) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    for (size_t j = 0; j < data_size; ++j) {
        Cr[j] = sin(j * 0.01);
        Ci[j] = cos(j * 0.01);
        R0[j] = 0.0;
        R1[j] = 0.0;
    }

    v = data_size / vector_length;
    ivs = 1;
    ovs = 1;

    if (v <= 0) v = 1;
}