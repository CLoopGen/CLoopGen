#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int stride;
extern int i;
extern uint16_t *dst;
extern int32_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int level1 = 0; level1 < 2; level1++) {
    for (int level2 = 0; level2 < 2; level2++) {
        int flat_idx = level1 * 2 + level2;
        dst[flat_idx] += (unsigned int)src[flat_idx];
    }
}
// Adjust pointer arithmetic only once after full iteration
dst += stride * 2;
src += 8;
}
