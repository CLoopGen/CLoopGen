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
        uint16_t temp_result[width];
        for (x = 0; x < width; x++) {
            int idx_val = index[x << 1];
            int v = lut[idx_val];
            temp_result[x] = (v >= 0 && v <= max) ? v : src[x];
        }
        for (x = 0; x < width; x++) {
            dst[x] = temp_result[x];
        }
        index += ilinesize / 2;
        src += slinesize / 2;
        dst += dlinesize / 2;
    }
}
