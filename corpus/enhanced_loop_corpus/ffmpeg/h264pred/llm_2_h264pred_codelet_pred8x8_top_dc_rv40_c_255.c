#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern int i;
extern unsigned int dc0;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access (flattened indexing)
    uint32_t *base = (uint32_t *)src;
    ptrdiff_t stride32 = stride / sizeof(uint32_t);
    for (i = 0; i < 8; i++) {
        int offset = i * stride32;
        base[offset + 0] = dc0;
        base[offset + 1] = dc0;
    }
}
