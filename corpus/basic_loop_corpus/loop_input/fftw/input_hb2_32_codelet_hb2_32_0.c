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

// Data size: aim for ~128MB of complex data (double precision)
#define DATA_SIZE (16*1024*1024)  // 16 million elements

R *cr;
R *ci;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP555570233;
E KP831469612;
E KP980785280;
E KP195090322;
E KP923879532;
E KP382683432;
E KP707106781;
INT m;

void init_vars() {
    // Initialize constants
    KP555570233 = 0.5555702330196022;
    KP831469612 = 0.8314696123025452;
    KP980785280 = 0.9807852804032304;
    KP195090322 = 0.19509032201612825;
    KP923879532 = 0.9238795325112867;
    KP382683432 = 0.3826834323650898;
    KP707106781 = 0.7071067811865476;

    // Allocate arrays
    cr = (R*)aligned_alloc(32, DATA_SIZE * sizeof(R));
    ci = (R*)aligned_alloc(32, DATA_SIZE * sizeof(R));
    W = (R*)aligned_alloc(32, 8 * sizeof(R));

    // Initialize W array with dummy twiddle factors
    for (int i = 0; i < 8; i++) {
        W[i] = sin((i + 1) * 0.5); // arbitrary values
    }

    // Allocate and initialize stride array
    rs = (stride)aligned_alloc(32, 32 * sizeof(INT)); // large enough for indexing up to rs[31]
    for (int i = 0; i < 32; i++) {
        rs[i] = (i * 17) % (DATA_SIZE / sizeof(R)); // ensure within bounds
    }

    // Set loop parameters
    mb = 1;
    me = 2;  // Run only one iteration to avoid out-of-bounds in W access: W + ((mb-1)*8) to W+8*(me-mb)
    ms = 1;

    // Initialize cr and ci with non-zero values to make computation meaningful
    for (INT i = 0; i < DATA_SIZE; i++) {
        cr[i] = sin(i * 0.0001);
        ci[i] = cos(i * 0.0001);
    }
}