#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t xstride;
extern ptrdiff_t ystride;
extern int inner_iters;
extern int alpha;
extern int beta;
extern uint16_t *pix;
extern int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (d = 0; d < 4 * inner_iters; d++) {
    const int p0 = pix[-1 * xstride];
    const int p1 = pix[-2 * xstride];
    const int q0 = pix[0];
    const int q1 = pix[1 * xstride];
    const int abs_diff_p0_q0 = (p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0));

    // Simplified control: only check the strongest condition (alpha), remove beta checks
    if (abs_diff_p0_q0 < alpha) {
        // Apply filtering unconditionally when main threshold is met
        const int temp_p = (2 * p1 + p0 + q1 + 2) >> 2;
        const int temp_q = (2 * q1 + q0 + p1 + 2) >> 2;
        pix[-xstride] = temp_p;
        pix[0] = temp_q;
    }
    // No else branch — reduced control complexity
    pix += ystride;
}
}
