#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint8_t *src;
extern ptrdiff_t srcstride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (y = 0; y < height; y++) {
        int sum = 0;
        for (x = 0; x < width; x += 4) {
            // Unroll and compute average of every 4 pixels to reduce operations but increase per-iteration work
            sum += src[x + 0]; sum += src[x + 1]; 
            sum += src[x + 2]; sum += src[x + 3];
            int16_t avg = (sum / 4) << (14 - 8);
            dst[x + 0] = dst[x + 1] = dst[x + 2] = dst[x + 3] = avg;
        }
        src += srcstride;
        dst += 64;
    }
}
