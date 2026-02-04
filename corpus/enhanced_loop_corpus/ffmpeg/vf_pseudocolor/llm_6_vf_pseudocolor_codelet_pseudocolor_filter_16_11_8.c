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
        uint16_t temp_val;
        for (x = 0; x < width; x++) {
            int idx = (y << 1) * ilinesize + (x << 1);
            int v = lut[index[idx]];
            // Introduce temporary to create intra-iteration dependency (WAW and RAW)
            if (v >= 0 && v <= max) {
                temp_val = v;
            } else {
                temp_val = src[x];
            }
            dst[x] = temp_val; // Write after write dependency via temp_val
        }
        src += slinesize;
        dst += dlinesize;
    }
}
