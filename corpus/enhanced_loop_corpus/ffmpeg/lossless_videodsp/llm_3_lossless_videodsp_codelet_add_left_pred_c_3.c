#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t w;
extern int acc;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access
    // Iterates from the end of the array toward the beginning
    for (; i >= 0 && (w - 1 - i) >= 0; i++) {
        int idx = w - 1 - i;
        acc += src[idx];
        dst[idx] = acc;
    }
}
