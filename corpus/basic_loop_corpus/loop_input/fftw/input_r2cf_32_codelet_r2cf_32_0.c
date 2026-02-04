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
E KP555570233 = 0.555570233f;
E KP831469612 = 0.831469612f;
E KP195090322 = 0.195090322f;
E KP980785280 = 0.980785280f;
E KP382683432 = 0.382683432f;
E KP923879532 = 0.923879532f;
E KP707106781 = 0.707106781f;
INT i;

void init_vars() {
    const INT N = 16; // Based on rs[15] and similar accesses
    const INT total_size = 1 << 20; // Aim for ~1MB of data per array (adjustable)
    const INT num_vectors = total_size / (N * sizeof(R));
    const INT padded_num_vectors = num_vectors > 0 ? num_vectors : 1;

    v = padded_num_vectors;
    ivs = N;
    ovs = N;

    size_t data_size = (size_t)N * padded_num_vectors;

    R0 = (R*)aligned_alloc(64, data_size * sizeof(R));
    R1 = (R*)aligned_alloc(64, data_size * sizeof(R));
    Cr = (R*)aligned_alloc(64, data_size * sizeof(R));
    Ci = (R*)aligned_alloc(64, data_size * sizeof(R));

    rs = (stride)aligned_alloc(64, N * sizeof(INT));
    csr = (stride)aligned_alloc(64, N * sizeof(INT));
    csi = (stride)aligned_alloc(64, N * sizeof(INT));

    for (INT j = 0; j < N; ++j) {
        rs[j] = j;
        csr[j] = j;
        csi[j] = j;
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        R0[idx] = sin(idx * 0.01);
        R1[idx] = cos(idx * 0.01);
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }
}