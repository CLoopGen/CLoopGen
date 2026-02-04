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
    const int dp0q0 = (p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0));
    const int dp1p0 = (p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0));
    const int dq1q0 = (q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0));

    if (dp0q0 < alpha && dp1p0 < beta && dq1q0 < beta) {
        const int threshold = (alpha >> 2) + 2;
        const int use_extended_filter = dp0q0 < threshold;
        const int p2p0_diff = (p2 - p0) >= 0 ? (p2 - p0) : (-(p2 - p0));
        const int q2q0_diff = (q2 - q0) >= 0 ? (q2 - q0) : (-(q2 - q0));
        const int apply_p3 = use_extended_filter && (p2p0_diff < beta);
        const int apply_q3 = use_extended_filter && (q2q0_diff < beta);

        if (use_extended_filter) {
            if (apply_p3) {
                const int p3 = pix[-4 * xstride];
                pix[-1 * xstride] = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                pix[-2 * xstride] = (p2 + p1 + p0 + q0 + 2) >> 2;
                pix[-3 * xstride] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
            } else {
                pix[-1 * xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
            }

            if (apply_q3) {
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
