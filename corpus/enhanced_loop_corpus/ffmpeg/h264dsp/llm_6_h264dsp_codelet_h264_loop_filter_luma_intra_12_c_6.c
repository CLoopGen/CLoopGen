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
    const int p2 = pix[-3 * xstride];
    const int p1 = pix[-2 * xstride];
    const int p0 = pix[-1 * xstride];
    const int q0 = pix[0 * xstride];
    const int q1 = pix[1 * xstride];
    const int q2 = pix[2 * xstride];
    const int abs_p0_q0 = (p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0));
    const int abs_p1_p0 = (p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0));
    const int abs_q1_q0 = (q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0));
    
    if (abs_p0_q0 < alpha && abs_p1_p0 < beta && abs_q1_q0 < beta) {
        const int threshold = (alpha >> 2) + 2;
        if (abs_p0_q0 < threshold) {
            const int abs_p2_p0 = (p2 - p0) >= 0 ? (p2 - p0) : (-(p2 - p0));
            if (abs_p2_p0 < beta) {
                const int p3 = pix[-4 * xstride];
                const int new_p0_val = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                const int new_p1_val = (p2 + p1 + p0 + q0 + 2) >> 2;
                const int new_p2_val = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
                pix[-1 * xstride] = new_p0_val;
                pix[-2 * xstride] = new_p1_val;
                pix[-3 * xstride] = new_p2_val;
            } else {
                pix[-1 * xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
            }
            const int abs_q2_q0 = (q2 - q0) >= 0 ? (q2 - q0) : (-(q2 - q0));
            if (abs_q2_q0 < beta) {
                const int q3 = pix[3 * xstride];
                const int new_q0_val = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                const int new_q1_val = (p0 + q0 + q1 + q2 + 2) >> 2;
                const int new_q2_val = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
                pix[0 * xstride] = new_q0_val;
                pix[1 * xstride] = new_q1_val;
                pix[2 * xstride] = new_q2_val;
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
