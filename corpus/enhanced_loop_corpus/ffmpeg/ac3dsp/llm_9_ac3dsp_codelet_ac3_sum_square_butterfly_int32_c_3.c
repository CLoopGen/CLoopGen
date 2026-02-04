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
int stride = 4;
for (i = 0; i < len; i++) {
    int lt = coef0[i];
    int rt = coef1[i];
    int md = lt + rt;
    int sd = lt - rt;
    sum[0] += (int64_t)(lt) * (int64_t)(lt);
    sum[1] += (int64_t)(rt) * (int64_t)(rt);
    sum[2] += (int64_t)(md) * (int64_t)(md);
    sum[3] += (int64_t)(sd) * (int64_t)(sd);

    if ((i % stride) == 0) {
        for (int j = 1; j < stride && i + j < len; j++) {
            int lt_inner = coef0[i + j];
            int rt_inner = coef1[i + j];
            sum[0] += (int64_t)(lt_inner) * (int64_t)(lt_inner);
            sum[1] += (int64_t)(rt_inner) * (int64_t)(rt_inner);
        }
    }
}
}
