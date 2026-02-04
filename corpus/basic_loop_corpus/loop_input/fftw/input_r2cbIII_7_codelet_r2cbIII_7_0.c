#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
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
E KP2_000000000 = 2.0;
E KP1_246979603 = 1.246979603;
E KP1_801937735 = 1.801937735;
E KP445041867 = 0.445041867;
E KP867767478 = 0.867767478;
E KP1_949855824 = 1.949855824;
E KP1_563662964 = 1.563662964;
INT i;

static R *alloc_aligned_double_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(R)) != 0) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    return (R *)ptr;
}

static stride alloc_aligned_stride_array(size_t n) {
    void *ptr;
    if (posix_memalign(&ptr, 32, n * sizeof(INT)) != 0) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }
    return (stride)ptr;
}

void init_vars() {
    const size_t base_size = 1 << 20; // 1M elements per array
    const INT vector_width = 4;

    v = base_size / vector_width;
    ivs = 1;
    ovs = 1;

    R0 = alloc_aligned_double_array(base_size + 8);
    R1 = alloc_aligned_double_array(base_size + 8);
    Cr = alloc_aligned_double_array(base_size + 8);
    Ci = alloc_aligned_double_array(base_size + 8);

    rs = alloc_aligned_stride_array(vector_width);
    csr = alloc_aligned_stride_array(vector_width);
    csi = alloc_aligned_stride_array(vector_width);

    for (INT j = 0; j < vector_width; ++j) {
        rs[j] = j * ovs;
        csr[j] = j * ivs;
        csi[j] = j * ivs;
    }

    for (size_t j = 0; j < base_size + 8; ++j) {
        Cr[j] = sin(j * 0.01);
        Ci[j] = cos(j * 0.01);
        R0[j] = 0.0;
        R1[j] = 0.0;
    }
}