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
    const ptrdiff_t idx = d * ystride;
    const int p0 = pix[idx - xstride];
    const int p1 = pix[idx - 2 * xstride];
    const int q0 = pix[idx];
    const int q1 = pix[idx + xstride];
    if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < alpha && ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) < beta && ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) < beta) {
        pix[idx - xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
        pix[idx] = (2 * q1 + q0 + p1 + 2) >> 2;
    }
}
}
