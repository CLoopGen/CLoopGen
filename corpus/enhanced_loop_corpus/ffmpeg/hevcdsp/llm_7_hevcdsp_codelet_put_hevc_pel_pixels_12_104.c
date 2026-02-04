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
    int shift_amount = 14 - 12;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x += 2) {
            if (x + 1 < width) {
                dst_local[x]     = src_local[x]     << shift_amount;
                dst_local[x + 1] = src_local[x + 1] << shift_amount;
            } else {
                dst_local[x] = src_local[x] << shift_amount;
            }
        }
        src_local += srcstride;
        dst_local += 64;
    }
}
