#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t xstride;
extern ptrdiff_t ystride;
extern int inner_iters;
extern int alpha;
extern int beta;
extern uint8_t *pix;
extern int d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (d = 0; d < 4 * inner_iters; d++) {
    const int p2 = pix[-3 * xstride];
    const int p1 = pix[-2 * xstride];
    const int p0 = pix[-1 * xstride];
    const int q0 = pix[0 * xstride];
    const int q1 = pix[1 * xstride];
    const int q2 = pix[2 * xstride];
    const int abs_p0_q0 = (p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0));
    const int abs_p1_p0 = (p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0));
    const int abs_q1_q0 = (q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0));

    // Simplify control flow: Remove nested condition on (alpha >> 2) + 2
    // Always apply strong filtering if edge and gradient conditions are met
    if (abs_p0_q0 < alpha && abs_p1_p0 < beta && abs_q1_q0 < beta) {
        const int use_strong_filter = abs_p0_q0 < ((alpha >> 2) + 2);
        const int p2p0_abs = (p2 - p0) >= 0 ? (p2 - p0) : (-(p2 - p0));
        const int q2q0_abs = (q2 - q0) >= 0 ? (q2 - q0) : (-(q2 - q0));
        const int has_smooth_p_side = use_strong_filter && (p2p0_abs < beta);
        const int has_smooth_q_side = use_strong_filter && (q2q0_abs < beta);

        // Apply strong filter only when both sides are smooth, otherwise weak
        if (has_smooth_p_side && has_smooth_q_side) {
            const int p3 = pix[-4 * xstride];
            const int q3 = pix[3 * xstride];
            pix[-3 * xstride] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
            pix[-2 * xstride] = (p2 + p1 + p0 + q0 + 2) >> 2;
            pix[-1 * xstride] = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
            pix[0 * xstride] = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
            pix[1 * xstride] = (p0 + q0 + q1 + q2 + 2) >> 2;
            pix[2 * xstride] = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
        } else {
            // Weak filter applied unconditionally when base conditions pass
            pix[-1 * xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
            pix[0 * xstride] = (2 * q1 + q0 + p1 + 2) >> 2;
            // Skip updating p2/q2 positions to reduce memory traffic
        }
    }
    // No early exit — always advance pointer
    pix += ystride;
}
}
