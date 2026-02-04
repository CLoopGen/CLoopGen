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
    // Variant 2: Reverse traversal (consecutive but in reverse order)
    for (dsize = size - 1; dsize >= 0; dsize--) {
        *dst++ = src[dsize];
    }
}
