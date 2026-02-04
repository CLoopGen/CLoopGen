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
    for (int ii = 0; ii < 1; ii++) {
        for (j = 0; j < width; j++) {
            dst[j] = top[j] + (((top[j] < 128) ? (((2 * top[j]) == 0) ? (2 * top[j]) : ((0) > (255 - ((255 - (bottom[j])) << 8) / (2 * top[j])) ? (0) : (255 - ((255 - (bottom[j])) << 8) / (2 * top[j])))) : (((2 * (top[j] - 128)) == 255) ? (2 * (top[j] - 128)) : ((255) > ((((bottom[j]) << 8) / (255 - (2 * (top[j] - 128))))) ? ((((bottom[j]) << 8) / (255 - (2 * (top[j] - 128))))) : (255)))) - top[j]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
