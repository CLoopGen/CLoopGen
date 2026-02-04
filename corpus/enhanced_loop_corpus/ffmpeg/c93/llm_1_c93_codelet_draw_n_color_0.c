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
    if (grps)
        cols[0] = grps[3 * (y >> 1)];
    for (x = 0; x < width; x += 2) {
        if (grps) {
            cols[1] = grps[(x >> 1) + 1];
        }
        out[x + y * stride] = cols[col & ((1 << bpp) - 1)];
        col >>= bpp;
        if (x + 1 < width) {
            out[x + 1 + y * stride] = cols[col & ((1 << bpp) - 1)];
            col >>= bpp;
        }
    }
}
}
