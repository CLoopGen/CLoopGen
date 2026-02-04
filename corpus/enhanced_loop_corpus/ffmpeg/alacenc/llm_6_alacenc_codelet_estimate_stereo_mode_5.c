#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *left_ch;
extern int32_t *right_ch;
extern int n;
extern int i;
extern int32_t lt;
extern int32_t rt;
extern uint64_t sum[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < n; i++) {
    lt = left_ch[i] - 2 * left_ch[i - 1] + left_ch[i - 2];
    rt = right_ch[i] - 2 * right_ch[i - 1] + right_ch[i - 2];
    int32_t lt_abs = (lt >= 0) ? lt : -lt;
    int32_t rt_abs = (rt >= 0) ? rt : -rt;
    int32_t sum_lr_avg_abs = (((lt + rt) >> 1) >= 0 ? ((lt + rt) >> 1) : (-((lt + rt) >> 1)));
    int32_t sum_lr_diff_abs = ((lt - rt) >= 0 ? (lt - rt) : (-(lt - rt)));
    sum[2] += sum_lr_avg_abs;
    sum[3] += sum_lr_diff_abs;
    sum[0] += lt_abs;
    sum[1] += rt_abs;
}
}
