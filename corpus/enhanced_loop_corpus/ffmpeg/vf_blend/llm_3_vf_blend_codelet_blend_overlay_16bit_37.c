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
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j += 2) { // Strided access with step 2
            if (j + 1 < width) {
                // Process two elements at once with stride-2 access
                dst[j] = top[j] + (((top[j] < 32768) ? ((2) * (((top[j]) * (bottom[j])) / 65535)) : (65535 - (2) * ((65535 - (top[j])) * (65535 - (bottom[j])) / 65535))) - top[j]) * opacity;
                dst[j+1] = top[j+1] + (((top[j+1] < 32768) ? ((2) * (((top[j+1]) * (bottom[j+1])) / 65535)) : (65535 - (2) * ((65535 - (top[j+1])) * (65535 - (bottom[j+1])) / 65535))) - top[j+1]) * opacity;
            } else {
                // Handle last element if width is odd
                dst[j] = top[j] + (((top[j] < 32768) ? ((2) * (((top[j]) * (bottom[j])) / 65535)) : (65535 - (2) * ((65535 - (top[j])) * (65535 - (bottom[j])) / 65535))) - top[j]) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
