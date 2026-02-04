#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ptrdiff_t top_linesize;
extern ptrdiff_t bottom_linesize;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern  uint16_t *top;
extern  uint16_t *bottom;
extern uint16_t *dst;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with precomputed base pointers and stride handling via indexing
    uint16_t *top_base = top;
    uint16_t *bottom_base = bottom;
    uint16_t *dst_base = dst;
    for (i = 0; i < height; i++) {
        ptrdiff_t idx = i * width; // Linear index for consecutive-like access pattern
        for (j = 0; j < width; j++) {
            ptrdiff_t offset = idx + j; // Flatten 2D access into 1D
            dst_base[offset] = top_base[j] + (((top_base[j] < 2048) ? 
                (((2 * top_base[j]) == 0) ? (2 * top_base[j]) : 
                ((0) > (4095 - ((4095 - (bottom_base[j])) << 12) / (2 * top_base[j])) ? (0) : 
                (4095 - ((4095 - (bottom_base[j])) << 12) / (2 * top_base[j])))) : 
                (((2 * (top_base[j] - 2048)) == 4095) ? (2 * (top_base[j] - 2048)) : 
                ((4095) > ((((bottom_base[j]) << 12) / (4095 - (2 * (top_base[j] - 2048))))) ? 
                ((((bottom_base[j]) << 12) / (4095 - (2 * (top_base[j] - 2048))))) : (4095)))) - top_base[j]) * opacity;
        }
    }
    // Note: No pointer updates needed since we use base + index
}
