#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int64_t sum[4];
extern  int32_t *coef0;
extern  int32_t *coef1;
extern int len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp_sum0 = 0, temp_sum1 = 0, temp_sum2 = 0, temp_sum3 = 0;
    for (i = 0; i < len; i++) {
        int lt = coef0[i];
        int rt = coef1[i];
        int md = lt + rt;
        int sd = lt - rt;
        temp_sum0 += (int64_t)lt * lt;
        temp_sum1 += (int64_t)rt * rt;
        temp_sum2 += (int64_t)md * md;
        temp_sum3 += (int64_t)sd * sd;
    }
    sum[0] += temp_sum0;
    sum[1] += temp_sum1;
    sum[2] += temp_sum2;
    sum[3] += temp_sum3;
}
