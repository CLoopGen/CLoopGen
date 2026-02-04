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
    for (y = 0; y < height; y++) {
        uint8_t temp_row[width];
        for (x = 0; x < width; x++) {
            int idx = (y >> 1) * ilinesize + (x >> 1);
            int v = (int)lut[index[idx]];
            if (v >= 0 && v <= max) {
                temp_row[x] = (uint8_t)v;
            } else {
                temp_row[x] = src[x];
            }
        }
        for (x = 0; x < width; x++) {
            dst[x] = temp_row[x];
        }
        src += slinesize;
        dst += dlinesize;
    }
}
