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
    const int p0 = pix[-1 * xstride];
    const int p1 = pix[-2 * xstride];
    const int q0 = pix[0];
    const int q1 = pix[1 * xstride];
    const int abs_diff_p0_q0 = (p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0));
    const int abs_diff_p1_p0 = (p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0));
    const int abs_diff_q1_q0 = (q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0));

    int condition = 1;
    if (abs_diff_p0_q0 >= alpha) condition = 0;
    if (abs_diff_p1_p0 >= beta) condition = 0;
    if (abs_diff_q1_q0 >= beta) condition = 0;

    if (condition) {
        const int temp1 = (2 * p1 + p0 + q1 + 2) >> 2;
        const int temp2 = (2 * q1 + q0 + p1 + 2) >> 2;
        pix[-xstride] = temp1;
        pix[0] = temp2;
    }
    pix += ystride;
}
}
