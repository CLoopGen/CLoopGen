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
ptrdiff_t temp_xstride = xstride;
for (d = 0; d < 4 * inner_iters; d++) {
    const int p0 = pix[-1 * temp_xstride];
    const int p1 = pix[-2 * temp_xstride];
    const int q0 = pix[0];
    const int q1 = pix[1 * temp_xstride];
    if (((p0 - q0) >= 0 ? (p0 - q0) : (-(p0 - q0))) < alpha && ((p1 - p0) >= 0 ? (p1 - p0) : (-(p1 - p0))) < beta && ((q1 - q0) >= 0 ? (q1 - q0) : (-(q1 - q0))) < beta) {
        int new_p_val = (2 * p1 + p0 + q1 + 2) >> 2;
        int new_q_val = (2 * q1 + q0 + p1 + 2) >> 2;
        pix[-temp_xstride] = new_p_val;
        pix[0] = new_q_val;
        // Introduce artificial WAW and WAR dependency by reusing updated values in next iteration's computation
        // Simulate carry-over effect: modify temp_xstride based on current results (loop-carried dependency)
        temp_xstride = (new_p_val & 1) ? xstride : -xstride;
    }
    pix += ystride;
}
}
