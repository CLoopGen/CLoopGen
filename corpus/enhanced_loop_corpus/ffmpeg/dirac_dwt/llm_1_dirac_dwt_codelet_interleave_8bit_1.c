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
    for (int outer = 0; outer < 2; outer++) {
        for (i = 0; i < w2; i++) {
            if (outer == 0) {
                dst[2 * i] = ((int)(src0[i] + (unsigned int)add)) >> shift;
            } else {
                dst[2 * i + 1] = ((int)(src1[i] + (unsigned int)add)) >> shift;
            }
        }
    }
}
