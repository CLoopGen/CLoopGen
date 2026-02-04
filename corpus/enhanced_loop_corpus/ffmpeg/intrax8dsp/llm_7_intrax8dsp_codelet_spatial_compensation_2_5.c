#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t stride;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < 8; y++) {
        for (x = 0; x < 8; x++) {
            int index = (8 + 8 + 1) + 1 + y + x;
            dst[x] = src[index];           // RAW: dst[x] depends on index and src
            src[index] = src[index] + 1;   // WAW on src[index] — introduces write after read and write after write
        }
        dst += stride;
    }
}
