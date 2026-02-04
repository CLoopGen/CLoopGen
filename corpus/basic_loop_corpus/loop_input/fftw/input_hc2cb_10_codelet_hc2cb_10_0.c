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
R *Rp;
R *Ip;
R *Rm;
R *Im;
R *W;
stride rs;
INT mb;
INT me;
INT ms;
E KP250000000;
E KP951056516;
E KP587785252;
E KP559016994;
INT m;

void init_vars() {
    const size_t data_size = 1 << 20; // ~1MB of working data
    const INT vector_length = data_size / (sizeof(R) * 10); // Estimate for complex pairs and twiddle factors

    // Set constants
    KP250000000 = 0.25;
    KP951056516 = sin(2.0 * M_PI / 5.0);
    KP587785252 = sin(M_PI / 5.0);
    KP559016994 = tan(M_PI / 8.0);

    // Allocate rs as a small array of strides
    rs = (stride)aligned_alloc(sizeof(INT), sizeof(INT) * 5);
    for (INT i = 0; i < 5; i++) {
        rs[i] = (i == 0) ? 0 : (vector_length >> 3) >> i; // decreasing strides
    }

    // Set loop bounds to stay within allocated memory
    mb = 1;
    ms = 1;
    me = vector_length / 8 - 1; // Ensure W indexing with +18 stays in bounds

    // Allocate arrays with padding to prevent out-of-bounds access
    Rp = (R*)aligned_alloc(64, sizeof(R) * (me + 10) * ms);
    Ip = (R*)aligned_alloc(64, sizeof(R) * (me + 10) * ms);
    Rm = (R*)aligned_alloc(64, sizeof(R) * (me + 10) * ms);
    Im = (R*)aligned_alloc(64, sizeof(R) * (me + 10) * ms);
    W = (R*)aligned_alloc(64, sizeof(R) * ((me - mb + 2) * 18 + 20));

    // Initialize all arrays to avoid NaNs or extreme values
    memset(Rp, 0, sizeof(R) * (me + 10) * ms);
    memset(Ip, 0, sizeof(R) * (me + 10) * ms);
    memset(Rm, 0, sizeof(R) * (me + 10) * ms);
    memset(Im, 0, sizeof(R) * (me + 10) * ms);
    for (INT i = 0; i < ((me - mb + 2) * 18 + 20); i++) {
        W[i] = sin(i * 0.1) + cos(i * 0.15);
    }
}