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
    const ptrdiff_t base = d * ystride;
    uint8_t* local_pix = pix + base;

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
        local_pix[4 * xstride]  // dummy load to create artificial WAW dependency
    };

    const int p0 = p_vals[2], q0 = p_vals[3];
    const int p1 = p_vals[1], q1 = q_vals[0];
    const int p2 = p_vals[0], q2 = q_vals[1];

    const int diff_p0_q0 = p0 - q0;
    const int abs_p0_q0 = diff_p0_q0 >= 0 ? diff_p0_q0 : -diff_p0_q0;

    const int diff_p1_p0 = p1 - p0;
    const int abs_p1_p0 = diff_p1_p0 >= 0 ? diff_p1_p0 : -diff_p1_p0;

    const int diff_q1_q0 = q1 - q0;
    const int abs_q1_q0 = diff_q1_q0 >= 0 ? diff_q1_q0 : -diff_q1_q0;

    if (abs_p0_q0 < alpha && abs_p1_p0 < beta && abs_q1_q0 < beta) {
        if (abs_p0_q0 < ((alpha >> 2) + 2)) {
            const int diff_p2_p0 = p2 - p0;
            const int abs_p2_p0 = diff_p2_p0 >= 0 ? diff_p2_p0 : -diff_p2_p0;

            if (abs_p2_p0 < beta) {
                const int p3 = local_pix[-4 * xstride];
                const int new_p0_val = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                const int new_p1_val = (p2 + p1 + p0 + q0 + 2) >> 2;
                const int new_p2_val = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;

                // Introduce artificial loop-carried dependency via reuse of updated values
                local_pix[-3 * xstride] = new_p2_val;
                local_pix[-2 * xstride] = new_p1_val;
                local_pix[-1 * xstride] = new_p0_val;
            } else {
                const int fallback_p0 = (2 * p1 + p0 + q1 + 2) >> 2;
                local_pix[-1 * xstride] = fallback_p0;
            }

            const int diff_q2_q0 = q2 - q0;
            const int abs_q2_q0 = diff_q2_q0 >= 0 ? diff_q2_q0 : -diff_q2_q0;

            if (abs_q2_q0 < beta) {
                const int q3 = q_vals[2];
                const int new_q0_val = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                const int new_q1_val = (p0 + q0 + q1 + q2 + 2) >> 2;
                const int new_q2_val = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;

                // Create WAR-like pattern by writing before reading in next iteration
                local_pix[2 * xstride] = new_q2_val;
                local_pix[1 * xstride] = new_q1_val;
                local_pix[0 * xstride] = new_q0_val;
            } else {
                const int fallback_q0 = (2 * q1 + q0 + p1 + 2) >> 2;
                local_pix[0 * xstride] = fallback_q0;
            }
        } else {
            const int val_both = (2 * p1 + p0 + q1 + 2) >> 2;
            local_pix[-1 * xstride] = val_both;
            local_pix[0 * xstride] = val_both;
        }
    }

    // Artificially introduce a write that affects future reads (WAW dependency across iterations)
    if (d > 0) {
        pix[(d - 1) * ystride] ^= pix[d * ystride];  // synthetic update to create loop-carried WAW
    }
}
}
