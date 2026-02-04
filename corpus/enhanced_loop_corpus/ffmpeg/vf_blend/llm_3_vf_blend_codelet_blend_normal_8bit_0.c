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
    // Variant 2: Consecutive Pointer-Based Access with Local Temporaries
    // Use pointer variables that traverse memory consecutively to improve locality and clarity
    uint8_t *d = dst;
    uint8_t *t = top;
    uint8_t *b = bottom;

    for (i = 0; i < height; i++) {
        uint8_t *di = d;
        uint8_t *ti = t;
        uint8_t *bi = b;

        for (j = 0; j < width; j++) {
            di[j] = ti[j] * opacity + bi[j] * (1. - opacity);
        }

        d += dst_linesize;
        t += top_linesize;
        b += bottom_linesize;
    }

    // Update original pointers (if needed beyond this function, though extern implies global state)
    dst = d - (height * dst_linesize);
    top = t - (height * top_linesize);
    bottom = b - (height * bottom_linesize);
}
