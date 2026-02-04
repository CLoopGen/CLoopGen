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
    // Variant 2: Consecutive Linear Access with Flattened Indexing
    uint16_t *dst_base = dst;
    uint16_t *top_base = top;
    uint16_t *bottom_base = bottom;

    for (i = 0; i < height; i++) {
        ptrdiff_t offset = i * dst_linesize;
        for (j = 0; j < width; j++) {
            // Use base pointers with linear offsets to ensure consecutive access pattern
            ptrdiff_t idx = offset + j;
            dst_base[idx] = top_base[i * top_linesize + j] + 
                           (((top_base[i * top_linesize + j] > bottom_base[i * bottom_linesize + j] ? 
                              top_base[i * top_linesize + j] : bottom_base[i * bottom_linesize + j]) - 
                             top_base[i * top_linesize + j]) * opacity);
        }
    }
}
