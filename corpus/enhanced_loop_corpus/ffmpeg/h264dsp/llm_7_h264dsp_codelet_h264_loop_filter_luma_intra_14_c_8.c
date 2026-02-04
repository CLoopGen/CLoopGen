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
    const ptrdiff_t base = d * ystride;
    uint16_t temp_store[6];
    const int p2 = pix[base - 3 * xstride];
    const int p1 = pix[base - 2 * xstride];
    const int p0 = pix[base - 1 * xstride];
    const int q0 = pix[base + 0 * xstride];
    const int q1 = pix[base + 1 * xstride];
    const int q2 = pix[base + 2 * xstride];

    const int diff_p0_q0 = p0 - q0;
    const int abs_p0_q0 = diff_p0_q0 < 0 ? -diff_p0_q0 : diff_p0_q0;
    const int abs_p1_p0 = (p1 - p0) < 0 ? -(p1 - p0) : (p1 - p0);
    const int abs_q1_q0 = (q1 - q0) < 0 ? -(q1 - q0) : (q1 - q0);

    if (abs_p0_q0 < alpha && abs_p1_p0 < beta && abs_q1_q0 < beta) {
        const int threshold = (alpha >> 2) + 2;
        if (abs_p0_q0 < threshold) {
            const int abs_p2_p0 = (p2 - p0) < 0 ? -(p2 - p0) : (p2 - p0);
            if (abs_p2_p0 < beta) {
                const int p3 = pix[base - 4 * xstride];
                temp_store[0] = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                temp_store[1] = (p2 + p1 + p0 + q0 + 2) >> 2;
                temp_store[2] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
            } else {
                temp_store[0] = (2 * p1 + p0 + q1 + 2) >> 2;
            }

            const int abs_q2_q0 = (q2 - q0) < 0 ? -(q2 - q0) : (q2 - q0);
            if (abs_q2_q0 < beta) {
                const int q3 = pix[base + 3 * xstride];
                temp_store[3] = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                temp_store[4] = (p0 + q0 + q1 + q2 + 2) >> 2;
                temp_store[5] = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
            } else {
                temp_store[3] = (2 * q1 + q0 + p1 + 2) >> 2;
            }

            if (abs_p2_p0 < beta) {
                pix[base - 3 * xstride] = temp_store[2];
                pix[base - 2 * xstride] = temp_store[1];
                pix[base - 1 * xstride] = temp_store[0];
            } else {
                pix[base - 1 * xstride] = temp_store[0];
            }

            if (abs_q2_q0 < beta) {
                pix[base + 2 * xstride] = temp_store[5];
                pix[base + 1 * xstride] = temp_store[4];
                pix[base + 0 * xstride] = temp_store[3];
            } else {
                pix[base + 0 * xstride] = temp_store[3];
            }
        } else {
            const int val_p = (2 * p1 + p0 + q1 + 2) >> 2;
            const int val_q = (2 * q1 + q0 + p1 + 2) >> 2;
            pix[base - 1 * xstride] = val_p;
            pix[base + 0 * xstride] = val_q;
        }
    }
}
}
