#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *dst;
extern int32_t *src0;
extern int32_t *src1;
extern int w2;
extern int add;
extern int shift;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < w2; i++) {
        int32_t val0 = src0[i] + add;
        int32_t val1 = src1[i] + add;
        dst[2 * i]     = (val0 + (val0 >> 4)) >> shift;
        dst[2 * i + 1] = (val1 - (val1 >> 5)) >> shift;
    }
}
