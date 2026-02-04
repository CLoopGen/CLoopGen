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
    for (x = 0; x < srcWidth - 3; x += 2) {
        dst[2 * x + 1] = (src[x] * 3 + src[x + 1]) >> 2;
        dst[2 * x + 2] = (src[x] + 3 * src[x + 1]) >> 2;
        dst[2 * x + 3] = (src[x + 1] * 3 + src[x + 2]) >> 2;
        dst[2 * x + 4] = (src[x + 1] + 3 * src[x + 2]) >> 2;
        dst[2 * x + 5] = (src[x + 2] * 3 + src[x + 3]) >> 2;
        dst[2 * x + 6] = (src[x + 2] + 3 * src[x + 3]) >> 2;
    }
}
