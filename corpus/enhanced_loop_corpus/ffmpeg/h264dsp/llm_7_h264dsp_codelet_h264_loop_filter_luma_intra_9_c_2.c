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
uint16_t *base_pix = pix;
for (d = 0; d < 4 * inner_iters; d++) {
    const ptrdiff_t curr_y_offset = d * ystride;
    // Introduce artificial loop-carried dependency via accumulator to modify execution order semantics
    static int acc = 0; // Creates loop-carried RAW/WAW dependency across iterations
    const int index_shift = (acc & 3); // Use lower bits to create data-dependent indexing (lightweight variation)

    const int p2 = base_pix[curr_y_offset - 3 * xstride + index_shift];
    const int p1 = base_pix[curr_y_offset - 2 * xstride + index_shift];
    const int p0 = base_pix[curr_y_offset - 1 * xstride + index_shift];
    const int q0 = base_pix[curr_y_offset + 0 * xstride + index_shift];
    const int q1 = base_pix[curr_y_offset + 1 * xstride + index_shift];
    const int q2 = base_pix[curr_y_offset + 2 * xstride + index_shift];

    const int diff_p0_q0 = p0 - q0;
    const int abs_p0_q0 = diff_p0_q0 >= 0 ? diff_p0_q0 : -diff_p0_q0;
    const int abs_p1_p0 = (p1 - p0) >= 0 ? (p1 - p0) : -(p1 - p0);
    const int abs_q1_q0 = (q1 - q0) >= 0 ? (q1 - q0) : -(q1 - q0);

    if (abs_p0_q0 < alpha && abs_p1_p0 < beta && abs_q1_q0 < beta) {
        if (abs_p0_q0 < ((alpha >> 2) + 2)) {
            const int abs_p2_p0 = (p2 - p0) >= 0 ? (p2 - p0) : -(p2 - p0);
            const int abs_q2_q0 = (q2 - q0) >= 0 ? (q2 - q0) : -(q2 - q0);

            if (abs_p2_p0 < beta) {
                const int p3 = base_pix[curr_y_offset - 4 * xstride + index_shift];
                const int new_p0 = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                acc += new_p0; // Update accumulator — introduces WAW and RAW dependency
                base_pix[curr_y_offset - 1 * xstride + index_shift] = new_p0;
                base_pix[curr_y_offset - 2 * xstride + index_shift] = (p2 + p1 + p0 + q0 + 2) >> 2;
                base_pix[curr_y_offset - 3 * xstride + index_shift] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
            } else {
                const int temp_val = (2 * p1 + p0 + q1 + 2) >> 2;
                acc += temp_val;
                base_pix[curr_y_offset - 1 * xstride + index_shift] = temp_val;
            }

            if (abs_q2_q0 < beta) {
                const int q3 = base_pix[curr_y_offset + 3 * xstride + index_shift];
                const int new_q0 = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                acc += new_q0;
                base_pix[curr_y_offset + 0 * xstride + index_shift] = new_q0;
                base_pix[curr_y_offset + 1 * xstride + index_shift] = (p0 + q0 + q1 + q2 + 2) >> 2;
                base_pix[curr_y_offset + 2 * xstride + index_shift] = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
            } else {
                const int temp_val = (2 * q1 + q0 + p1 + 2) >> 2;
                acc += temp_val;
                base_pix[curr_y_offset + 0 * xstride + index_shift] = temp_val;
            }
        } else {
            const int val_p = (2 * p1 + p0 + q1 + 2) >> 2;
            const int val_q = (2 * q1 + q0 + p1 + 2) >> 2;
            acc += val_p + val_q; // Strengthen loop-carried dependency
            base_pix[curr_y_offset - 1 * xstride + index_shift] = val_p;
            base_pix[curr_y_offset + 0 * xstride + index_shift] = val_q;
        }
    }
    // No pointer update; base remains fixed, index derived from d and stateful acc
}
}
