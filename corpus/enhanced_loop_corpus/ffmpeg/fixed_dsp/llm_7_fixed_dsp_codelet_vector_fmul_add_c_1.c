#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *dst;
extern  int *src0;
extern  int *src1;
extern  int *src2;
extern int len;
extern int i;
extern int64_t accu;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t temp_accu;
    int prev_index = (len > 0) ? 0 : 0;
    for (i = 1; i <= len; i++) {
        if (i < len) {
            temp_accu = (int64_t)src0[i] * src1[i];
            dst[prev_index] = src2[prev_index] + (int)(((int64_t)src0[prev_index] * src1[prev_index] + 1073741824) >> 31);
            prev_index = i;
        }
    }
    if (len == 1) {
        temp_accu = (int64_t)src0[0] * src1[0];
        dst[0] = src2[0] + (int)((temp_accu + 1073741824) >> 31);
    } else if (len > 0 && prev_index == len - 1) {
        temp_accu = (int64_t)src0[prev_index] * src1[prev_index];
        dst[prev_index] = src2[prev_index] + (int)((temp_accu + 1073741824) >> 31);
    }
}
