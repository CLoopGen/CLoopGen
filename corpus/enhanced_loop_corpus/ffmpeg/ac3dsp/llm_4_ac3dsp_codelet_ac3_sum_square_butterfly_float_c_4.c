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
        if (lt > 0.0f) {
            sum[0] += lt * lt;
            sum[2] += md * md;
        }
        if (rt >= 0.0f) {
            sum[1] += rt * rt;
        }
        if (sd > -1.0f && sd < 1.0f) {
            sum[3] += sd * sd;
        }
    }
}
