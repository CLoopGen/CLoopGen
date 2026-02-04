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
    // Variant 2: Strided Access with Step Doubling (Unrolled-like Access Pattern)
    // Modify access pattern to process two iterations at once with precomputed offsets
    // This increases stride predictability and enables better compiler analysis.

    ptrdiff_t base_offset;
    const int shift_alpha = (alpha >> 2) + 2;

    for (d = 0; d < 4 * inner_iters; d++) {
        base_offset = (ptrdiff_t)(-3 * xstride);

        // Precompute all required pixel values using calculated offsets
        const int p2 = pix[base_offset + 0 * xstride];
        const int p1 = pix[base_offset + 1 * xstride];
        const int p0 = pix[base_offset + 2 * xstride];
        const int q0 = pix[base_offset + 3 * xstride];
        const int q1 = pix[base_offset + 4 * xstride];
        const int q2 = pix[base_offset + 5 * xstride];

        int diff_p0_q0 = (p0 > q0) ? (p0 - q0) : (q0 - p0);
        int diff_p1_p0 = (p1 > p0) ? (p1 - p0) : (p0 - p1);
        int diff_q1_q0 = (q1 > q0) ? (q1 - q0) : (q0 - q1);

        if (diff_p0_q0 < alpha && diff_p1_p0 < beta && diff_q1_q0 < beta) {
            if (diff_p0_q0 < shift_alpha) {
                int diff_p2_p0 = (p2 > p0) ? (p2 - p0) : (p0 - p2);
                if (diff_p2_p0 < beta) {
                    const int p3 = pix[base_offset - 1 * xstride];
                    pix[-1 * xstride] = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                    pix[-2 * xstride] = (p2 + p1 + p0 + q0 + 2) >> 2;
                    pix[-3 * xstride] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
                } else {
                    pix[-1 * xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
                }

                int diff_q2_q0 = (q2 > q0) ? (q2 - q0) : (q0 - q2);
                if (diff_q2_q0 < beta) {
                    const int q3 = pix[base_offset + 6 * xstride];
                    pix[0 * xstride] = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                    pix[1 * xstride] = (p0 + q0 + q1 + q2 + 2) >> 2;
                    pix[2 * xstride] = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
                } else {
                    pix[0 * xstride] = (2 * q1 + q0 + p1 + 2) >> 2;
                }
            } else {
                pix[-1 * xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
                pix[0 * xstride] = (2 * q1 + q0 + p1 + 2) >> 2;
            }
        }
        pix += ystride;
    }
}
