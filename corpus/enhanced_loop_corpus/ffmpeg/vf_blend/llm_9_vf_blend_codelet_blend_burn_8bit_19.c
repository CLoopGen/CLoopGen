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
        for (j = 0; j < width; j += 4) {
            for (int k = 0; k < 4 && (j + k) < width; k++) {
                int idx = j + k;
                int base = top[idx];
                int overlay = bottom[idx];
                int temp = (base == 0) ? base : (255 - ((255 - overlay) << 8) / base);
                temp = (temp < 0) ? 0 : (temp > 255 ? 255 : temp);
                dst[idx] = base + (temp - base) * opacity;
            }
        }
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
