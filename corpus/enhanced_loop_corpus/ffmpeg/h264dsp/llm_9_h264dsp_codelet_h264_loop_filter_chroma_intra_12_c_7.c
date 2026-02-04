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
for (d = 0; d < 8 * inner_iters; d += 2) {
    const int p0_a = pix[-1 * xstride];
    const int p1_a = pix[-2 * xstride];
    const int q0_a = pix[0];
    const int q1_a = pix[1 * xstride];
    const int p0_b = pix[ystride - xstride];
    const int p1_b = pix[ystride - 2 * xstride];
    const int q0_b = pix[ystride];
    const int q1_b = pix[ystride + xstride];
    const int dp0q0_a = (p0_a > q0_a) ? p0_a - q0_a : q0_a - p0_a;
    const int dp1p0_a = (p1_a > p0_a) ? p1_a - p0_a : p0_a - p1_a;
    const int dq1q0_a = (q1_a > q0_a) ? q1_a - q0_a : q0_a - q1_a;
    const int dp0q0_b = (p0_b > q0_b) ? p0_b - q0_b : q0_b - p0_b;
    const int dp1p0_b = (p1_b > p0_b) ? p1_b - p0_b : p0_b - p1_b;
    const int dq1q0_b = (q1_b > q0_b) ? q1_b - q0_b : q0_b - q1_b;
    if (dp0q0_a < alpha && dp1p0_a < beta && dq1q0_a < beta) {
        pix[-xstride] = (2 * p1_a + p0_a + q1_a + 2) / 4;
        pix[0] = (2 * q1_a + q0_a + p1_a + 2) / 4;
    }
    if (dp0q0_b < alpha && dp1p0_b < beta && dq1q0_b < beta) {
        pix[ystride - xstride] = (2 * p1_b + p0_b + q1_b + 2) / 4;
        pix[ystride] = (2 * q1_b + q0_b + p1_b + 2) / 4;
    }
    pix += 2 * ystride;
}
}
