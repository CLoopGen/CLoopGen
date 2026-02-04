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
E KP382683432;
E KP923879532;
E KP707106781;
INT m;

void init_vars() {
    const INT N = 1 << 16; // ~64KB for cr/ci arrays, W needs more

    cr = (R*)aligned_alloc(32, N * sizeof(R));
    ci = (R*)aligned_alloc(32, N * sizeof(R));
    W = (R*)aligned_alloc(32, 32 * sizeof(R)); // W is accessed up to index 29
    rs = (stride)aligned_alloc(32, 16 * sizeof(INT));

    // Initialize constants
    KP382683432 = 0.382683432;
    KP923879532 = 0.923879532;
    KP707106781 = 0.707106781;

    // Initialize rs stride values: use safe positive offsets
    for (INT i = 0; i < 16; ++i) {
        rs[i] = i; // ensures rs[i] is valid index within bounds
    }

    // Initialize data arrays with non-zero values for meaningful computation
    for (INT i = 0; i < N; ++i) {
        cr[i] = sin(i);
        ci[i] = cos(i);
    }
    for (INT i = 0; i < 32; ++i) {
        W[i] = sin(i * 0.1); // W accessed from 0 to 29
    }

    // Set loop parameters to ensure valid memory access
    mb = 1;
    me = 2; // Run only one iteration to avoid out-of-bounds on W and pointer updates
    ms = 1;

    // Ensure initial W offset (mb-1)*30 = 0, so W starts at base
    // Adjusted me to prevent W from going out of bounds
}