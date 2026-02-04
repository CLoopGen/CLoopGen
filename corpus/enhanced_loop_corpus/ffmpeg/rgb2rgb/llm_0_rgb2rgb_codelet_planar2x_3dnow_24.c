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
    for (int outer = 0; outer < (srcWidth - 1) / 16 + 1; outer++) {
        int start = outer * 16;
        int end = (start + 16 < srcWidth - 1) ? start + 16 : srcWidth - 1;
        for (x = start; x < end; x++) {
            dst[2 * x + 1] = (3 * src[x] + src[x + 1]) >> 2;
            dst[2 * x + 2] = (src[x] + 3 * src[x + 1]) >> 2;
        }
    }
}
