#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern ptrdiff_t dstStride;
extern ptrdiff_t srcStride;
extern  int h;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < h; i++) {
    uint8_t temp_vals[8];
    ptrdiff_t s = i * srcStride;
    ptrdiff_t d = i * dstStride;
    
    temp_vals[0] = cm[((0 * src[s - 2] + -7 * src[s - 1] + 42 * src[s + 0] + 96 * src[s + 1] + -2 * src[s + 2] + -1 * src[s + 3]) + 64) >> 7];
    temp_vals[1] = cm[((0 * src[s - 1] + -7 * src[s + 0] + 42 * src[s + 1] + 96 * src[s + 2] + -2 * src[s + 3] + -1 * src[s + 4]) + 64) >> 7];
    temp_vals[2] = cm[((0 * src[s + 0] + -7 * src[s + 1] + 42 * src[s + 2] + 96 * src[s + 3] + -2 * src[s + 4] + -1 * src[s + 5]) + 64) >> 7];
    temp_vals[3] = cm[((0 * src[s + 1] + -7 * src[s + 2] + 42 * src[s + 3] + 96 * src[s + 4] + -2 * src[s + 5] + -1 * src[s + 6]) + 64) >> 7];
    temp_vals[4] = cm[((0 * src[s + 2] + -7 * src[s + 3] + 42 * src[s + 4] + 96 * src[s + 5] + -2 * src[s + 6] + -1 * src[s + 7]) + 64) >> 7];
    temp_vals[5] = cm[((0 * src[s + 3] + -7 * src[s + 4] + 42 * src[s + 5] + 96 * src[s + 6] + -2 * src[s + 7] + -1 * src[s + 8]) + 64) >> 7];
    temp_vals[6] = cm[((0 * src[s + 4] + -7 * src[s + 5] + 42 * src[s + 6] + 96 * src[s + 7] + -2 * src[s + 8] + -1 * src[s + 9]) + 64) >> 7];
    temp_vals[7] = cm[((0 * src[s + 5] + -7 * src[s + 6] + 42 * src[s + 7] + 96 * src[s + 8] + -2 * src[s + 9] + -1 * src[s + 10]) + 64) >> 7];

    for (int j = 0; j < 8; j++) {
        dst[d + j] = ((dst[d + j]) + temp_vals[j] + 1) >> 1;
    }
}
}
