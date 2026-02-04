#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *dst;
extern  uint16_t *src;
extern unsigned int mask;
extern int w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access from end to start
    for (; i < w; i++) {
        int idx = w - 1 - i;  // Access elements in reverse order
        dst[idx] = (dst[idx] + src[idx]) & mask;
    }
}
