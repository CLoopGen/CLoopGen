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
    // Variant 2: Strided Access with Index Vectorization Emulation
    // Simulate vectorized strided access using offset array for non-uniform strides
    const ptrdiff_t offsets[] = {-3, -2, -1, 0, 1, 2};
    const int num_offsets = 6;
    ptrdiff_t indexed_stride[num_offsets];

    // Precompute effective memory offsets based on xstride
    for (int i = 0; i < num_offsets; ++i) {
        indexed_stride[i] = offsets[i] * xstride;
    }

    for (d = 0; d < 4 * inner_iters; d++) {
        // Gather values using precomputed strided indices
        const int p2 = pix[indexed_stride[0]];
        const int p1 = pix[indexed_stride[1]];
        const int p0 = pix[indexed_stride[2]];
        const int q0 = pix[indexed_stride[3]];
        const int q1 = pix[indexed_stride[4]];
        const int q2 = pix[indexed_stride[5]];

        // Absolute differences using conditional-free arithmetic
        const int dp0q0 = p0 - q0;
        const int diff_p0_q0 = (dp0q0 ^ (dp0q0 >> 31)) - (dp0q0 >> 31);
        const int dp1p0 = p1 - p0;
        const int diff_p1_p0 = (dp1p0 ^ (dp1p0 >> 31)) - (dp1p0 >> 31);
        const int dq1q0 = q1 - q0;
        const int diff_q1_q0 = (dq1q0 ^ (dq1q0 >> 31)) - (dq1q0 >> 31);

        if (diff_p0_q0 < alpha && diff_p1_p0 < beta && diff_q1_q0 < beta) {
            const int threshold = (alpha >> 2) + 2;
            if (diff_p0_q0 < threshold) {
                const int dp2p0 = p2 - p0;
                const int diff_p2_p0 = (dp2p0 ^ (dp2p0 >> 31)) - (dp2p0 >> 31);
                if (diff_p2_p0 < beta) {
                    const int p3 = pix[-4 * xstride];
                    pix[-1 * xstride] = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                    pix[-2 * xstride] = (p2 + p1 + p0 + q0 + 2) >> 2;
                    pix[-3 * xstride] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
                } else {
                    pix[-1 * xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
                }

                const int dq2q0 = q2 - q0;
                const int diff_q2_q0 = (dq2q0 ^ (dq2q0 >> 31)) - (dq2q0 >> 31);
                if (diff_q2_q0 < beta) {
                    const int q3 = pix[3 * xstride];
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
