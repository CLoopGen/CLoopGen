#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern int srcWidth;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with reversed traversal
    for (x = srcWidth - 2; x >= 0; x--) {
        int idx = 2 * x;
        dst[idx + 1] = (3 * src[x] + src[x + 1]) >> 2;
        dst[idx + 2] = (src[x] + 3 * src[x + 1]) >> 2;
    }
}
