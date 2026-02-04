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
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of using strided access along xstride, reorganize data access to use consecutive indices
    // Assume that the pixel data has been transposed or rearranged so that the required elements are now in contiguous memory.
    // We replace xstride with a fixed offset of 1 and adjust indexing accordingly.

    uint8_t *base_ptr;
    for (d = 0; d < 4 * inner_iters; d++) {
        base_ptr = pix;
        const int p2 = base_ptr[-3];
        const int p1 = base_ptr[-2];
        const int p0 = base_ptr[-1];
        const int q0 = base_ptr[0];
        const int q1 = base_ptr[1];
        const int q2 = base_ptr[2];

        if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < alpha && 
            ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) < beta && 
            ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) < beta) {

            if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < ((alpha >> 2) + 2)) {
                if (((p2 - p0) >= 0 ? (p2 - p0) : (-(p2 - p0))) < beta) {
                    const int p3 = base_ptr[-4];
                    base_ptr[-1] = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                    base_ptr[-2] = (p2 + p1 + p0 + q0 + 2) >> 2;
                    base_ptr[-3] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
                } else {
                    base_ptr[-1] = (2 * p1 + p0 + q1 + 2) >> 2;
                }
                if (((q2 - q0) >= 0 ? (q2 - q0) : (-(q2 - q0))) < beta) {
                    const int q3 = base_ptr[3];
                    base_ptr[0] = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                    base_ptr[1] = (p0 + q0 + q1 + q2 + 2) >> 2;
                    base_ptr[2] = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
                } else {
                    base_ptr[0] = (2 * q1 + q0 + p1 + 2) >> 2;
                }
            } else {
                base_ptr[-1] = (2 * p1 + p0 + q1 + 2) >> 2;
                base_ptr[0] = (2 * q1 + q0 + p1 + 2) >> 2;
            }
        }
        pix += ystride;
    }
}
