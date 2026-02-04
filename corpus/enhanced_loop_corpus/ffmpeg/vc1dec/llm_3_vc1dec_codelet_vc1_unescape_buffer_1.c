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
    // Variant 2: Reverse sequential access from the end of the arrays
    for (dsize = 0; dsize < size; dsize++) {
        dst[dsize] = src[size - 1 - dsize];
    }
    // Update pointer to reflect movement (if needed by context)
    dst += size;
}
