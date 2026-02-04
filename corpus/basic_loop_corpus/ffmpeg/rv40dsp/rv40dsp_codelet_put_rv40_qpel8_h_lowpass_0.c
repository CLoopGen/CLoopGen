#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern  uint8_t *src;
extern int dstStride;
extern int srcStride;
extern  int h;
extern  int C1;
extern  int C2;
extern  int SHIFT;
extern  uint8_t *cm;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < h; i++) {
    dst[0] = cm[(src[-2] + src[3] - 5 * (src[-1] + src[2]) + src[0] * C1 + src[1] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    dst[1] = cm[(src[-1] + src[4] - 5 * (src[0] + src[3]) + src[1] * C1 + src[2] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    dst[2] = cm[(src[0] + src[5] - 5 * (src[1] + src[4]) + src[2] * C1 + src[3] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    dst[3] = cm[(src[1] + src[6] - 5 * (src[2] + src[5]) + src[3] * C1 + src[4] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    dst[4] = cm[(src[2] + src[7] - 5 * (src[3] + src[6]) + src[4] * C1 + src[5] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    dst[5] = cm[(src[3] + src[8] - 5 * (src[4] + src[7]) + src[5] * C1 + src[6] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    dst[6] = cm[(src[4] + src[9] - 5 * (src[5] + src[8]) + src[6] * C1 + src[7] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    dst[7] = cm[(src[5] + src[10] - 5 * (src[6] + src[9]) + src[7] * C1 + src[8] * C2 + (1 << (SHIFT - 1))) >> SHIFT];
    dst += dstStride;
    src += srcStride;
}

}
