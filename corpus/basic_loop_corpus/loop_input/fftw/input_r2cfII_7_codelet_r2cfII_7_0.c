#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

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
E KP900968867;
E KP222520933;
E KP623489801;
E KP433883739;
E KP974927912;
E KP781831482;
INT i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB of total data, adjust as needed
    const INT vector_length = 16384; // Number of iterations to achieve ~0.01s runtime

    R0 = (R*)aligned_alloc(32, data_size * sizeof(R));
    R1 = (R*)aligned_alloc(32, data_size * sizeof(R));
    Cr = (R*)aligned_alloc(32, data_size * sizeof(R));
    Ci = (R*)aligned_alloc(32, data_size * sizeof(R));

    rs = (INT*)aligned_alloc(32, 4 * sizeof(INT));
    csr = (INT*)aligned_alloc(32, 4 * sizeof(INT));
    csi = (INT*)aligned_alloc(32, 4 * sizeof(INT));

    for (INT j = 0; j < data_size; ++j) {
        R0[j] = (R)(rand() % 1000) / 100.0;
        R1[j] = (R)(rand() % 1000) / 100.0;
        Cr[j] = 0.0;
        Ci[j] = 0.0;
    }

    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;

    csr[0] = 0;
    csr[1] = 1;
    csr[2] = 2;
    csr[3] = 3;

    csi[0] = 0;
    csi[1] = 1;
    csi[2] = 2;
    csi[3] = 3;

    v = vector_length;
    ivs = 4;
    ovs = 4;

    KP900968867 = (E)-0.900968867;
    KP222520933 = (E)-0.222520933;
    KP623489801 = (E)-0.623489801;
    KP433883739 = (E)-0.433883739;
    KP974927912 = (E)-0.974927912;
    KP781831482 = (E)-0.781831482;
}