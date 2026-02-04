#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef double E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;
R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP707106781;
INT m;

static size_t data_size;
static R *alloc_buffer;

void init_vars() {
    // Set constants
    KP707106781 = 0.707106781; // Approximation of 1/sqrt(2)

    // Estimate workload for ~0.01s runtime: aim for about 1M iterations
    // Each iteration touches several memory locations with strides.
    // We'll set the loop to run about 1<<17 = 131072 iterations, and ensure data fits in cache reasonably.

    mb = 1;
    me = (1 << 17) + 1;  // so m goes from 1 to 131071
    ms = 1;              // stride step for pointer increments

    // Allocate a buffer large enough to hold all arrays with maximum offset
    // The largest index used: 
    //   rs[3] is used -> need at least 4 elements in rs
    //   Rp[rs[3]], etc., so rs values must be within bounds
    // W is accessed up to index 13, and incremented by 14 per loop -> total size: (me - mb) * 14 + 14
    // Let's set rs to small fixed offsets: 0,1,2,3 for simplicity and safety

    rs = (INT*)calloc(4, sizeof(INT));
    if (!rs) abort();
    rs[0] = 0;
    rs[1] = 1;
    rs[2] = 2;
    rs[3] = 3;

    size_t w_size = (me - mb + 1) * 14 + 16;  // extra padding
    size_t vec_len = (me - mb + 1) * abs(ms) + 4;  // enough for Rp, Ip, Rm, Im with offsets

    data_size = sizeof(R) * (4 * vec_len + w_size);
    alloc_buffer = (R*)aligned_alloc(64, data_size);
    if (!alloc_buffer) abort();

    Rp = alloc_buffer;
    Ip = Rp + vec_len;
    Rm = Ip + vec_len;
    Im = Rm + vec_len;
    W  = Im + vec_len;

    // Initialize W: contains interleaved cosine/sine values, 14 per block
    for (INT i = 0; i < (me - mb + 1); i++) {
        for (int j = 0; j < 14; j++) {
            W[i * 14 + j] = sin((j + 1) * 0.1 * i); // dummy trigonometric-like data
        }
    }

    // Initialize vector data: fill with non-zero values to avoid division-by-zero or no-op issues
    for (size_t i = 0; i < vec_len; i++) {
        Rp[i] = sin(i + 1);
        Ip[i] = cos(i + 1);
        Rm[i] = sin(i + 0.5);
        Im[i] = cos(i + 0.5);
    }

    // Ensure that initial W pointer starts at correct offset
    W = W + ((mb - 1) * 14);
}