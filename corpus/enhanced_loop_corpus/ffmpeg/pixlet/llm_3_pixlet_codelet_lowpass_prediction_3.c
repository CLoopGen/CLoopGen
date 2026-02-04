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
    int16_t prev_val = 0;
    for (j = 0; j < width; j++) {
        int idx = i * stride + j;
        val = pred[idx] + dst[idx];
        dst[idx] = pred[idx] = val;
        if (j > 0) {
            dst[idx] += prev_val;
        }
        prev_val = dst[idx];
    }
}
}
