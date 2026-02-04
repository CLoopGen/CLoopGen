#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern ptrdiff_t top_linesize;
extern  uint8_t *bottom;
extern ptrdiff_t bottom_linesize;
extern uint8_t *dst;
extern ptrdiff_t dst_linesize;
extern ptrdiff_t width;
extern ptrdiff_t height;
extern double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Pointer-Based Access with Local Pointer Variables
    for (i = 0; i < height; i++) {
        uint8_t *top_ptr = top;
        uint8_t *bottom_ptr = bottom;
        uint8_t *dst_ptr = dst;
        
        for (j = 0; j < width; j++) {
            *dst_ptr = *top_ptr + (((255 - (1) * ((255 - (*top_ptr)) * (255 - (*bottom_ptr)) / 255))) - *top_ptr) * opacity;
            dst_ptr++;
            top_ptr++;
            bottom_ptr++;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
