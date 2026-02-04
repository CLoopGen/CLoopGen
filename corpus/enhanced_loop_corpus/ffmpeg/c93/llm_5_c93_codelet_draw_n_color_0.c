#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int stride;
extern int width;
extern int height;
extern int bpp;
extern uint8_t cols[4];
extern uint8_t grps[4];
extern uint32_t col;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (y = 0; y < height; y++) {
    int shift_y = y >> 1;
    if (grps) {
        cols[0] = grps[3 * shift_y];
        for (x = 0; x < width; x++) {
            int shift_x = x >> 1;
            cols[1] = grps[shift_x + 1];
            uint32_t index = col & ((1 << bpp) - 1);
            out[x + y * stride] = cols[index];
            col >>= bpp;
        }
    } else {
        for (x = 0; x < width; x++) {
            uint32_t index = col & ((1 << bpp) - 1);
            out[x + y * stride] = cols[index];
            col >>= bpp;
        }
    }
}
}
