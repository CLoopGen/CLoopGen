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
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x++) {
        int v1 = lut[index[x << 1]];
        int v2 = lut[index[(x << 1) + 2]];
        if (v1 >= 0 && v1 <= max) {
            dst[x] = v1;
        } else {
            dst[x] = src[x];
        }
        if (y + 1 < height) {
            if (v2 >= 0 && v2 <= max) {
                dst[width + x] = v2;
            } else {
                dst[width + x] = src[width + x];
            }
        }
    }
    index += ilinesize / 2;
    src += slinesize / 2;
    dst += dlinesize / 2;
    if (y + 1 < height) {
        index += ilinesize / 2;
        src += slinesize / 2;
        dst += dlinesize / 2;
    }
}
}
