#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int16_t *src0;
extern int16_t *src1;
extern int w2;
extern int add;
extern int shift;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp0, temp1;
    for (i = 0; i < w2; i++) {
        temp0 = src0[i] + add;
        temp1 = src1[i] + add;
        dst[2 * i] = temp0 >> shift;
        dst[2 * i + 1] = temp1 >> shift;
    }
}
