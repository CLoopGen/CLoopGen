#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float sum[4];
extern  float *coef0;
extern  float *coef1;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        float lt = coef0[i];
        float rt = coef1[i];
        float md = lt + rt;
        float sd = lt - rt;

        // Unconditionally compute squares
        float lt_sq = lt * lt;
        float rt_sq = rt * rt;
        float md_sq = md * md;
        float sd_sq = sd * sd;

        // Control dependency: only accumulate if magnitude is within range
        if (lt_sq <= 1e6f) {
            sum[0] += lt_sq;
        }
        if (rt_sq <= 1e6f) {
            sum[1] += rt_sq;
        }
        if (md_sq <= 1e6f) {
            sum[2] += md_sq;
        }
        if (sd_sq <= 1e6f) {
            sum[3] += sd_sq;
        }
    }
}
