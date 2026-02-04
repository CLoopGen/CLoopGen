#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int i;
extern  uint8_t * palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed base pointer and unrolling by 2
    uint8_t *base_palette = palette;
    uint32_t *base_pal = pal + 32;
    for (i = 0; i < 32; i += 2) {
        // First element
        base_pal[i] = 4278190080U | (((((const uint8_t *)(base_palette + i * 3))[0] << 16) | 
                                   (((const uint8_t *)(base_palette + i * 3))[1] << 8) | 
                                   ((const uint8_t *)(base_palette + i * 3))[2]) & 16711422) >> 1;
        // Second element (if within bounds)
        if (i + 1 < 32) {
            base_pal[i + 1] = 4278190080U | (((((const uint8_t *)(base_palette + (i + 1) * 3))[0] << 16) | 
                                             (((const uint8_t *)(base_palette + (i + 1) * 3))[1] << 8) | 
                                             ((const uint8_t *)(base_palette + (i + 1) * 3))[2]) & 16711422) >> 1;
        }
    }
}
