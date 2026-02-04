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
    for (int j = 0; j < 2; j++) {
        for (i = 0; i < w2; i++) {
            if (j == 0) {
                dst[2 * i] = ((int)(src0[i] + (unsigned int)add)) >> shift;
            } else {
                dst[2 * i + 1] = ((int)(src1[i] + (unsigned int)add)) >> shift;
            }
        }
    }
}
