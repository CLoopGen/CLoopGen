#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

// Define data size to target ~0.01 seconds runtime
// Based on typical performance, use ~16M elements to stay in L3 cache range but provide enough work
#define DATA_SIZE (1 << 22)  // ~16 million complex pairs -> ~256MB total

R *rio = NULL;
R *iio = NULL;
R *W = NULL;
stride rs = NULL;
stride vs = NULL;

INT mb = 0;
INT me = DATA_SIZE / 8;  // Each loop processes 8 elements (0..7 via vs[0..4], rs[0..4])
INT ms = 2;               // stride step for rio/iio increment

E KP250000000 = 0.25;
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;
E KP559016994 = 0.559016994;

INT m = 0;

void init_vars() {
    // Allocate input/output arrays
    rio = (R*)aligned_alloc(sizeof(R), DATA_SIZE * sizeof(R));
    iio = (R*)aligned_alloc(sizeof(R), DATA_SIZE * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), 8 * sizeof(R));  // W has 8 elements accessed: [0..7]

    // Allocate and initialize stride arrays
    rs = (stride)malloc(5 * sizeof(INT));
    vs = (stride)malloc(5 * sizeof(INT));

    // Initialize W coefficients (common twiddle factors)
    W[0] = 1.0;           W[1] = 0.0;
    W[2] = 0.809017;      W[3] = 0.587785;
    W[4] = 0.309017;      W[5] = 0.951057;
    W[6] = -0.309017;     W[7] = 0.951057;

    // Initialize rs strides: assume unit stride for base array access
    for (INT i = 0; i < 5; i++) {
        rs[i] = i * 2;  // Stride by 2 for real/imag interleaving
        vs[i] = i * (DATA_SIZE / 5);  // Distribute across data
    }

    // Ensure vs[4] doesn't exceed bounds when accessing +rs[4]
    vs[4] = (DATA_SIZE / 2) - 8;  // Safe offset within buffer

    // Initialize data arrays with non-zero values to avoid degenerate math
    for (INT i = 0; i < DATA_SIZE; i++) {
        rio[i] = (R)(i % 100) * 0.01;
        iio[i] = (R)((i + 10) % 100) * 0.01;
    }

    // Adjust me to ensure no out-of-bounds access
    // Each iteration uses m from mb to me, and accesses up to vs[4]+rs[4]
    // Ensure that (vs[1])+rs[4] etc. are valid
    INT max_offset = vs[4] + rs[4];
    INT usable_size = DATA_SIZE / 2;  // Working on half due to structure
    if (max_offset >= usable_size) {
        me = mb + (usable_size - max_offset) / 8;
    }
    if (me <= mb) {
        me = mb + 1;
    }
}