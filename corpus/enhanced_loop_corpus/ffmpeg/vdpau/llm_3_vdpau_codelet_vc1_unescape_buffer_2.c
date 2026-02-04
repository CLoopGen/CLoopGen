#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int size;
extern uint8_t *dst;
extern int dsize;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access from end to start
    int idx;
    for (dsize = 0; dsize < size; dsize++) {
        idx = size - 1 - dsize;
        dst[dsize] = src[idx];
    }
    dst += size;
}
