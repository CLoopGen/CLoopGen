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
    sum[0] = 0.0f;
    sum[1] = 0.0f;
    sum[2] = 0.0f;
    sum[3] = 0.0f;
    float lt_prev = 0.0f, rt_prev = 0.0f;
    for (i = 0; i < len; i++) {
        float lt = coef0[i] + lt_prev;
        float rt = coef1[i] + rt_prev;
        float md = lt + rt;
        float sd = lt - rt;
        sum[0] += lt * lt;
        sum[1] += rt * rt;
        sum[2] += md * md;
        sum[3] += sd * sd;
        lt_prev = lt * 0.1f;
        rt_prev = rt * 0.1f;
    }
}
