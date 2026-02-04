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
    if (srcWidth > 1) {
        x = 0;
        for (; x < srcWidth - 1; ) {
            dst[2 * x + 1] = (3 * src[x] + src[x + 1]) >> 2;
            dst[2 * x + 2] = (src[x] + 3 * src[x + 1]) >> 2;
            x++;
        }
    }
}
