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
    // Variant 2: Consecutive Block Access with Pointer Arithmetic (process elements using local pointers and consecutive access)
    for (i = 0; i < height; i++) {
        uint16_t *dst_ptr = dst;
        uint16_t *top_ptr = top;
        uint16_t *bottom_ptr = bottom;
        
        // Use consecutive memory access via local pointer increments
        for (j = 0; j < width; j++) {
            *dst_ptr = *top_ptr + ((((1023) > (*top_ptr + *bottom_ptr) ? (*top_ptr + *bottom_ptr) : (1023))) - *top_ptr) * opacity;
            dst_ptr++;
            top_ptr++;
            bottom_ptr++;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
