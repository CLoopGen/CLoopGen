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
    for (x = 0; x < (srcWidth >> 1); x++) {
        int idx = 2 * x;
        dst[4 * x + 1] = (7 * src[idx] + 5 * src[idx + 1] + 2 * src[idx + 2]) / 14;
        dst[4 * x + 2] = (5 * src[idx] + 8 * src[idx + 1] + 1 * src[idx + 2]) / 14;
        dst[4 * x + 3] = (2 * src[idx] + 7 * src[idx + 1] + 5 * src[idx + 2]) / 14;
        dst[4 * x + 4] = (1 * src[idx] + 5 * src[idx + 1] + 8 * src[idx + 2]) / 14;
    }
}
