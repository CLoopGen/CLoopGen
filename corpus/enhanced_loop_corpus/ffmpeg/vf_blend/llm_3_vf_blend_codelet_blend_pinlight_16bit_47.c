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
    // Variant 2: Consecutive reversed traversal (backward through each row)
    // Alters access pattern to process elements from end to start of each line
    for (i = 0; i < height; i++) {
        for (j = width - 1; j >= 0; j--) {
            dst[j] = top[j] + (((bottom[j] < 32768) ? 
                ((top[j]) > (2 * bottom[j]) ? (2 * bottom[j]) : (top[j])) : 
                ((top[j]) > (2 * (bottom[j] - 32768)) ? (top[j]) : (2 * (bottom[j] - 32768)))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
