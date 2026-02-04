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
const ptrdiff_t base_stride = ystride * 4 * inner_iters;
ptrdiff_t offset = -base_stride + ystride;
for (d = 0; d < 4 * inner_iters; d++) {
    offset += base_stride;
    const int p0 = *(pix + offset - xstride);
    const int p1 = *(pix + offset - 2 * xstride);
    const int q0 = *(pix + offset);
    const int q1 = *(pix + offset + xstride);
    const int dpq = (p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0));
    const int dpp = (p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0));
    const int dqq = (q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0));
    if (dpq < alpha && dpp < beta && dqq < beta) {
        *(pix + offset - xstride) = (2 * p1 + p0 + q1 + 2) >> 2;
        *(pix + offset) = (2 * q1 + q0 + p1 + 2) >> 2;
    }
}
}
