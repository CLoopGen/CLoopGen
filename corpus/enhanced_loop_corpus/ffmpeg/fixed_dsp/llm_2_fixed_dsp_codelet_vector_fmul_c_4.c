#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *dst;
extern  int *src0;
extern  int *src1;
extern int len;
extern int i;
extern int64_t accu;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < len; i += 2) {
        if (i + 1 < len) {
            accu = (int64_t)src0[i] * src1[i];
            dst[i] = (int)((accu + 1073741824) >> 31);
            accu = (int64_t)src0[i + 1] * src1[i + 1];
            dst[i + 1] = (int)((accu + 1073741824) >> 31);
        } else {
            accu = (int64_t)src0[i] * src1[i];
            dst[i] = (int)((accu + 1073741824) >> 31);
        }
    }
}
