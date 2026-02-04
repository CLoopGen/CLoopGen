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
    const ptrdiff_t base_offset = d * ystride;
    uint8_t* local_pix = pix + base_offset;

    const int p_vals[4] = {
        local_pix[-3 * xstride],
        local_pix[-2 * xstride],
        local_pix[-1 * xstride],
        local_pix[0 * xstride]
    };
    const int q_vals[4] = {
        local_pix[1 * xstride],
        local_pix[2 * xstride],
        local_pix[3 * xstride],
        local_pix[4 * xstride]
    };

    const int p0 = p_vals[2], q0 = p_vals[3];
    const int p1 = p_vals[1], q1 = q_vals[0];
    const int p2 = p_vals[0], q2 = q_vals[1];

    const int diff_p0_q0 = p0 - q0;
    const int abs_p0_q0 = diff_p0_q0 >= 0 ? diff_p0_q0 : -diff_p0_q0;
    const int abs_p1_p0 = (p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0));
    const int abs_q1_q0 = (q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0));

    if (abs_p0_q0 < alpha && abs_p1_p0 < beta && abs_q1_q0 < beta) {
        const int threshold = (alpha >> 2) + 2;
        if (abs_p0_q0 < threshold) {
            const int abs_p2_p0 = (p2 - p0) >= 0 ? (p2 - p0) : (-(p2 - p0));
            const int abs_q2_q0 = (q2 - q0) >= 0 ? (q2 - q0) : (-(q2 - q0));

            int update_left = 0, update_right = 0;
            int new_left[3], new_right[3];

            if (abs_p2_p0 < beta) {
                const int p3 = local_pix[-4 * xstride];
                new_left[0] = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                new_left[1] = (p2 + p1 + p0 + q0 + 2) >> 2;
                new_left[2] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
                update_left = 1;
            } else {
                new_left[0] = (2 * p1 + p0 + q1 + 2) >> 2;
            }

            if (abs_q2_q0 < beta) {
                const int q3 = q_vals[2];
                new_right[0] = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                new_right[1] = (p0 + q0 + q1 + q2 + 2) >> 2;
                new_right[2] = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
                update_right = 1;
            } else {
                new_right[0] = (2 * q1 + q0 + p1 + 2) >> 2;
            }

            if (update_left) {
                local_pix[-1 * xstride] = new_left[0];
                local_pix[-2 * xstride] = new_left[1];
                local_pix[-3 * xstride] = new_left[2];
            } else {
                local_pix[-1 * xstride] = new_left[0];
            }

            if (update_right) {
                local_pix[0 * xstride] = new_right[0];
                local_pix[1 * xstride] = new_right[1];
                local_pix[2 * xstride] = new_right[2];
            } else {
                local_pix[0 * xstride] = new_right[0];
            }
        } else {
            local_pix[-1 * xstride] = (2 * p1 + p0 + q1 + 2) >> 2;
            local_pix[0 * xstride] = (2 * q1 + q0 + p1 + 2) >> 2;
        }
    }
}
}
