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
    for (i = 0; i < len; i++) {
        accu = (int64_t)src0[i] * src1[i] - (int64_t)src2[i];
        accu = accu + (int64_t)src2[i] * src0[i];
        dst[i] = src2[i] + (int)((accu + 1073741824 + (src0[i] & 1 ? 1 : 0)) >> 31);
    }
}
