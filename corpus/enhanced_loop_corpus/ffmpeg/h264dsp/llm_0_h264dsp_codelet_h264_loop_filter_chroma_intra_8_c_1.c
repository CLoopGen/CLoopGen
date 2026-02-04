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
    for (int sub_d = 0; sub_d < 1; sub_d++) { // Introduce trivial nested loop with depth increased by 1
        const int p0 = pix[-1 * xstride];
        const int p1 = pix[-2 * xstride];
        const int q0 = pix[0];
        const int q1 = pix[1 * xstride];
        if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < alpha && ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) < beta && ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) < beta) {
            pix[-xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
            pix[0] = (2 * q1 + q0 + p1 + 2) >> 2;
        }
        pix += ystride;
    }
}
}
