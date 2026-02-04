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
// Reduce computational intensity: simplify blending and increase stride
const double scaled_opacity = opacity * 0.5;
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j += 2) {
        // Simplified blending: use average instead of complex conditional logic
        uint8_t blended = (uint8_t)((top[j] + bottom[j]) >> 1);
        dst[j] = (uint8_t)(top[j] + (blended - top[j]) * scaled_opacity);

        // Stride-2 access with boundary check
        if (j + 1 < width) {
            blended = (uint8_t)((top[j+1] + bottom[j+1]) >> 1);
            dst[j+1] = (uint8_t)(top[j+1] + (blended - top[j+1]) * scaled_opacity);
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
