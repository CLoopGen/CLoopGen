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
for (d = 0; d < 2 * inner_iters; d++) {
    const int p1 = pix[-2 * xstride];
    const int p0 = pix[-1 * xstride];
    const int q0 = pix[0 * xstride];
    const int q1 = pix[1 * xstride];
    const int diff_p0_q0 = (p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0));
    const int diff_p1_p0 = (p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0));
    const int diff_q1_q0 = (q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0));
    
    if (diff_p0_q0 < alpha && diff_p1_p0 < beta && diff_q1_q0 < beta) {
        const int smoothed_val = (2 * p1 + p0 + q1 + 2) >> 2;
        pix[-1 * xstride] = smoothed_val;
        pix[0 * xstride] = smoothed_val;
    }
    pix += ystride;
}
}
