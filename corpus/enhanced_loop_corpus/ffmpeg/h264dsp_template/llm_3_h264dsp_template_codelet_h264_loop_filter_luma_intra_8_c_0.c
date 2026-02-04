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
    // Variant 2: Indirect Memory Access Pattern
    // Replace direct pointer arithmetic with an index array that defines non-uniform offsets.
    // This simulates access via an indirect addressing table, which could model sparse or reordered data layouts.

    const ptrdiff_t offsets[] = {-3*xstride, -2*xstride, -xstride, 0, xstride, 2*xstride, 3*xstride};
    ptrdiff_t idx_p2 = 0, idx_p1 = 1, idx_p0 = 2, idx_q0 = 3, idx_q1 = 4, idx_q2 = 5, idx_q3 = 6;
    ptrdiff_t idx_p3 = 0; // will be set conditionally

    for (d = 0; d < 4 * inner_iters; d++) {
        const int p2 = pix[offsets[idx_p2]];
        const int p1 = pix[offsets[idx_p1]];
        const int p0 = pix[offsets[idx_p0]];
        const int q0 = pix[offsets[idx_q0]];
        const int q1 = pix[offsets[idx_q1]];
        const int q2 = pix[offsets[idx_q2]];

        if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < alpha && 
            ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) < beta && 
            ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) < beta) {

            if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < ((alpha >> 2) + 2)) {
                if (((p2 - p0) >= 0 ? (p2 - p0) : (-(p2 - p0))) < beta) {
                    idx_p3 = 0; // corresponds to -4*xstride -> we need to compute offset manually
                    const int p3 = pix[offsets[idx_p2] - xstride]; // -4*xstride
                    pix[offsets[idx_p0]] = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                    pix[offsets[idx_p1]] = (p2 + p1 + p0 + q0 + 2) >> 2;
                    pix[offsets[idx_p2]] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
                } else {
                    pix[offsets[idx_p0]] = (2 * p1 + p0 + q1 + 2) >> 2;
                }
                if (((q2 - q0) >= 0 ? (q2 - q0) : (-(q2 - q0))) < beta) {
                    const int q3 = pix[offsets[idx_q2] + xstride]; // 3*xstride
                    pix[offsets[idx_q0]] = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                    pix[offsets[idx_q1]] = (p0 + q0 + q1 + q2 + 2) >> 2;
                    pix[offsets[idx_q2]] = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
                } else {
                    pix[offsets[idx_q0]] = (2 * q1 + q0 + p1 + 2) >> 2;
                }
            } else {
                pix[offsets[idx_p0]] = (2 * p1 + p0 + q1 + 2) >> 2;
                pix[offsets[idx_q0]] = (2 * q1 + q0 + p1 + 2) >> 2;
            }
        }
        pix += ystride;
    }
}
