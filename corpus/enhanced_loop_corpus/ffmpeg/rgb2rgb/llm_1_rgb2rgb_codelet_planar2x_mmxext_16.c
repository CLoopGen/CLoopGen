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
    if (srcWidth <= 1) return;
    int x1, x2;
    for (x = 0; x < srcWidth - 3; x += 2) {
        x1 = x;
        x2 = x + 1;
        dst[2 * x1 + 1] = (3 * src[x1] + src[x1 + 1]) >> 2;
        dst[2 * x1 + 2] = (src[x1] + 3 * src[x1 + 1]) >> 2;
        dst[2 * x2 + 1] = (3 * src[x2] + src[x2 + 1]) >> 2;
        dst[2 * x2 + 2] = (src[x2] + 3 * src[x2 + 1]) >> 2;
    }
    // Handle remaining elements
    for (; x < srcWidth - 1; x++) {
        dst[2 * x + 1] = (3 * src[x] + src[x + 1]) >> 2;
        dst[2 * x + 2] = (src[x] + 3 * src[x + 1]) >> 2;
    }
}
