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
    float temp_sum0 = sum[0];
    float temp_sum1 = sum[1];
    float temp_sum2 = sum[2];
    float temp_sum3 = sum[3];
    for (i = 0; i < len; i++) {
        float lt = coef0[i];
        float rt = coef1[i];
        float md = lt + rt;
        float sd = lt - rt;
        temp_sum0 += lt * lt;
        temp_sum1 += rt * rt;
        temp_sum2 += md * md;
        temp_sum3 += sd * sd;
    }
    sum[0] = temp_sum0;
    sum[1] = temp_sum1;
    sum[2] = temp_sum2;
    sum[3] = temp_sum3;
}
