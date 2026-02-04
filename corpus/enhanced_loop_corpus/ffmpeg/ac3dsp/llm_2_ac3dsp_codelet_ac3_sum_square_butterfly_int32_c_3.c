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
for (i = 0; i < len; i += 2) {
    int lt0 = coef0[i];
    int rt0 = coef1[i];
    int md0 = lt0 + rt0;
    int sd0 = lt0 - rt0;
    ((sum[0]) += ((int64_t)(lt0) * (int64_t)(lt0)));
    ((sum[1]) += ((int64_t)(rt0) * (int64_t)(rt0)));
    ((sum[2]) += ((int64_t)(md0) * (int64_t)(md0)));
    ((sum[3]) += ((int64_t)(sd0) * (int64_t)(sd0)));

    if (i + 1 < len) {
        int lt1 = coef0[i + 1];
        int rt1 = coef1[i + 1];
        int md1 = lt1 + rt1;
        int sd1 = lt1 - rt1;
        ((sum[0]) += ((int64_t)(lt1) * (int64_t)(lt1)));
        ((sum[1]) += ((int64_t)(rt1) * (int64_t)(rt1)));
        ((sum[2]) += ((int64_t)(md1) * (int64_t)(md1)));
        ((sum[3]) += ((int64_t)(sd1) * (int64_t)(sd1)));
    }
}
}
