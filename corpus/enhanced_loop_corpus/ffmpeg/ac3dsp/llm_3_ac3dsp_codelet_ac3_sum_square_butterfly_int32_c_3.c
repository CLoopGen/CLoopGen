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
for (i = 0; i < len; i++) {
    int idx = (i * 3) % len; // Strided access with wrap-around to ensure valid index
    int lt = coef0[idx];
    int rt = coef1[idx];
    int md = lt + rt;
    int sd = lt - rt;
    ((sum[0]) += ((int64_t)(lt) * (int64_t)(lt)));
    ((sum[1]) += ((int64_t)(rt) * (int64_t)(rt)));
    ((sum[2]) += ((int64_t)(md) * (int64_t)(md)));
    ((sum[3]) += ((int64_t)(sd) * (int64_t)(sd)));
}
}
