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



void loop() {
    for (i = 0; i < h; i++) {
        int j;
        for (j = 0; j < 8; j++) {
            int index = (src[j - 2] + src[j + 3] - 5 * (src[j - 1] + src[j + 2]) + src[j] * C1 + src[j + 1] * C2 + (1 << (SHIFT - 1))) >> SHIFT;
            dst[j] = (((dst[j]) + cm[index] + 1) >> 1);
        }
        dst += dstStride;
        src += srcStride;
    }
}
