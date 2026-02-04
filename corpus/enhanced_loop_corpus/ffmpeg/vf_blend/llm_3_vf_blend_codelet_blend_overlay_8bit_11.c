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
    // Variant 2: Strided memory access – process every 2nd element in reverse order
    // This creates a non-consecutive, strided access pattern with backward traversal
    for (i = 0; i < height; i++) {
        for (j = (width % 2 == 0) ? width - 2 : width - 1; j >= 0; j -= 2) {
            // Stride of 2: only update even indices (or odd depending on width parity)
            dst[j] = top[j] + (((top[j] < 128) ? 
                ((2) * (((top[j]) * (bottom[j])) / 255)) : 
                (255 - (2) * ((255 - top[j]) * (255 - bottom[j]) / 255))) - top[j]) * opacity;
        }
        // Fill in the skipped indices in forward pass with stride 2 starting at 1
        for (j = 1; j < width; j += 2) {
            dst[j] = top[j] + (((top[j] < 128) ? 
                ((2) * (((top[j]) * (bottom[j])) / 255)) : 
                (255 - (2) * ((255 - top[j]) * (255 - bottom[j]) / 255))) - top[j]) * opacity;
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
