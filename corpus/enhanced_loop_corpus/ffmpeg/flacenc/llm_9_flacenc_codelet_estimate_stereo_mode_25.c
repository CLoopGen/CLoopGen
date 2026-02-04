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
for (i = 3; i < n; i++) {
    int32_t lt1 = left_ch[i] - 2 * left_ch[i - 1] + left_ch[i - 2];
    int32_t rt1 = right_ch[i] - 2 * right_ch[i - 1] + right_ch[i - 2];
    int32_t lt2 = left_ch[i-1] - 2 * left_ch[i - 2] + left_ch[i - 3];
    int32_t rt2 = right_ch[i-1] - 2 * right_ch[i - 2] + right_ch[i - 3];
    sum[2] += (((lt1 + rt1) >> 1) >= 0 ? ((lt1 + rt1) >> 1) : (-((lt1 + rt1) >> 1)));
    sum[3] += ((lt1 - rt1) >= 0 ? (lt1 - rt1) : (-(lt1 - rt1)));
    sum[0] += ((lt1) >= 0 ? (lt1) : (-(lt1))) + ((lt2) >= 0 ? (lt2) : (-(lt2)));
    sum[1] += ((rt1) >= 0 ? (rt1) : (-(rt1))) + ((rt2) >= 0 ? (rt2) : (-(rt2)));
}
}
