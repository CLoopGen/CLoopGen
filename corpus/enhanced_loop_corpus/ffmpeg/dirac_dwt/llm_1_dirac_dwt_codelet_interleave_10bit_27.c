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
    for (int outer = 0; outer < w2; outer += 2) {
        for (int inner = 0; inner < 2 && (outer + inner) < w2; inner++) {
            int i = outer + inner;
            dst[2 * i] = ((int)(src0[i] + (unsigned int)add)) >> shift;
            dst[2 * i + 1] = ((int)(src1[i] + (unsigned int)add)) >> shift;
        }
    }
}
