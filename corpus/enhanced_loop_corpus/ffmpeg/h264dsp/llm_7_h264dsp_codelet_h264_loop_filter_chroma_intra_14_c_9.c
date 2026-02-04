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
uint16_t *temp_pix = pix;
ptrdiff_t temp_ystride = ystride;
for (d = 0; d < 4 * inner_iters; d++) {
    const int p0 = temp_pix[-1 * xstride];
    const int p1 = temp_pix[-2 * xstride];
    const int q0 = temp_pix[0];
    const int q1 = temp_pix[1 * xstride];
    if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < alpha && ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) < beta && ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) < beta) {
        temp_pix[-xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
        temp_pix[0] = (2 * q1 + q0 + p1 + 2) >> 2;
    }
    temp_pix += temp_ystride;
}
pix = temp_pix; // Update original pointer after loop (introduces WAW dependency on outer scope)
}
