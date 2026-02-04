#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int src_size;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < src_size - 2; i += 3) {
        register uint8_t temp = src[i + 2];
        dst[i + 0] = temp;
        dst[i + 1] = src[i + 1];
        // Introduce artificial write-after-write dependency with dummy assignment
        dst[i + 2] = src[i + 0];
        dst[i + 2] = dst[i + 2]; // WAW dependency introduced: redundant store to same location
    }
}
