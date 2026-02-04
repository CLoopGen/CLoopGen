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
E KP222520933 = 0.222520933;
E KP900968867 = 0.900968867;
E KP623489801 = 0.623489801;
E KP433883739 = 0.433883739;
E KP781831482 = 0.781831482;
E KP974927912 = 0.974927912;
INT i;

static size_t data_size;

void init_vars() {
    const INT vector_length = 65536; // Adjust to achieve ~0.01 sec runtime
    data_size = vector_length * sizeof(R);

    v = vector_length;
    ivs = 1;
    ovs = 1;

    R0 = (R*)aligned_alloc(32, data_size);
    R1 = (R*)aligned_alloc(32, data_size);
    Cr = (R*)aligned_alloc(32, data_size);
    Ci = (R*)aligned_alloc(32, data_size);

    rs = (stride)aligned_alloc(32, 4 * sizeof(INT));
    csr = (stride)aligned_alloc(32, 4 * sizeof(INT));
    csi = (stride)aligned_alloc(32, 4 * sizeof(INT));

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

    for (INT j = 0; j < v; ++j) {
        R0[j] = (R)(j % 100) * 0.01;
        R1[j] = (R)((j + 27) % 100) * 0.01;
    }
    for (INT j = 0; j < v * 2; ++j) {
        if (j < v) {
            Cr[j] = 0.0;
            Ci[j] = 0.0;
        }
    }
}