#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *dst;
extern  uint32_t *src;
extern int stride;
extern int height;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < height; i++) {
    for (int j = 0; j < stride >> 2; j++) {
        uint32_t computed_val = ((src[j] >> 3) + (1061109567 & dst[j]));
        dst[j] = (computed_val << 3) & 4244438268U;
        src[j] = computed_val; // Introduce WAW and RAW dependency: write after write, read after write in next iterations
    }
    dst += stride >> 2;
    src += stride >> 2;
}
}
