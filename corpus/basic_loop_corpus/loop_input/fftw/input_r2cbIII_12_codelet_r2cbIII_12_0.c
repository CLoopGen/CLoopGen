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
E KP1_414213562;
E KP2_000000000;
E KP500000000;
E KP866025403;
INT i;

static R *alloc_aligned_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 64, n * sizeof(R)) != 0) {
        exit(1);
    }
    return (R *)ptr;
}

static stride alloc_aligned_stride(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 64, n * sizeof(INT)) != 0) {
        exit(1);
    }
    return (stride)ptr;
}

void init_vars() {
    KP1_414213562 = 1.414213562;
    KP2_000000000 = 2.0;
    KP500000000 = 0.5;
    KP866025403 = 0.866025403;

    size_t data_size = 1 << 20; // ~8MB per array (adjust for ~0.01s runtime)
    Cr = alloc_aligned_array(data_size);
    Ci = alloc_aligned_array(data_size);
    size_t out_size = data_size * 2;
    R0 = alloc_aligned_array(out_size);
    R1 = alloc_aligned_array(out_size);

    rs = alloc_aligned_stride(6);
    csr = alloc_aligned_stride(6);
    csi = alloc_aligned_stride(6);

    for (int idx = 0; idx < 6; ++idx) {
        rs[idx] = idx;
        csr[idx] = idx * (data_size / 6);
        csi[idx] = idx * (data_size / 6);
    }

    ivs = 1;
    ovs = 1;

    v = data_size / 6;

    for (size_t j = 0; j < data_size; ++j) {
        Cr[j] = (R)(rand() % 1000) / 100.0;
        Ci[j] = (R)(rand() % 1000) / 100.0;
    }
    for (size_t j = 0; j < out_size; ++j) {
        R0[j] = 0.0;
        R1[j] = 0.0;
    }
}