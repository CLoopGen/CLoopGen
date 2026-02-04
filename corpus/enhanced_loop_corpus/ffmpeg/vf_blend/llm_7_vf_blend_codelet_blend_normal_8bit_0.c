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
extern  double opacity;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double acc = opacity;
    for (i = 0; i < height; i++) {
        double local_opacity = acc; // Introduce loop-carried dependency on opacity via accumulation
        for (j = 0; j < width; j++) {
            double blended = top[j] * local_opacity + bottom[j] * (1.0 - local_opacity);
            dst[j] = (uint8_t)blended;
        }
        acc *= 0.99; // Reduce opacity slightly each row — introduces WAW and loop-carried dependency
        dst += dst_linesize;
        top += top_linesize;
        bottom += bottom_linesize;
    }
}
