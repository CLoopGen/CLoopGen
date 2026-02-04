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
for (i = 1; i < n; i += 2) {
    lt = left_ch[i] - left_ch[i - 1];
    rt = right_ch[i] - right_ch[i - 1];
    sum[2] += ((lt + rt) >= 0 ? (lt + rt) : (-(lt + rt)));
    sum[0] += ((lt) >= 0 ? (lt) : (-(lt)));
    sum[1] += ((rt) >= 0 ? (rt) : (-(rt)));
}
}
