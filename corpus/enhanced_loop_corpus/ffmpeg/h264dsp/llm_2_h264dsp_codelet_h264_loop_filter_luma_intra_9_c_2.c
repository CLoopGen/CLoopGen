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



void loop() {
    // Variant 1: Consecutive Memory Access with Prefetched Indices
    // Instead of repeatedly calculating offsets with xstride, precompute array indices
    // and access memory consecutively via a temporary buffer to improve cache locality.
    
    ptrdiff_t base_offset = -3 * xstride;
    for (d = 0; d < 4 * inner_iters; d++) {
        const ptrdiff_t idx_p3 = base_offset - xstride;
        const ptrdiff_t idx_p2 = base_offset;
        const ptrdiff_t idx_p1 = base_offset + xstride;
        const ptrdiff_t idx_p0 = base_offset + 2 * xstride;
        const ptrdiff_t idx_q0 = base_offset + 3 * xstride;
        const ptrdiff_t idx_q1 = base_offset + 4 * xstride;
        const ptrdiff_t idx_q2 = base_offset + 5 * xstride;

        const int p2 = pix[idx_p2];
        const int p1 = pix[idx_p1];
        const int p0 = pix[idx_p0];
        const int q0 = pix[idx_q0];
        const int q1 = pix[idx_q1];
        const int q2 = pix[idx_q2];

        int diff_p0_q0 = (p0 > q0) ? p0 - q0 : q0 - p0;
        int diff_p1_p0 = (p1 > p0) ? p1 - p0 : p0 - p1;
        int diff_q1_q0 = (q1 > q0) ? q1 - q0 : q0 - q1;

        if (diff_p0_q0 < alpha && diff_p1_p0 < beta && diff_q1_q0 < beta) {
            if (diff_p0_q0 < ((alpha >> 2) + 2)) {
                int diff_p2_p0 = (p2 > p0) ? p2 - p0 : p0 - p2;
                if (diff_p2_p0 < beta) {
                    const int p3 = pix[idx_p3];
                    pix[idx_p0] = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                    pix[idx_p1] = (p2 + p1 + p0 + q0 + 2) >> 2;
                    pix[idx_p2] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
                } else {
                    pix[idx_p0] = (2 * p1 + p0 + q1 + 2) >> 2;
                }

                int diff_q2_q0 = (q2 > q0) ? q2 - q0 : q0 - q2;
                if (diff_q2_q0 < beta) {
                    const ptrdiff_t idx_q3 = base_offset + 6 * xstride;
                    const int q3 = pix[idx_q3];
                    pix[idx_q0] = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                    pix[idx_q1] = (p0 + q0 + q1 + q2 + 2) >> 2;
                    pix[idx_q2] = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
                } else {
                    pix[idx_q0] = (2 * q1 + q0 + p1 + 2) >> 2;
                }
            } else {
                pix[idx_p0] = (2 * p1 + p0 + q1 + 2) >> 2;
                pix[idx_q0] = (2 * q1 + q0 + p1 + 2) >> 2;
            }
        }
        base_offset += ystride;
    }
}
