#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
E KP250000000;
E KP559016994;
E KP587785252;
E KP951056516;
INT m;

void init_vars() {
    const size_t N = 1 << 20; // ~1M elements, adjust for ~0.01s runtime

    mb = 1;
    me = N / 5 + 1; // ensures m < me runs for N/5 iterations
    ms = 2; // arbitrary stride multiplier
    KP250000000 = 0.25;
    KP559016994 = 0.559016994;
    KP587785252 = 0.587785252;
    KP951056516 = 0.951056516;

    cr = (R*)aligned_alloc(32, sizeof(R) * N);
    ci = (R*)aligned_alloc(32, sizeof(R) * N);
    W = (R*)aligned_alloc(32, sizeof(R) * (me - mb + 1) * 4);

    if (!cr || !ci || !W) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    rs = (stride)aligned_alloc(32, sizeof(INT) * 5);
    if (!rs) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    // Initialize rs indices to valid offsets within [0..N)
    rs[1] = 1 * ms;
    rs[2] = 2 * ms;
    rs[3] = 3 * ms;
    rs[4] = 4 * ms;

    // Ensure that all accessed cr[rs[i]], ci[rs[i]] are in bounds
    const INT max_offset = 4 * ms;
    const size_t required_size = max_offset + (me - mb) * ms;
    if (required_size >= N) {
        fprintf(stderr, "Size mismatch: increase N\n");
        exit(1);
    }

    // Initialize data arrays with non-zero values for meaningful computation
    for (size_t i = 0; i < N; ++i) {
        cr[i] = (R)(rand() % 1000) / 100.0;
        ci[i] = (R)(rand() % 1000) / 100.0;
    }
    for (size_t i = 0; i < (size_t)(me - mb + 1) * 4; ++i) {
        W[i] = (R)(rand() % 1000) / 100.0;
    }
}