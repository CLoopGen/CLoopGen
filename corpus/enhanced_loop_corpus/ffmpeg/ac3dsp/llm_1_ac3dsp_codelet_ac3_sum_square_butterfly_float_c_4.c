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
if (len > 0) {
    for (i = 0; i < len; i += 2) {
        for (int j = 0; j < 2 && (i + j) < len; j++) {
            int idx = i + j;
            float lt = coef0[idx];
            float rt = coef1[idx];
            float md = lt + rt;
            float sd = lt - rt;
            sum[0] += lt * lt;
            sum[1] += rt * rt;
            sum[2] += md * md;
            sum[3] += sd * sd;
        }
    }
}
}
