#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int count;
extern int i;
extern  uint8_t * palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic and pre-computed palette stride
    uint32_t *p_pal = pal;
    const uint8_t *p_palette = palette;
    for (i = 0; i < count; i++) {
        uint8_t r = *p_palette++;
        uint8_t g = *p_palette++;
        uint8_t b = *p_palette++;
        *p_pal++ = 4278190080U | ((r << 16) | (g << 8) | b);
    }
}
