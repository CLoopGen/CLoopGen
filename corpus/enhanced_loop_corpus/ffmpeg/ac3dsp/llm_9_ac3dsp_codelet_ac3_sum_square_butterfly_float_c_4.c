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
    sum[0] += lt * lt + rt * rt;
    sum[1] += md * md + sd * sd;
    sum[2] += lt * rt;
    sum[3] -= lt * rt;
}
}
