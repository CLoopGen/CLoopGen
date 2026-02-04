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
    float *local_lut = lut;
    uint16_t *local_index = index;
    uint16_t *local_src = src;
    uint16_t *local_dst = dst;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x += 2) {
            int v0 = local_lut[local_index[x << 1]];
            int v1 = local_lut[local_index[(x + 1) << 1]];
            if (v0 >= 0 && v0 <= max) {
                local_dst[x] = v0;
            } else {
                local_dst[x] = local_src[x];
            }
            if (v1 >= 0 && v1 <= max) {
                local_dst[x + 1] = v1;
            } else {
                local_dst[x + 1] = local_src[x + 1];
            }
        }
        local_index += ilinesize / 2;
        local_src += slinesize / 2;
        local_dst += dlinesize / 2;
    }
}
