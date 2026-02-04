#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int max;
extern int width;
extern int height;
extern  uint8_t *_usr_index;
extern  uint8_t *src;
extern uint8_t *dst;
extern ptrdiff_t ilinesize;
extern ptrdiff_t slinesize;
extern ptrdiff_t dlinesize;
extern float *lut;
extern int x;
extern int y;

// Variable name mappings to avoid conflicts with system symbols
#define index _usr_index



void loop(){
for (y = 0; y < height; y += 2) {
    for (x = 0; x < width; x++) {
        int v1 = lut[index[x]];
        int v2 = lut[index[x + ilinesize]];
        int u1 = (v1 >= 0 && v1 <= max) ? v1 : src[x];
        int u2 = (v2 >= 0 && v2 <= max) ? v2 : src[x + slinesize];
        dst[x] = u1;
        if (y + 1 < height) {
            ((uint8_t*)((char*)dst + dlinesize))[x] = u2;
        }
    }
    index += 2 * ilinesize;
    src += 2 * slinesize;
    dst += 2 * dlinesize;
}
}
