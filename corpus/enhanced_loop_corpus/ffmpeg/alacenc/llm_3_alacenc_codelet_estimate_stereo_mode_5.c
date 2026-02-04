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
int32_t *left_ptr = left_ch + 2;
int32_t *right_ptr = right_ch + 2;
for (i = 2; i < n; i++) {
    lt = left_ptr[0] - 2 * left_ptr[-1] + left_ptr[-2];
    rt = right_ptr[0] - 2 * right_ptr[-1] + right_ptr[-2];
    sum[2] += (((lt + rt) >> 1) >= 0 ? ((lt + rt) >> 1) : (-((lt + rt) >> 1)));
    sum[3] += ((lt - rt) >= 0 ? (lt - rt) : (-(lt - rt)));
    sum[0] += ((lt) >= 0 ? (lt) : (-(lt)));
    sum[1] += ((rt) >= 0 ? (rt) : (-(rt)));
    left_ptr++;
    right_ptr++;
}
}
