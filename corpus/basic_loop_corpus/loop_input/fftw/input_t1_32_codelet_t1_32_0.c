#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

typedef ptrdiff_t INT;
typedef double R;
typedef INT *stride;
typedef R E;

const INT fftw_an_INT_guaranteed_to_be_zero = 0;

R *ri;
R *ii;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP195090322;
E KP980785280;
E KP555570233;
E KP831469612;
E KP382683432;
E KP923879532;
E KP707106781;
INT m;

void init_vars() {
    const INT N = 32;
    const INT data_size = 1 << 20; // ~1MB of complex data (each double is 8 bytes)
    const INT total_elements = data_size / (2 * sizeof(R)); // number of complex numbers

    // Initialize constants
    KP195090322 = 0.19509032201612825;
    KP980785280 = 0.9807852804032304;
    KP555570233 = 0.5555702330196022;
    KP831469612 = 0.8314696123025452;
    KP382683432 = 0.3826834323650898;
    KP923879532 = 0.9238795325112867;
    KP707106781 = 0.7071067811865476;

    // Allocate arrays
    ri = (R*)aligned_alloc(64, total_elements * sizeof(R));
    ii = (R*)aligned_alloc(64, total_elements * sizeof(R));
    W = (R*)aligned_alloc(64, N * 62 * sizeof(R));
    rs = (stride)aligned_alloc(64, N * sizeof(INT));

    // Initialize rs stride values: rs[i] = i for i in [0, N-1]
    for (INT i = 0; i < N; ++i) {
        rs[i] = i;
    }

    // Initialize twiddle factors W
    for (INT i = 0; i < N; ++i) {
        for (INT k = 0; k < 31; ++k) {
            double angle = 2.0 * M_PI * i * k / (2 * N);
            W[i * 62 + k] = cos(angle);
            W[i * 62 + k + 1] = -sin(angle); // conjugate for forward transform
        }
        // Mirror symmetry or zero padding for remaining entries if needed
        for (INT k = 62 - 31; k < 62; ++k) {
            W[i * 62 + k] = 0.0;
        }
    }

    // Set loop bounds to ensure safe access within allocated data
    mb = 0;
    me = total_elements > N ? N : total_elements;
    ms = 1;

    // Initialize input data with non-zero values to avoid trivial computations
    for (INT i = 0; i < total_elements; ++i) {
        ri[i] = (R)(i & 1 ? 1.0 : -1.0);
        ii[i] = (R)((i % 3) == 0 ? 0.5 : 0.0);
    }
}