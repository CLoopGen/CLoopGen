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

E KP484122918 = 0.484122918;
E KP216506350 = 0.216506350;
E KP951056516 = 0.951056516;
E KP587785252 = 0.587785252;
E KP250000000 = 0.250000000;
E KP559016994 = 0.559016994;
E KP509036960 = 0.509036960;
E KP823639103 = 0.823639103;
E KP866025403 = 0.866025403;
E KP500000000 = 0.500000000;

INT i;

void init_vars() {
    const size_t N = 1 << 20; // ~1M elements, adjust for ~0.01s runtime
    const size_t stride_size = 8;

    R0 = (R*)aligned_alloc(64, sizeof(R) * N);
    R1 = (R*)aligned_alloc(64, sizeof(R) * N);
    Cr = (R*)aligned_alloc(64, sizeof(R) * N);
    Ci = (R*)aligned_alloc(64, sizeof(R) * N);

    rs = (stride)aligned_alloc(64, sizeof(INT) * stride_size);
    csr = (stride)aligned_alloc(64, sizeof(INT) * stride_size);
    csi = (stride)aligned_alloc(64, sizeof(INT) * stride_size);

    for (size_t idx = 0; idx < N; ++idx) {
        R0[idx] = (R)(idx % 100) / 100.0;
        R1[idx] = (R)((idx + 10) % 100) / 100.0;
        Cr[idx] = 0.0;
        Ci[idx] = 0.0;
    }

    for (size_t idx = 0; idx < stride_size; ++idx) {
        rs[idx] = (INT)(idx * 8);
        csr[idx] = (INT)(idx * 8);
        csi[idx] = (INT)(idx * 8);
    }

    ivs = 8;
    ovs = 8;
    v = (INT)(N / 8) - 1;
    if (v <= 0) v = 1;
}