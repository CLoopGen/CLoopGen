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
    const int p2 = pix[-3 * xstride];
    const int p1 = pix[-2 * xstride];
    const int p0 = pix[-1 * xstride];
    const int q0 = pix[0 * xstride];
    const int q1 = pix[1 * xstride];
    const int q2 = pix[2 * xstride];
    const int diff_p0_q0 = (p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0));
    const int diff_p1_p0 = (p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0));
    const int diff_q1_q0 = (q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0));

    if (diff_p0_q0 < alpha && diff_p1_p0 < beta && diff_q1_q0 < beta) {
        const int limit = (alpha >> 2) + 2;
        if (diff_p0_q0 < limit) {
            const int p3 = pix[-4 * xstride];
            const int q3 = pix[3 * xstride];
            const int use_extended_p = ((p2 - p0) >= 0 ? (p2 - p0) : (-(p2 - p0))) < beta;
            const int use_extended_q = ((q2 - q0) >= 0 ? (q2 - q0) : (-(q2 - q0))) < beta;

            pix[-1 * xstride] = use_extended_p ? 
                (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3 :
                (2 * p1 + p0 + q1 + 2) >> 2;

            pix[-2 * xstride] = use_extended_p ? 
                (p2 + p1 + p0 + q0 + 2) >> 2 : pix[-2 * xstride];

            pix[-3 * xstride] = use_extended_p ? 
                (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3 : pix[-3 * xstride];

            pix[0 * xstride] = use_extended_q ? 
                (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3 :
                (2 * q1 + q0 + p1 + 2) >> 2;

            pix[1 * xstride] = use_extended_q ? 
                (p0 + q0 + q1 + q2 + 2) >> 2 : pix[1 * xstride];

            pix[2 * xstride] = use_extended_q ? 
                (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3 : pix[2 * xstride];
        } else {
            pix[-1 * xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
            pix[0 * xstride] = (2 * q1 + q0 + p1 + 2) >> 2;
        }
    }
    pix += ystride;
}
}
