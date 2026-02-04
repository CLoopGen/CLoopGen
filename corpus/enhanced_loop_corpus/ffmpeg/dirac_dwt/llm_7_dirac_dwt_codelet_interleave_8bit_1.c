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
    for (i = 0; i < w2; i++) {
        int sum0 = (int)(src0[i] + (unsigned int)add);
        int sum1 = (int)(src1[i] + (unsigned int)add);
        dst[2 * i] = sum0 >> shift;
        dst[2 * i] = (dst[2 * i] + (sum1 >> shift)) >> 1; // WAW and RAW dependency introduced
        dst[2 * i + 1] = sum1 >> shift;
    }
}
