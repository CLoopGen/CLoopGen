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
    j = 0;
    for (; j < width - 3; j += 4) {
        dst[j]   = top[j]   + (((bottom[j]   < 256) ? ((top[j])   > (2 * bottom[j])   ? (2 * bottom[j])   : (top[j]))   : ((top[j])   > (2 * (bottom[j]   - 256)) ? (top[j])   : (2 * (bottom[j]   - 256)))) - top[j])   * opacity;
        dst[j+1] = top[j+1] + (((bottom[j+1] < 256) ? ((top[j+1]) > (2 * bottom[j+1]) ? (2 * bottom[j+1]) : (top[j+1])) : ((top[j+1]) > (2 * (bottom[j+1] - 256)) ? (top[j+1]) : (2 * (bottom[j+1] - 256)))) - top[j+1]) * opacity;
        dst[j+2] = top[j+2] + (((bottom[j+2] < 256) ? ((top[j+2]) > (2 * bottom[j+2]) ? (2 * bottom[j+2]) : (top[j+2])) : ((top[j+2]) > (2 * (bottom[j+2] - 256)) ? (top[j+2]) : (2 * (bottom[j+2] - 256)))) - top[j+2]) * opacity;
        dst[j+3] = top[j+3] + (((bottom[j+3] < 256) ? ((top[j+3]) > (2 * bottom[j+3]) ? (2 * bottom[j+3]) : (top[j+3])) : ((top[j+3]) > (2 * (bottom[j+3] - 256)) ? (top[j+3]) : (2 * (bottom[j+3] - 256)))) - top[j+3]) * opacity;
    }
    for (; j < width; j++) {
        dst[j] = top[j] + (((bottom[j] < 256) ? ((top[j]) > (2 * bottom[j]) ? (2 * bottom[j]) : (top[j])) : ((top[j]) > (2 * (bottom[j] - 256)) ? (top[j]) : (2 * (bottom[j] - 256)))) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
