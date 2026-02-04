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

    // Introduce early skip based on a new control condition: skip near-zero activity
    if (lt > -10 && lt < 10 && rt > -10 && rt < 10) {
        continue;
    }

    uint64_t temp_sum = (uint64_t)abs((int)(lt + rt) >> 1);
    sum[2] += temp_sum;

    sum[3] += (uint64_t)abs((int)(lt - rt));
    sum[0] += (uint64_t)abs((int)lt);
    sum[1] += (uint64_t)abs((int)rt);
}
}
