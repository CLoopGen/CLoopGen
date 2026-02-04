#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *data;
extern int linesize;
extern int w;
extern int h;
extern int min_val;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (access every 4th element first, then stride back)
    int stride = 4;
    int offset;
    for (offset = 0; offset < stride; offset++) {
        for (y = 0; y < h; y++) {
            for (x = offset; x < w; x += stride) {
                data[y * linesize + x] = data[y * linesize + x] > min_val;
            }
        }
    }
}
