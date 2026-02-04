#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *dst;
extern int height;
extern int width;
extern int x;
extern int y;
extern uint16_t *src;
extern ptrdiff_t srcstride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int16_t *dst_local = dst;
    uint16_t *src_local = src;
    for (y = 0; y < height; y++) {
        int temp_shift = 14 - 10;
        for (x = 0; x < width; x++) {
            int16_t val = (int16_t)(src_local[x] << temp_shift);
            dst_local[x] = val;
        }
        src_local += srcstride;
        dst_local += 64;
    }
}
