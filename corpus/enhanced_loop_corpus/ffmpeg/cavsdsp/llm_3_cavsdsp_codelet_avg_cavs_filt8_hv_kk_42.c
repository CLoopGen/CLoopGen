#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern ptrdiff_t dstStride;
extern int16_t *tmp;
extern  int w;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < w; i++) {
    int j;
    int temp_cache[11];
    const ptrdiff_t stride = 8;
    for (j = 0; j < 11; j++) {
        temp_cache[j] = tmp[(j - 2) * stride];
    }
    for (j = 0; j < 8; j++) {
        const int val = cm[((0 * temp_cache[j+0] + -1 * temp_cache[j+1] + 5 * temp_cache[j+2] + 5 * temp_cache[j+3] + -1 * temp_cache[j+4] + 0 * temp_cache[j+5]) + 512) >> 10];
        dst[j * dstStride] = ((dst[j * dstStride]) + val + 1) >> 1;
    }
    dst++;
    tmp++;
}
}
