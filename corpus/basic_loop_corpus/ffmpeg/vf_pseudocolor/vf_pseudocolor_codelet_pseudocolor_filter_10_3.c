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
    for (x = 0; x < width; x++) {
        int v = lut[index[x << 1]];
        if (v >= 0 && v <= max) {
            dst[x] = v;
        } else {
            dst[x] = src[x];
        }
    }
    index += ilinesize;
    src += slinesize;
    dst += dlinesize;
}

}
