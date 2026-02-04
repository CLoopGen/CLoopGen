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
E KP900968867;
E KP222520933;
E KP623489801;
E KP433883739;
E KP974927912;
E KP781831482;
INT i;

void init_vars() {
    const INT N = 1 << 20; // ~16 million elements, adjust for ~0.01s runtime
    const INT vec_size = 8; // implied by rs[7], csr[7], etc.

    // Allocate data arrays with padding to prevent out-of-bounds access
    R0 = (R*)aligned_alloc(64, sizeof(R) * N * 8);
    R1 = (R*)aligned_alloc(64, sizeof(R) * N * 8);
    Cr = (R*)aligned_alloc(64, sizeof(R) * N * 8);
    Ci = (R*)aligned_alloc(64, sizeof(R) * N * 8);

    if (!R0 || !R1 || !Cr || !Ci) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize coefficient constants
    KP900968867 = cos(-2.0 * M_PI / 7.0);
    KP222520933 = cos(-4.0 * M_PI / 7.0);
    KP623489801 = cos(-6.0 * M_PI / 7.0);
    KP433883739 = sin(-2.0 * M_PI / 7.0);
    KP974927912 = sin(-4.0 * M_PI / 7.0);
    KP781831482 = sin(-6.0 * M_PI / 7.0);

    // Allocate and initialize stride arrays
    rs  = (stride)aligned_alloc(64, sizeof(INT) * 8);
    csr = (stride)aligned_alloc(64, sizeof(INT) * 8);
    csi = (stride)aligned_alloc(64, sizeof(INT) * 8);

    if (!rs || !csr || !csi) {
        fprintf(stderr, "Stride allocation failed\n");
        exit(1);
    }

    for (INT j = 0; j < 8; ++j) {
        rs[j]  = j;
        csr[j] = j;
        csi[j] = j;
    }

    // Set loop parameters
    ivs = 8; // input vector stride
    ovs = 8; // output vector stride
    v = N;   // number of iterations

    // Initialize input data to avoid NaN or undefined behavior
    for (INT n = 0; n < N * 8; ++n) {
        R0[n] = sin(n * 0.01);
        R1[n] = cos(n * 0.01);
        Cr[n] = 0.0;
        Ci[n] = 0.0;
    }
}