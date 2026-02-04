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
    // Variant 1: Consecutive memory access by unrolling and writing to adjacent 32-bit locations
    uint32_t *base = (uint32_t *)src;
    for (i = 0; i < 8; i++) {
        uint32_t *row = base + i * (stride / sizeof(uint32_t));
        row[0] = dc0;
        row[1] = dc0;
    }
}
