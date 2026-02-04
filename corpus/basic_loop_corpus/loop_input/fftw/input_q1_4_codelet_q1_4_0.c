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
R *rio;
R *iio;
R *W;
stride rs;
stride vs;
INT mb;
INT me;
INT ms;
INT m;

static size_t data_size;
static void init_arrays() {
    // Total number of loop iterations for ~0.01 sec: estimate based on typical FFTW-like kernels
    // Assume each iteration does ~100-200 flops; modern CPU does ~3-10 GFLOPS -> aim for ~50M iterations?
    // But memory-bound: let's target total data around 64MB to 128MB

    // Each iteration accesses multiple offsets in rio, iio: up to (vs[3]) + (rs[3])
    // We assume rs and vs are strides for multi-dimensional access.
    // Let’s assume worst-case offset: vs[3] and rs[3] could be large.

    // To be safe, we choose:
    //   me - mb ≈ 1 << 16 = 65536 iterations
    //   vector size: 4 elements (indexed by vs[0..3]), stride dimension rs[0..3]
    //   so total complex data per array: 4 * 4 = 16 per "row", and 65536 rows

    mb = 0;
    me = 1 << 16;  // 65536 iterations
    ms = 1;        // increment step

    // Allocate rs and vs as arrays of 4 INTs
    rs = (stride)aligned_alloc(sizeof(INT), 4 * sizeof(INT));
    vs = (stride)aligned_alloc(sizeof(INT), 4 * sizeof(INT));

    // Set reasonable strides: like a 4x4 matrix view: rs is inner, vs is outer
    rs[0] = 0; rs[1] = 1; rs[2] = 2; rs[3] = 3;
    vs[0] = 0; vs[1] = 4; vs[2] = 8; vs[3] = 12;

    // Maximum offset: vs[3] + rs[3] = 12 + 3 = 15
    // So each "block" needs 16 elements
    // Total blocks: me - mb = 65536
    // Total elements per array: 65536 * 16 = 1048576
    data_size = me * 16;

    rio = (R*)aligned_alloc(32, data_size * sizeof(R));
    iio = (R*)aligned_alloc(32, data_size * sizeof(R));
    // W: each iteration uses W[m*6], and reads 6 elements: W[0] to W[5]
    // So we need (me - mb) * 6 elements in W
    W = (R*)aligned_alloc(32, me * 6 * sizeof(R));

    // Initialize rio and iio with non-zero test data to avoid division-by-zero or flat results
    for (size_t i = 0; i < data_size; ++i) {
        rio[i] = sin(i * 0.001);
        iio[i] = cos(i * 0.001);
    }

    // Initialize W: rotation factors, e.g., simulate twiddle factors
    for (INT i = 0; i < me; ++i) {
        double angle = 2.0 * M_PI * i / me;
        W[i * 6 + 0] = cos(angle);
        W[i * 6 + 1] = sin(angle);
        W[i * 6 + 2] = cos(2.0 * angle);
        W[i * 6 + 3] = sin(2.0 * angle);
        W[i * 6 + 4] = cos(3.0 * angle);
        W[i * 6 + 5] = sin(3.0 * angle);
    }
}

void init_vars() {
    init_arrays();
}