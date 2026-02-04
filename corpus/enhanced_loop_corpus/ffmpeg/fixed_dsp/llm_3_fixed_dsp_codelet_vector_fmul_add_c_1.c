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
    // Variant 2: Reverse Sequential Access
    for (i = len - 1; i >= 0; i--) {
        accu = (int64_t)src0[i] * src1[i];
        dst[i] = src2[i] + (int)((accu + 1073741824) >> 31);
    }
}
