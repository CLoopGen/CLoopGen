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
    int idx;
    for (i = 0; i < w2; i++) {
        idx = i << 1; // Strided index calculation (equivalent to 2*i)
        dst[idx] = ((int)(src0[i] + (unsigned int)add)) >> shift;
        dst[idx + 1] = ((int)(src1[i] + (unsigned int)add)) >> shift;
    }
}
