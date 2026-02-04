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
    // Variant 1: Consecutive memory access pattern
    // Instead of strided access, write 8 consecutive uint32_t values in a row
    uint32_t *base = (uint32_t *)src;
    for (i = 0; i < 8; i++) {
        base[i] = dc0;
    }
}
