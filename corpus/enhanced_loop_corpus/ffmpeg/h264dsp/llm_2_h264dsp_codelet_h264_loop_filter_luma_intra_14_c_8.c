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



void loop() {
    // Variant 1: Consecutive Memory Access with Local Buffering
    // Instead of accessing `pix` with large strides repeatedly, we prefetch a block of data into a local array
    // to promote spatial locality and reduce redundant memory accesses.
    
    uint16_t window[7];  // Local buffer to hold values from -3*xstride to +3*xstride

    for (d = 0; d < 4 * inner_iters; d++) {
        // Load the neighborhood once using strided access, then use consecutive local access
        window[0] = pix[-3 * xstride];
        window[1] = pix[-2 * xstride];
        window[2] = pix[-1 * xstride];
        window[3] = pix[0 * xstride];
        window[4] = pix[1 * xstride];
        window[5] = pix[2 * xstride];
        window[6] = pix[3 * xstride];

        const int p2 = window[0];
        const int p1 = window[1];
        const int p0 = window[2];
        const int q0 = window[3];
        const int q1 = window[4];
        const int q2 = window[5];

        if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < alpha && 
            ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) < beta && 
            ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) < beta) {

            if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < ((alpha >> 2) + 2)) {
                if (((p2 - p0) >= 0 ? (p2 - p0) : (-(p2 - p0))) < beta) {
                    const int p3 = window[0]; // Already loaded as window[0]
                    pix[-1 * xstride] = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                    pix[-2 * xstride] = (p2 + p1 + p0 + q0 + 2) >> 2;
                    pix[-3 * xstride] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
                } else {
                    pix[-1 * xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
                }
                if (((q2 - q0) >= 0 ? (q2 - q0) : (-(q2 - q0))) < beta) {
                    const int q3 = window[6];
                    pix[0 * xstride] = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                    pix[1 * xstride] = (p0 + q0 + q1 + q2 + 2) >> 2;
                    pix[2 * xstride] = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
                } else {
                    pix[0 * xstride] = (2 * q1 + q0 + p1 + 2) >> 2;
                }
            } else {
                pix[-1 * xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
                pix[0 * xstride] = (2 * q1 + q0 + p1 + 2) >> 2;
            }
        }
        pix += ystride;
    }
}
