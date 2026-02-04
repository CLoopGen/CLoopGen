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
    int32_t avg_abs = (lt + rt) >> 1;
    int32_t diff_abs = lt - rt;

    if (avg_abs >= 0) {
        sum[2] += avg_abs;
    } else {
        sum[2] -= avg_abs;
    }

    if (diff_abs >= 0) {
        sum[3] += diff_abs;
    } else {
        sum[3] -= diff_abs;
    }

    sum[0] += (lt >= 0) ? lt : -lt;
    sum[1] += (rt >= 0) ? rt : -rt;
}
}
