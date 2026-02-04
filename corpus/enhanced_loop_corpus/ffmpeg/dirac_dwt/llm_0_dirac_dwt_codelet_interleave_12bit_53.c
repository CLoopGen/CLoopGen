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
    for (i = 0; i < w2; i += 2) {
        if (i < w2) {
            dst[2 * i] = ((int)(src0[i] + (unsigned int)add)) >> shift;
            dst[2 * i + 1] = ((int)(src1[i] + (unsigned int)add)) >> shift;
        }
        if (i + 1 < w2) {
            dst[2 * (i + 1)] = ((int)(src0[i + 1] + (unsigned int)add)) >> shift;
            dst[2 * (i + 1) + 1] = ((int)(src1[i + 1] + (unsigned int)add)) >> shift;
        }
    }
}
