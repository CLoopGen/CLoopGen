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
    for (x = 0; x < srcWidth - 1; x++) {
        uint8_t next_val = src[x + 1];
        dst[2 * x + 1] = (3 * src[x] + next_val) >> 2;
        if (x > 0) {
            dst[2 * x] = (dst[2 * x - 1] + dst[2 * x + 1]) >> 1;
        }
        dst[2 * x + 2] = (src[x] + 3 * next_val) >> 2;
    }
    if (srcWidth > 1) {
        dst[1] = (3 * src[0] + src[1]) >> 2;
    }
}
