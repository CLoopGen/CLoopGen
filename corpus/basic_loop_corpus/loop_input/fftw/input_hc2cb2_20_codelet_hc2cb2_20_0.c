#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

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
E KP250000000 = 0.25;
E KP559016994 = 0.559016994;
E KP587785252 = 0.587785252;
E KP951056516 = 0.951056516;
INT m;

void init_vars() {
    const size_t N = 1 << 20; // ~2^20 elements, total data ~few MBs for complex FFT-like data
    const INT alignment = 32;

    // Allocate aligned memory to prevent issues with vectorized access
    Rp = aligned_alloc(alignment, sizeof(R) * N);
    Ip = aligned_alloc(alignment, sizeof(R) * N);
    Rm = aligned_alloc(alignment, sizeof(R) * N);
    Im = aligned_alloc(alignment, sizeof(R) * N);
    W = aligned_alloc(alignment, sizeof(R) * (N + 16)); // Extra space for offset indexing

    // Allocate and initialize stride array: rs[0..10] used as offsets
    rs = aligned_alloc(alignment, sizeof(INT) * 10);
    rs[0] = 0; rs[1] = 1; rs[2] = 2; rs[3] = 3; rs[4] = 4;
    rs[5] = 5; rs[6] = 6; rs[7] = 7; rs[8] = 8; rs[9] = 9;

    // Set loop parameters
    mb = 1;
    me = 10000; // Adjusted to ensure W[(mb-1)*8 + ...] stays in bounds
    ms = 1;

    // Initialize data arrays to avoid NaN/inf and ensure predictable behavior
    for (size_t i = 0; i < N; ++i) {
        Rp[i] = (R)(i & 1 ? 1 : -1);
        Ip[i] = (R)((i % 3) == 0 ? 0.5 : -0.5);
        Rm[i] = (R)((i % 5) == 0 ? 1.0 : -0.2);
        Im[i] = (R)(i % 7 == 0 ? 0.3 : -0.4);
    }

    // Initialize twiddle factors W: each iteration uses 8 elements
    const size_t w_size = (me - mb + 1) * 8 + 16;
    for (size_t i = 0; i < w_size; ++i) {
        W[i] = (R)(1.0 / (1.0 + (i % 17))); // Avoid zero values
    }
}