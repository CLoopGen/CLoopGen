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
    for (j = 0; j < width; j += 2) {
        ptrdiff_t j1 = j;
        ptrdiff_t j2 = j + 1;
        if (j2 < width) {
            dst[j1] = top[j1] + (((top[j1] < 128) ? (((2 * top[j1]) == 0) ? (2 * top[j1]) : ((0) > (255 - ((255 - (bottom[j1])) << 8) / (2 * top[j1])) ? (0) : (255 - ((255 - (bottom[j1])) << 8) / (2 * top[j1])))) : (((2 * (top[j1] - 128)) == 255) ? (2 * (top[j1] - 128)) : ((255) > ((((bottom[j1]) << 8) / (255 - (2 * (top[j1] - 128))))) ? ((((bottom[j1]) << 8) / (255 - (2 * (top[j1] - 128))))) : (255)))) - top[j1]) * opacity;

            dst[j2] = top[j2] + (((top[j2] < 128) ? (((2 * top[j2]) == 0) ? (2 * top[j2]) : ((0) > (255 - ((255 - (bottom[j2])) << 8) / (2 * top[j2])) ? (0) : (255 - ((255 - (bottom[j2])) << 8) / (2 * top[j2])))) : (((2 * (top[j2] - 128)) == 255) ? (2 * (top[j2] - 128)) : ((255) > ((((bottom[j2]) << 8) / (255 - (2 * (top[j2] - 128))))) ? ((((bottom[j2]) << 8) / (255 - (2 * (top[j2] - 128))))) : (255)))) - top[j2]) * opacity;
        } else {
            dst[j1] = top[j1] + (((top[j1] < 128) ? (((2 * top[j1]) == 0) ? (2 * top[j1]) : ((0) > (255 - ((255 - (bottom[j1])) << 8) / (2 * top[j1])) ? (0) : (255 - ((255 - (bottom[j1])) << 8) / (2 * top[j1])))) : (((2 * (top[j1] - 128)) == 255) ? (2 * (top[j1] - 128)) : ((255) > ((((bottom[j1]) << 8) / (255 - (2 * (top[j1] - 128))))) ? ((((bottom[j1]) << 8) / (255 - (2 * (top[j1] - 128))))) : (255)))) - top[j1]) * opacity;
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
