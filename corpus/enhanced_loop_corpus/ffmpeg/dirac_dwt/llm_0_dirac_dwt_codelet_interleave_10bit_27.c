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
    for (int j = 0; j < w2; j++) {
        for (int k = 0; k < 2; k++) {
            if (k == 0) {
                dst[2 * j] = ((int)(src0[j] + (unsigned int)add)) >> shift;
            } else {
                dst[2 * j + 1] = ((int)(src1[j] + (unsigned int)add)) >> shift;
            }
        }
    }
}
