#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern uint8_t *src;
extern ptrdiff_t w;
extern long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive access in reverse order (from end to beginning)
    for (; i >= 0 && (w - 1 - i) >= 0; i++)
        dst[w - 1 - i] += src[w - 1 - i];
}
