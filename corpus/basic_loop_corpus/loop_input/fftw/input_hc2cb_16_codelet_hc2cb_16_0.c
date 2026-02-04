#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <inttypes.h>
#include <math.h>

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
E KP382683432;
E KP923879532;
E KP707106781;
INT m;

void init_vars() {
    const size_t N = 1 << 20; // ~8MB per array, total ~40MB, reasonable for 0.01s runtime
    const INT vector_size = 8; // inferred from rs[7] being used

    Rp = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Ip = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Rm = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    Im = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), 32 * vector_size * sizeof(R)); // max index 29 -> need at least 30, but align to multiple
    rs = (stride)aligned_alloc(sizeof(INT), vector_size * sizeof(INT));

    // Initialize constants
    KP382683432 = sin(2.0 * M_PI / 16.0); // approx 0.382683432
    KP923879532 = sin(7.0 * M_PI / 16.0); // approx 0.923879532
    KP707106781 = sin(M_PI / 4.0);        // approx 0.707106781

    // Initialize stride array: assume unit stride for simplicity and safety
    for (INT i = 0; i < vector_size; ++i) {
        rs[i] = i;
    }

    // Initialize data arrays with non-zero values to allow meaningful computation
    for (size_t i = 0; i < N; ++i) {
        Rp[i] = sin(i);
        Ip[i] = cos(i);
        Rm[i] = sin(i + 0.5);
        Im[i] = cos(i + 0.5);
    }

    // Initialize twiddle factors W: enough for indices up to 29
    for (INT i = 0; i < 30; ++i) {
        W[i] = sin(i * M_PI / 32.0);
    }

    // Set loop bounds to ensure valid memory access
    mb = 1;
    me = (N / vector_size) - 1; // ensure (mb-1)*30 + 30*steps doesn't overflow W
    if (me > 10000) me = 10000; // cap it to avoid overusing W
    ms = vector_size; // step by vector size in data arrays

    // Ensure W has enough space: reinitialize if needed based on loop increment
    // Original: W = W + ((mb - 1) * 30); then += 30 each iteration
    // Total offset: (mb-1)*30 + (me-mb)*30 = (me-1)*30
    size_t required_W_size = (me - 1) * 30 + 30;
    if (required_W_size > 32 * vector_size) {
        free(W);
        W = (R*)aligned_alloc(sizeof(R), required_W_size * sizeof(R));
        for (size_t i = 0; i < required_W_size; ++i) {
            W[i] = sin((i % 64) * M_PI / 64.0);
        }
    }
}