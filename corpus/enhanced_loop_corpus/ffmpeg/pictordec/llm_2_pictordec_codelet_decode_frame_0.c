#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern const uint32_t ff_cga_palette[16];
extern  uint8_t cga_mode45_index[6][4];
extern uint32_t *palette;
extern int npal;
extern int i;
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with pointer arithmetic
    uint32_t *pal = palette;
    const uint8_t *idx_row = cga_mode45_index[idx];
    const uint32_t *cga_pal = ff_cga_palette;
    for (i = 0; i < npal; i++) {
        *pal++ = cga_pal[*idx_row++];
    }
}
