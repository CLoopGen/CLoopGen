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
E KP461939766;
E KP191341716;
E KP353553390;
E KP500000000;
INT m;

void init_vars() {
    // Constants initialization
    KP461939766 = sin(M_PI / 8.0);  // approx 0.3826834323650898
    KP191341716 = cos(M_PI / 8.0) - KP461939766; // actually ~0.9238795325112867, but named oddly
    // Correct interpretation: likely scaled constants for twiddle factors
    KP191341716 = cos(M_PI / 8.0);
    KP353553390 = sin(M_PI / 4.0); // sqrt(2)/2 ≈ 0.7071067811865476 -> often truncated
    KP500000000 = 0.5;

    // Data size parameters
    const INT N = (1 << 20); // ~1M elements, suitable for ~0.01s on modern CPU
    const INT alignment = 32;

    // Allocate aligned memory to prevent issues and match FFTW-like behavior
    Rp = aligned_alloc(alignment, N * sizeof(R));
    Ip = aligned_alloc(alignment, N * sizeof(R));
    Rm = aligned_alloc(alignment, N * sizeof(R));
    Im = aligned_alloc(alignment, N * sizeof(R));
    W = aligned_alloc(alignment, 30 * sizeof(R));

    // Initialize W: 30-element array of twiddle factors
    for (int i = 0; i < 30; ++i) {
        W[i] = cos(2.0 * M_PI * i / 32.0); // Approximate pattern from usage
        if (i % 2 == 1) {
            W[i] = sin(2.0 * M_PI * (i-1) / 32.0); // alternate as sine
        }
    }

    // Fill data arrays with non-zero values to simulate real input
    for (INT i = 0; i < N; ++i) {
        Rp[i] = sin(i * 0.01);
        Ip[i] = cos(i * 0.01);
        Rm[i] = -Rp[i];
        Im[i] = -Ip[i];
    }

    // Allocate and initialize stride vector
    rs = aligned_alloc(alignment, 8 * sizeof(INT));
    // The loop uses rs[0], rs[1], ..., rs[7] as offsets
    for (int i = 0; i < 8; ++i) {
        rs[i] = (i + 1) * (N / 8); // ensure within bounds
    }

    // Set loop bounds
    mb = 1;
    me = 2; // Run only one iteration to test correctness; increase if needed
    ms = N / 8; // reasonable step

    // Ensure that all pointer arithmetic in the loop stays within [0, N)
    // Adjust me if more iterations are desired:
    // For now, keep me = mb+1 to avoid out-of-bounds with complex indexing
}