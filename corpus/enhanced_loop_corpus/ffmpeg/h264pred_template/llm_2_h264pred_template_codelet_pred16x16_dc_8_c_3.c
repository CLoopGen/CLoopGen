#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t stride;
extern int i;
extern int dc;
extern uint8_t *src;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the indexing to ensure positive offsets
    // We assume stride is positive, so we access src in reverse order from src[15] down to src[0]
    for (i = 0; i < 16; i++) {
        dc += src[15 - i];
    }
}
