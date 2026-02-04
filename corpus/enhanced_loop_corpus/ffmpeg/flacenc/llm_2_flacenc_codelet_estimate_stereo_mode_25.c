#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int32_t *left_ch;
extern  int32_t *right_ch;
extern int n;
extern int i;
extern int32_t lt;
extern int32_t rt;
extern uint64_t sum[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 2; i < n; i += 2) {
    if (i + 1 >= n) break;
    lt = left_ch[i] - 2 * left_ch[i - 1] + left_ch[i - 2];
    rt = right_ch[i] - 2 * right_ch[i - 1] + right_ch[i - 2];
    sum[2] += (((lt + rt) >> 1) >= 0 ? ((lt + rt) >> 1) : (-((lt + rt) >> 1)));
    sum[3] += ((lt - rt) >= 0 ? (lt - rt) : (-(lt - rt)));
    sum[0] += ((lt) >= 0 ? (lt) : (-(lt)));
    sum[1] += ((rt) >= 0 ? (rt) : (-(rt)));

    lt = left_ch[i+1] - 2 * left_ch[i] + left_ch[i-1];
    rt = right_ch[i+1] - 2 * right_ch[i] + right_ch[i-1];
    sum[2] += (((lt + rt) >> 1) >= 0 ? ((lt + rt) >> 1) : (-((lt + rt) >> 1)));
    sum[3] += ((lt - rt) >= 0 ? (lt - rt) : (-(lt - rt)));
    sum[0] += ((lt) >= 0 ? (lt) : (-(lt)));
    sum[1] += ((rt) >= 0 ? (rt) : (-(rt)));
}
}
