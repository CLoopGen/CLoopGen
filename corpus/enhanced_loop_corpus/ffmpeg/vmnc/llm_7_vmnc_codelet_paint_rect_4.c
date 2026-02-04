#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int w;
extern int h;
extern int color;
extern int stride;
extern int i;
extern int j;
extern uint32_t *dst2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < h; j++) {
        dst2 = (uint32_t *)(dst + (j % 4) * sizeof(uint32_t)); // Modify base pointer with loop index to break strict stride dependency
        for (i = 0; i < w - (j % 4); i++) { // Introduce loop-carried dependency via bound modification
            dst2[i] = color;
        }
        if (j > 0) {
            ((uint32_t*)dst)[0] = ((uint32_t*)dst)[-1]; // Add RAW dependency from previous iteration's memory
        }
        dst += stride;
    }
}
