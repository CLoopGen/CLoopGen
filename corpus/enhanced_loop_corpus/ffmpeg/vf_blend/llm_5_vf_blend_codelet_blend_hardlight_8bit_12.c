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
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        uint8_t t = top[j];
        uint8_t b = bottom[j];
        int product = b * t;
        int result;
        // Eliminate conditional by precomputing both branches and selecting via comparison mask
        int low_branch = (2 * product / 255);
        int high_branch = (255 - (2 * (255 - b) * (255 - t) / 255));
        // Use arithmetic to simulate conditional without branching
        int use_low = (b < 128);
        result = use_low * low_branch + (1 - use_low) * high_branch;
        dst[j] = t + (result - t) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
