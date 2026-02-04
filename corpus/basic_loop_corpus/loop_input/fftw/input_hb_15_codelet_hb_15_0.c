#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP559016994;
E KP250000000;
E KP951056516;
E KP587785252;
E KP500000000;
E KP866025403;
INT m;

static size_t total_data_size = 268435456; // ~256MB of total data

void init_vars() {
    // Initialize constants
    KP559016994 = 0.559016994;
    KP250000000 = 0.250000000;
    KP951056516 = 0.951056516;
    KP587785252 = 0.587785252;
    KP500000000 = 0.500000000;
    KP866025403 = 0.866025403;

    // Allocate rs as an array of strides (ptrdiff_t) with sufficient size
    rs = (stride)calloc(15, sizeof(INT));
    for (int i = 0; i < 15; i++) {
        rs[i] = i; // rs[i] used as index offsets: rs[0]=0, rs[1]=1, ..., rs[14]=14
    }

    // Each iteration accesses up to rs[14], so we need at least 15 elements in cr and ci
    // We'll allocate large arrays to meet data size target
    size_t num_elements = total_data_size / (sizeof(R) * 2); // Two arrays: cr and ci
    if (num_elements < 15) num_elements = 15;

    cr = (R*)calloc(num_elements, sizeof(R));
    ci = (R*)calloc(num_elements, sizeof(R));

    // W is accessed up to index 27, and incremented by 28 per loop step
    // We need enough W blocks for the number of loop iterations
    mb = 1;
    ms = 1;
    me = (num_elements / 15); // Ensure we don't exceed cr/ci bounds
    if (me < 2) me = 2;

    size_t w_size = ((me - mb) * 28) + 28; // Enough for all iterations plus offset
    W = (R*)calloc(w_size, sizeof(R));
    for (size_t i = 0; i < w_size; i++) {
        W[i] = 1.0 + (i * 0.001); // Non-zero to avoid trivial math
    }

    // Initialize cr and ci with non-zero values to ensure computation effect
    for (size_t i = 0; i < num_elements; i++) {
        cr[i] = (R)(i * 0.0001);
        ci[i] = (R)(i * 0.0002);
    }
}