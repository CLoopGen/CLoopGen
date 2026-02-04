#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int16_t *pred;
extern int width;
extern int height;
extern ptrdiff_t stride;
extern int16_t val;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
        val = pred[j] + dst[j];
        dst[j] = pred[j] = val;
        if (j > 0) {
            dst[j] += dst[j - 1];
        }
    }
    dst += stride;
}
}
