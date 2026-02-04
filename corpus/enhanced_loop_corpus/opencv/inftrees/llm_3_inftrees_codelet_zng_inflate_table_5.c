#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern uint16_t count[16];
extern uint16_t offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access – compute dependencies backward
    // This changes access pattern to descending order while maintaining correctness
    // Note: since each offs[i+1] depends on offs[i], we must reverse the iteration order
    // But original dependency is forward-only, so we instead simulate a shifted base
    // Instead, use indirect indexing via pointer arithmetic to create indirect access pattern

    uint16_t *base_offs = offs + 1;
    uint16_t *base_count = count + 1;

    for (len = 0; len < 14; len++) {
        // Indirect and offset-based access using pointer arithmetic
        *(base_offs + len + 1) = *(base_offs + len) + *(base_count + len);
    }
}
