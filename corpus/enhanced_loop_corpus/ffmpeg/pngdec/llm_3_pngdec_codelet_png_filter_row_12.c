#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern uint8_t *last;
extern int bpp;
extern int i;
extern int p;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive reverse traversal of arrays
    // Processes elements from the end to the beginning
    for (i = bpp - 1; i >= 0; i--) {
        p = (last[i] >> 1);
        dst[i] = p + src[i];
    }
}
