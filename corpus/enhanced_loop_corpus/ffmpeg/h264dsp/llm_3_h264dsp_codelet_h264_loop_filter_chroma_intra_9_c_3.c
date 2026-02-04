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
ptrdiff_t offset = 0;
for (d = 0; d < 4 * inner_iters; d++) {
    const int p0 = *(pix + offset - xstride);
    const int p1 = *(pix + offset - 2 * xstride);
    const int q0 = *(pix + offset);
    const int q1 = *(pix + offset + xstride);
    int diff_p0_q0 = p0 - q0;
    int diff_p1_p0 = p1 - p0;
    int diff_q1_q0 = q1 - q0;
    if ((diff_p0_q0 < 0 ? -diff_p0_q0 : diff_p0_q0) < alpha &&
        (diff_p1_p0 < 0 ? -diff_p1_p0 : diff_p1_p0) < beta &&
        (diff_q1_q0 < 0 ? -diff_q1_q0 : diff_q1_q0) < beta) {
        *(pix + offset - xstride) = (2 * p1 + p0 + q1 + 2) >> 2;
        *(pix + offset) = (2 * q1 + q0 + p1 + 2) >> 2;
    }
    offset += ystride;
}
}
