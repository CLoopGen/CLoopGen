#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern  uint16_t *_usr_index;
extern  uint16_t *src;
extern uint16_t *dst;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (y = 0; y < height; y++) {
    for (int block_y = 0; block_y < 2 && y * 2 + block_y < height * 2; block_y++) {
        for (int block_x = 0; block_x < 2 && (y * 2 + block_y) * ilinesize + (block_x << 1) < (height << 1) * ilinesize; block_x++) {
            for (x = 0; x < width; x++) {
                int abs_y = y * 2 + block_y;
                int abs_x = x * 2 + block_x;
                int idx = abs_y * ilinesize + abs_x;
                int v = lut[index[idx]];
                if (v >= 0 && v <= max) {
                    dst[x] = v;
                } else {
                    dst[x] = src[x];
                }
            }
            src += slinesize;
            dst += dlinesize;
        }
    }
}
}
