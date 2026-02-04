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
    // Variant 1: Strided memory access with stride of 2
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            // Process two elements at once with stride-2 access
            float lt0 = coef0[i];
            float rt0 = coef1[i];
            float md0 = lt0 + rt0;
            float sd0 = lt0 - rt0;

            float lt1 = coef0[i + 1];
            float rt1 = coef1[i + 1];
            float md1 = lt1 + rt1;
            float sd1 = lt1 - rt1;

            sum[0] += lt0 * lt0 + lt1 * lt1;
            sum[1] += rt0 * rt0 + rt1 * rt1;
            sum[2] += md0 * md0 + md1 * md1;
            sum[3] += sd0 * sd0 + sd1 * sd1;
        } else {
            // Handle odd-length tail
            float lt = coef0[i];
            float rt = coef1[i];
            float md = lt + rt;
            float sd = lt - rt;
            sum[0] += lt * lt;
            sum[1] += rt * rt;
            sum[2] += md * md;
            sum[3] += sd * sd;
        }
    }
}
