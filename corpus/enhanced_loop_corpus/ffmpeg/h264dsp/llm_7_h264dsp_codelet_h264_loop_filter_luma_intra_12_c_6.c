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
    uint16_t *base_pix = pix;
    const int p2 = base_pix[-3 * xstride];
    const int p1 = base_pix[-2 * xstride];
    const int p0 = base_pix[-1 * xstride];
    const int q0 = base_pix[0 * xstride];
    const int q1 = base_pix[1 * xstride];
    const int q2 = base_pix[2 * xstride];
    const int diff_p0_q0 = p0 - q0;
    const int abs_p0_q0 = diff_p0_q0 >= 0 ? diff_p0_q0 : -diff_p0_q0;

    if (abs_p0_q0 < alpha) {
        const int diff_p1_p0 = p1 - p0;
        const int abs_p1_p0 = diff_p1_p0 >= 0 ? diff_p1_p0 : -diff_p1_p0;
        const int diff_q1_q0 = q1 - q0;
        const int abs_q1_q0 = diff_q1_q0 >= 0 ? diff_q1_q0 : -diff_q1_q0;

        if (abs_p1_p0 < beta && abs_q1_q0 < beta) {
            const int threshold = (alpha >> 2) + 2;
            const int use_strong_filter = abs_p0_q0 < threshold;
            int updated_p0 = 0, updated_q0 = 0;

            if (use_strong_filter) {
                const int diff_p2_p0 = p2 - p0;
                const int abs_p2_p0 = diff_p2_p0 >= 0 ? diff_p2_p0 : -diff_p2_p0;
                const int diff_q2_q0 = q2 - q0;
                const int abs_q2_q0 = diff_q2_q0 >= 0 ? diff_q2_q0 : -diff_q2_q0;

                if (abs_p2_p0 < beta) {
                    const int p3 = base_pix[-4 * xstride];
                    updated_p0 = (p2 + 2 * p1 + 2 * p0 + 2 * q0 + q1 + 4) >> 3;
                    base_pix[-2 * xstride] = (p2 + p1 + p0 + q0 + 2) >> 2;
                    base_pix[-3 * xstride] = (2 * p3 + 3 * p2 + p1 + p0 + q0 + 4) >> 3;
                } else {
                    updated_p0 = (2 * p1 + p0 + q1 + 2) >> 2;
                }

                if (abs_q2_q0 < beta) {
                    const int q3 = base_pix[3 * xstride];
                    updated_q0 = (p1 + 2 * p0 + 2 * q0 + 2 * q1 + q2 + 4) >> 3;
                    base_pix[1 * xstride] = (p0 + q0 + q1 + q2 + 2) >> 2;
                    base_pix[2 * xstride] = (2 * q3 + 3 * q2 + q1 + q0 + p0 + 4) >> 3;
                } else {
                    updated_q0 = (2 * q1 + q0 + p1 + 2) >> 2;
                }

                base_pix[-1 * xstride] = updated_p0;
                base_pix[0 * xstride] = updated_q0;
            } else {
                updated_p0 = (2 * p1 + p0 + q1 + 2) >> 2;
                updated_q0 = (2 * q1 + q0 + p1 + 2) >> 2;
                base_pix[-1 * xstride] = updated_p0;
                base_pix[0 * xstride] = updated_q0;
            }
        }
    }
    pix += ystride;
}
}
