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
for (d = 0; d < 8 * inner_iters; d += 2) {
    const int p0_1 = pix[-1 * xstride];
    const int p1_1 = pix[-2 * xstride];
    const int q0_1 = pix[0];
    const int q1_1 = pix[1 * xstride];
    const int p0_2 = pix[ystride - 1 * xstride];
    const int p1_2 = pix[ystride - 2 * xstride];
    const int q0_2 = pix[ystride];
    const int q1_2 = pix[ystride + 1 * xstride];

    const int abs_diff1 = (p0_1 - q0_1) >= 0 ? (p0_1 - q0_1) : (-(p0_1 - q0_1));
    const int abs_diff2 = (p1_1 - p0_1) >= 0 ? (p1_1 - p0_1) : (-(p1_1 - p0_1));
    const int abs_diff3 = (q1_1 - q0_1) >= 0 ? (q1_1 - q0_1) : (-(q1_1 - q0_1));

    const int abs_diff4 = (p0_2 - q0_2) >= 0 ? (p0_2 - q0_2) : (-(p0_2 - q0_2));
    const int abs_diff5 = (p1_2 - p0_2) >= 0 ? (p1_2 - p0_2) : (-(p1_2 - p0_2));
    const int abs_diff6 = (q1_2 - q0_2) >= 0 ? (q1_2 - q0_2) : (-(q1_2 - q0_2));

    if (abs_diff1 < alpha && abs_diff2 < beta && abs_diff3 < beta) {
        pix[-xstride] = (2 * p1_1 + p0_1 + q1_1 + 2) >> 2;
        pix[0] = (2 * q1_1 + q0_1 + p1_1 + 2) >> 2;
    }
    if (abs_diff4 < alpha && abs_diff5 < beta && abs_diff6 < beta) {
        pix[ystride - xstride] = (2 * p1_2 + p0_2 + q1_2 + 2) >> 2;
        pix[ystride] = (2 * q1_2 + q0_2 + p1_2 + 2) >> 2;
    }
    pix += 2 * ystride;
}
}
