#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *palette;
extern int i;
extern uint32_t color_count;
extern uint32_t r;
extern uint32_t g;
extern uint32_t b;
extern  uint8_t *color_table;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access with Pointer Arithmetic
    uint8_t *ct_ptr = color_table;
    uint32_t *pal_ptr = palette;
    for (i = 0; i < color_count; i++) {
        r = *ct_ptr++;
        g = *ct_ptr++;
        b = *ct_ptr++;
        *pal_ptr++ = (255U << 24) | (r << 16) | (g << 8) | b;
    }
}
