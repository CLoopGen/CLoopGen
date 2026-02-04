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
    // Variant 2: Strided Access via Pointer Arithmetic Unrolling
    // Transform the loop into a strided pattern by unrolling and using pointer arithmetic
    // directly on a moving pointer, simulating a more regular stride traversal.
    // Also replace conditional expressions with direct absolute difference computation.

    uint16_t* current_pix = pix;
    for (d = 0; d < 4 * inner_iters; d++) {
        // Load pixel values using direct pointer arithmetic
        const int p2 = *(current_pix - 3);
        const int p1 = *(current_pix - 2);
        const int p0 = *(current_pix - 1);
        const int q0 = *(current_pix);
        const int q1 = *(current_pix + 1);
        const int q2 = *(current_pix + 2);

        // Compute absolute differences without ternary operator
        int dp0q0 = abs(p0 - q0);
        int dp1p0 = abs(p1 - p0);
        int dq1q0 = abs(q1 - q0);

        if (dp0q0 < alpha && dp1p0 < beta && dq1q0 < beta) {
            if (dp0q0 < ((alpha >> 2) + 2)) {
                if (abs(p2 - p0) < beta) {
                    const int p3 = *(current_pix - 4);
                    *(current_pix - 1) = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                    *(current_pix - 2) = (p2 + p1 + p0 + q0 + 2) >> 2;
                    *(current_pix - 3) = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
                } else {
                    *(current_pix - 1) = (2 * p1 + p0 + q1 + 2) >> 2;
                }

                if (abs(q2 - q0) < beta) {
                    const int q3 = *(current_pix + 3);
                    *(current_pix + 0) = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                    *(current_pix + 1) = (p0 + q0 + q1 + q2 + 2) >> 2;
                    *(current_pix + 2) = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
                } else {
                    *(current_pix + 0) = (2 * q1 + q0 + p1 + 2) >> 2;
                }
            } else {
                *(current_pix - 1) = (2 * p1 + p0 + q1 + 2) >> 2;
                *(current_pix + 0) = (2 * q1 + q0 + p1 + 2) >> 2;
            }
        }
        // Advance pointer in 2D grid using ystride as byte-like offset
        current_pix += ystride;
    }
    // Update global pix pointer if side effects are expected
    pix = current_pix - (4 * inner_iters) * ystride;
}
