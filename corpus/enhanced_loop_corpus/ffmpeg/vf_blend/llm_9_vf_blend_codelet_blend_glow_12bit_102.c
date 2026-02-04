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
    uint16_t t, b, r;
    double inv_opacity = 1.0 - opacity;
    for (j = 0; j < width; j += 4) {
        for (int k = 0; k < 4 && j + k < width; k++) {
            t = top[j + k];
            b = bottom[j + k];
            if (t == 4095 || t >= 4095) {
                r = 4095;
            } else {
                long long num = (long long)b * b;
                r = (num / (4095 - t)) > 4095 ? 4095 : (uint16_t)(num / (4095 - t));
            }
            dst[j + k] = (uint16_t)(t * inv_opacity + r * opacity);
        }
    }
    dst += dst_linesize;
    top += top_linesize;
    bottom += bottom_linesize;
}
}
