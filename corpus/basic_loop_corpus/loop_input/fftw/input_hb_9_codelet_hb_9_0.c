#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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
E KP984807753;
E KP173648177;
E KP342020143;
E KP939692620;
E KP642787609;
E KP766044443;
E KP500000000;
E KP866025403;
INT m;

void init_vars() {
    // Initialize constants
    KP984807753 = 0.984807753;
    KP173648177 = 0.173648177;
    KP342020143 = 0.342020143;
    KP939692620 = 0.939692620;
    KP642787609 = 0.642787609;
    KP766044443 = 0.766044443;
    KP500000000 = 0.5;
    KP866025403 = 0.866025403;

    // Problem size: aim for ~100ms runtime; the loop does ~18 complex arithmetic ops per iteration
    // We'll allocate enough data so that the loop runs for several thousand iterations
    // The stride array rs has at least 9 elements (rs[8] is accessed), and W has 16 elements per iteration
    // cr and ci are indexed with rs[i], which implies scattered access

    const INT N = 1 << 18;  // ~256K elements, ~2MB per array
    const INT max_stride_index = 8;
    const INT num_W_per_iter = 16;

    // Allocate cr and ci: real and imaginary parts of complex data
    cr = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    ci = (R*)aligned_alloc(sizeof(R), N * sizeof(R));
    W = (R*)aligned_alloc(sizeof(R), N * num_W_per_iter * sizeof(R));

    // Allocate and initialize stride array
    rs = (INT*)malloc((max_stride_index + 1) * sizeof(INT));
    for (INT i = 0; i <= max_stride_index; ++i) {
        rs[i] = i * 31;  // pseudo-random stride pattern, ensure within bounds
    }

    // Set loop parameters
    mb = 1;
    me = (N - 1) / 100;  // adjust to avoid out-of-bounds in cr[rs[8]], etc.
    if (me > 10000) me = 10000;  // cap iterations for predictable timing (~0.01s)
    ms = 1;

    // Initialize cr, ci, W with non-zero values to prevent compiler from optimizing away computations
    for (INT i = 0; i < N; ++i) {
        cr[i] = sin(i * 0.01);
        ci[i] = cos(i * 0.01);
    }
    for (INT i = 0; i < N * num_W_per_iter; ++i) {
        W[i] = sin(i * 0.001);
    }
}