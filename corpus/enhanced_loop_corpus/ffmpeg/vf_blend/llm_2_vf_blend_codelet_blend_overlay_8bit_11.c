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
    // Variant 1: Consecutive memory access with pointer arithmetic unrolled by 2 elements
    // This variant assumes width is even and processes two pixels per iteration to promote consecutive access
    for (i = 0; i < height; i++) {
        uint8_t *top_ptr = top;
        uint8_t *bottom_ptr = bottom;
        uint8_t *dst_ptr = dst;
        for (j = 0; j < width - 1; j += 2) {
            // Process two adjacent pixels consecutively
            dst_ptr[j] = top_ptr[j] + (((top_ptr[j] < 128) ? 
                ((2) * (((top_ptr[j]) * (bottom_ptr[j])) / 255)) : 
                (255 - (2) * ((255 - top_ptr[j]) * (255 - bottom_ptr[j]) / 255))) - top_ptr[j]) * opacity;

            dst_ptr[j+1] = top_ptr[j+1] + (((top_ptr[j+1] < 128) ? 
                ((2) * (((top_ptr[j+1]) * (bottom_ptr[j+1])) / 255)) : 
                (255 - (2) * ((255 - top_ptr[j+1]) * (255 - bottom_ptr[j+1]) / 255))) - top_ptr[j+1]) * opacity;
        }
        // Handle last pixel if width is odd
        if (j < width) {
            dst_ptr[j] = top_ptr[j] + (((top_ptr[j] < 128) ? 
                ((2) * (((top_ptr[j]) * (bottom_ptr[j])) / 255)) : 
                (255 - (2) * ((255 - top_ptr[j]) * (255 - bottom_ptr[j]) / 255))) - top_ptr[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
