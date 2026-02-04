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
    // Variant 1: Consecutive Memory Access with Prefetching and Local Caching
    uint16_t local_cache[7];
    for (d = 0; d < 4 * inner_iters; d++) {
        // Prefetch data into a local array to enable consecutive access pattern
        const ptrdiff_t base_offset = -3 * xstride;
        for (int i = 0; i < 7; i++) {
            local_cache[i] = pix[base_offset + i * xstride];
        }

        const int p2 = local_cache[0];
        const int p1 = local_cache[1];
        const int p0 = local_cache[2];
        const int q0 = local_cache[3];
        const int q1 = local_cache[4];
        const int q2 = local_cache[5];

        const int diff_p0_q0 = (p0 > q0) ? (p0 - q0) : (q0 - p0);
        const int diff_p1_p0 = (p1 > p0) ? (p1 - p0) : (p0 - p1);
        const int diff_q1_q0 = (q1 > q0) ? (q1 - q0) : (q0 - q1);

        if (diff_p0_q0 < alpha && diff_p1_p0 < beta && diff_q1_q0 < beta) {
            const int threshold = (alpha >> 2) + 2;
            if (diff_p0_q0 < threshold) {
                const int diff_p2_p0 = (p2 > p0) ? (p2 - p0) : (p0 - p2);
                if (diff_p2_p0 < beta) {
                    const int p3 = local_cache[6]; // -4*xstride
                    pix[-1 * xstride] = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                    pix[-2 * xstride] = (p2 + p1 + p0 + q0 + 2) >> 2;
                    pix[-3 * xstride] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
                } else {
                    pix[-1 * xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
                }

                const int diff_q2_q0 = (q2 > q0) ? (q2 - q0) : (q0 - q2);
                if (diff_q2_q0 < beta) {
                    const int q3 = pix[3 * xstride]; // Not in cache, load directly
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
