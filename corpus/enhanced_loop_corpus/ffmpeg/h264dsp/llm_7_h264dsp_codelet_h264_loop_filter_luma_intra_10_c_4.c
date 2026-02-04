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
    const ptrdiff_t base_offset = d * ystride;
    const int idx_p2 = base_offset - 3 * xstride;
    const int idx_p1 = base_offset - 2 * xstride;
    const int idx_p0 = base_offset - 1 * xstride;
    const int idx_q0 = base_offset + 0 * xstride;
    const int idx_q1 = base_offset + 1 * xstride;
    const int idx_q2 = base_offset + 2 * xstride;

    const int val_p2 = pix[idx_p2];
    const int val_p1 = pix[idx_p1];
    const int val_p0 = pix[idx_p0];
    const int val_q0 = pix[idx_q0];
    const int val_q1 = pix[idx_q1];
    const int val_q2 = pix[idx_q2];

    const int diff_p0_q0 = val_p0 - val_q0;
    const int abs_diff_p0_q0 = diff_p0_q0 >= 0 ? diff_p0_q0 : -diff_p0_q0;

    const int diff_p1_p0 = val_p1 - val_p0;
    const int abs_diff_p1_p0 = diff_p1_p0 >= 0 ? diff_p1_p0 : -diff_p1_p0;

    const int diff_q1_q0 = val_q1 - val_q0;
    const int abs_diff_q1_q0 = diff_q1_q0 >= 0 ? diff_q1_q0 : -diff_q1_q0;

    if (abs_diff_p0_q0 < alpha && abs_diff_p1_p0 < beta && abs_diff_q1_q0 < beta) {
        const int threshold = (alpha >> 2) + 2;
        if (abs_diff_p0_q0 < threshold) {
            const int diff_p2_p0 = val_p2 - val_p0;
            const int abs_diff_p2_p0 = diff_p2_p0 >= 0 ? diff_p2_p0 : -diff_p2_p0;

            int updated_p0_val = (2 * val_p1 + val_p0 + val_q1 + 2) >> 2;
            int updated_q0_val = (2 * val_q1 + val_q0 + val_p1 + 2) >> 2;

            if (abs_diff_p2_p0 < beta) {
                const int val_p3 = pix[base_offset - 4 * xstride];
                updated_p0_val = (val_p2 + 2 * val_p1 + 2 * val_p0 + 2 * val_q0 + val_q1 + 4) >> 3;
                pix[idx_p0] = updated_p0_val;
                pix[idx_p1] = (val_p2 + val_p1 + val_p0 + val_q0 + 2) >> 2;
                pix[idx_p2] = (2 * val_p3 + 3 * val_p2 + val_p1 + val_p0 + val_q0 + 4) >> 3;
            } else {
                pix[idx_p0] = updated_p0_val;
            }

            const int diff_q2_q0 = val_q2 - val_q0;
            const int abs_diff_q2_q0 = diff_q2_q0 >= 0 ? diff_q2_q0 : -diff_q2_q0;

            if (abs_diff_q2_q0 < beta) {
                const int val_q3 = pix[base_offset + 3 * xstride];
                updated_q0_val = (val_p1 + 2 * val_p0 + 2 * val_q0 + 2 * val_q1 + val_q2 + 4) >> 3;
                pix[idx_q0] = updated_q0_val;
                pix[idx_q1] = (val_p0 + val_q0 + val_q1 + val_q2 + 2) >> 2;
                pix[idx_q2] = (2 * val_q3 + 3 * val_q2 + val_q1 + val_q0 + val_p0 + 4) >> 3;
            } else {
                pix[idx_q0] = updated_q0_val;
            }
        } else {
            pix[idx_p0] = (2 * val_p1 + val_p0 + val_q1 + 2) >> 2;
            pix[idx_q0] = (2 * val_q1 + val_q0 + val_p1 + 2) >> 2;
        }
    }
}
}
