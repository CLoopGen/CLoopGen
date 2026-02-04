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
    int val0 = (5 * (src[0] + src[1]) - src[-1] - src[2] + 4) >> 3;
    int val1 = (5 * (src[1] + src[2]) - src[0] - src[3] + 4) >> 3;
    int val2 = (5 * (src[2] + src[3]) - src[1] - src[4] + 4) >> 3;
    int val3 = (5 * (src[3] + src[4]) - src[2] - src[5] + 4) >> 3;
    int val4 = (5 * (src[4] + src[5]) - src[3] - src[6] + 4) >> 3;
    int val5 = (5 * (src[5] + src[6]) - src[4] - src[7] + 4) >> 3;
    int val6 = (5 * (src[6] + src[7]) - src[5] - src[8] + 4) >> 3;
    int val7 = (5 * (src[7] + src[8]) - src[6] - src[9] + 4) >> 3;

    dst[0] = cm[val0];
    dst[1] = cm[val1];
    dst[2] = cm[val2];
    dst[3] = cm[val3];
    dst[4] = cm[val4];
    dst[5] = cm[val5];
    dst[6] = cm[val6];
    dst[7] = cm[val7];

    dst += dstStride;
    src += srcStride;
}
}
