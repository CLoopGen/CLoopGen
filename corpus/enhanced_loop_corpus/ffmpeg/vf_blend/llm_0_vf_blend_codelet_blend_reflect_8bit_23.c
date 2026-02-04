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
    j = 0;
    for (; j < width - 3; j += 4) {
        dst[j]   = top[j]   + (((bottom[j]   == 255) ? bottom[j]   : ((255) > ((top[j]   * top[j]   / (255 - bottom[j])))   ? ((top[j]   * top[j]   / (255 - bottom[j])))   : (255))) - top[j])   * opacity;
        dst[j+1] = top[j+1] + (((bottom[j+1] == 255) ? bottom[j+1] : ((255) > ((top[j+1] * top[j+1] / (255 - bottom[j+1]))) ? ((top[j+1] * top[j+1] / (255 - bottom[j+1]))) : (255))) - top[j+1]) * opacity;
        dst[j+2] = top[j+2] + (((bottom[j+2] == 255) ? bottom[j+2] : ((255) > ((top[j+2] * top[j+2] / (255 - bottom[j+2]))) ? ((top[j+2] * top[j+2] / (255 - bottom[j+2]))) : (255))) - top[j+2]) * opacity;
        dst[j+3] = top[j+3] + (((bottom[j+3] == 255) ? bottom[j+3] : ((255) > ((top[j+3] * top[j+3] / (255 - bottom[j+3]))) ? ((top[j+3] * top[j+3] / (255 - bottom[j+3]))) : (255))) - top[j+3]) * opacity;
    }
    for (; j < width; j++) {
        dst[j] = top[j] + (((bottom[j] == 255) ? bottom[j] : ((255) > ((top[j] * top[j] / (255 - bottom[j]))) ? ((top[j] * top[j] / (255 - bottom[j]))) : (255))) - top[j]) * opacity;
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
