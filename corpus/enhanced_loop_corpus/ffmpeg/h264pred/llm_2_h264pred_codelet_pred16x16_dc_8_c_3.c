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
    // and accessing a contiguous block by adjusting the base pointer.
    uint8_t *base_src = src + 15; // Point to the last element of the intended range
    for (i = 0; i < 16; i++) {
        dc += base_src[-i]; // Access elements in reverse consecutive order: base_src[0], base_src[-1], ...
    }
}
