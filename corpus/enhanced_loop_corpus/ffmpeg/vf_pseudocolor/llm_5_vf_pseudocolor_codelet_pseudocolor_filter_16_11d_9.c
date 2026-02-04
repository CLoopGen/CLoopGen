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
    int iy = (y >> 1) * ilinesize;
    for (x = 0; x < width; x += 2) {
        int base_idx = iy + (x >> 1);
        int v1 = (int)lut[index[base_idx]];
        int valid1 = (v1 >= 0 && v1 <= max);
        dst[x] = valid1 ? v1 : src[x];
        
        if (x + 1 < width) {
            dst[x + 1] = valid1 ? v1 : src[x + 1];
        }
    }
    src += slinesize;
    dst += dlinesize;
}
}
