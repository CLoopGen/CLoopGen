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
    int32_t temp0, temp1;
    for (i = 0; i < w2; i++) {
        temp0 = src0[i] + (unsigned int)add;
        temp1 = src1[i] + (unsigned int)add;
        dst[2 * i] = ((int)temp0) >> shift;
        dst[2 * i + 1] = ((int)temp1) >> shift;
    }
}
