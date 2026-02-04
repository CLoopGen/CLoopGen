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
        int v1 = lut[index[x >> 1]];
        int v2 = lut[index[(x >> 1) + (ilinesize / 4)]];
        int result1 = (v1 >= 0 && v1 <= max) ? v1 : src[x];
        int result2 = (v2 >= 0 && v2 <= max) ? v2 : src[x + (slinesize / 2)];
        dst[x] = result1;
        if (y + 1 < height) {
            dst[x + (dlinesize / 2)] = result2;
        }
    }
    index += ilinesize;
    src += slinesize;
    dst += dlinesize;
}
}
