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
    const ptrdiff_t offset = d * ystride;
    const int p2 = pix[-3 * xstride + offset];
    const int p1 = pix[-2 * xstride + offset];
    const int p0 = pix[-1 * xstride + offset];
    const int q0 = pix[0 * xstride + offset];
    const int q1 = pix[1 * xstride + offset];
    const int q2 = pix[2 * xstride + offset];
    const int abs_diff_p0_q0 = (p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0));
    const int abs_diff_p1_p0 = (p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0));
    const int abs_diff_q1_q0 = (q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0));

    if (abs_diff_p0_q0 < alpha && abs_diff_p1_p0 < beta && abs_diff_q1_q0 < beta) {
        const int threshold = (alpha >> 2) + 2;
        if (abs_diff_p0_q0 < threshold) {
            const int abs_diff_p2_p0 = (p2 - p0) >= 0 ? (p2 - p0) : (-(p2 - p0));
            if (abs_diff_p2_p0 < beta) {
                const int p3 = pix[-4 * xstride + offset];
                const int new_p0 = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                const int new_p1 = (p2 + p1 + p0 + q0 + 2) >> 2;
                const int new_p2 = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
                pix[-1 * xstride + offset] = new_p0;
                pix[-2 * xstride + offset] = new_p1;
                pix[-3 * xstride + offset] = new_p2;
            } else {
                const int new_p0 = (2 * p1 + p0 + q1 + 2) >> 2;
                pix[-1 * xstride + offset] = new_p0;
            }
            const int abs_diff_q2_q0 = (q2 - q0) >= 0 ? (q2 - q0) : (-(q2 - q0));
            if (abs_diff_q2_q0 < beta) {
                const int q3 = pix[3 * xstride + offset];
                const int new_q0 = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                const int new_q1 = (p0 + q0 + q1 + q2 + 2) >> 2;
                const int new_q2 = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
                pix[0 * xstride + offset] = new_q0;
                pix[1 * xstride + offset] = new_q1;
                pix[2 * xstride + offset] = new_q2;
            } else {
                const int new_q0 = (2 * q1 + q0 + p1 + 2) >> 2;
                pix[0 * xstride + offset] = new_q0;
            }
        } else {
            const int new_p0 = (2 * p1 + p0 + q1 + 2) >> 2;
            const int new_q0 = (2 * q1 + q0 + p1 + 2) >> 2;
            pix[-1 * xstride + offset] = new_p0;
            pix[0 * xstride + offset] = new_q0;
        }
    }
}
}
