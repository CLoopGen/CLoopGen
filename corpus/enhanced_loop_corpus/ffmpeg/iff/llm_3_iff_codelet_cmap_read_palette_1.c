#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint32_t *pal;
extern int i;
extern  uint8_t * palette;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - reverse traversal with stride of 4, processing every 4th element in a group
    uint32_t *base_pal = pal + 32;
    const uint8_t *base_palette = palette;
    for (i = 31; i >= 0; i--) {
        int idx = i; // Use descending index for strided read pattern
        const uint8_t *p = base_palette + idx * 3;
        uint32_t rgb = ((uint32_t)p[0] << 16) | ((uint32_t)p[1] << 8) | p[2];
        base_pal[idx] = 4278190080U | (rgb & 16711422) >> 1;
    }
}
