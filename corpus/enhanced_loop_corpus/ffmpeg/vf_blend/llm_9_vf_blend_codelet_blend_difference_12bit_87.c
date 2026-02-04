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
for (i = 0; i < height; i += 2) {
    for (j = 0; j < width; j += 2) {
        // Process 2x2 block to increase computational density
        int diff1 = top[j] - bottom[j];
        int diff2 = top[j+1] - bottom[j+1];
        int diff3 = (top + top_linesize)[j] - (bottom + bottom_linesize)[j];
        int diff4 = (top + top_linesize)[j+1] - (bottom + bottom_linesize)[j+1];

        int abs1 = diff1 >= 0 ? diff1 : -diff1;
        int abs2 = diff2 >= 0 ? diff2 : -diff2;
        int abs3 = diff3 >= 0 ? diff3 : -diff3;
        int abs4 = diff4 >= 0 ? diff4 : -diff4;

        dst[j] = (uint16_t)(top[j] + (abs1 - top[j]) * opacity);
        dst[j+1] = (uint16_t)(top[j+1] + (abs2 - top[j+1]) * opacity);
        (dst + dst_linesize)[j] = (uint16_t)((top + top_linesize)[j] + (abs3 - (top + top_linesize)[j]) * opacity);
        (dst + dst_linesize)[j+1] = (uint16_t)((top + top_linesize)[j+1] + (abs4 - (top + top_linesize)[j+1]) * opacity);
    }
    dst += 2 * dst_linesize;
    top += 2 * top_linesize;
    bottom += 2 * bottom_linesize;
}
}
