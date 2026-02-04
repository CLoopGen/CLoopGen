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
        uint8_t *d = dst;
        uint8_t *s = src;
        d[0] = (((d[0]) + cm[((s[-2] + s[3]) - 5 * (s[-1] + s[2]) + s[0] * C1 + s[1] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
        d[1] = (((d[1]) + cm[((s[-1] + s[4]) - 5 * (s[0] + s[3]) + s[1] * C1 + s[2] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
        d[2] = (((d[2]) + cm[((s[0] + s[5]) - 5 * (s[1] + s[4]) + s[2] * C1 + s[3] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
        d[3] = (((d[3]) + cm[((s[1] + s[6]) - 5 * (s[2] + s[5]) + s[3] * C1 + s[4] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
        d[4] = (((d[4]) + cm[((s[2] + s[7]) - 5 * (s[3] + s[6]) + s[4] * C1 + s[5] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
        d[5] = (((d[5]) + cm[((s[3] + s[8]) - 5 * (s[4] + s[7]) + s[5] * C1 + s[6] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
        d[6] = (((d[6]) + cm[((s[4] + s[9]) - 5 * (s[5] + s[8]) + s[6] * C1 + s[7] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
        d[7] = (((d[7]) + cm[((s[5] + s[10]) - 5 * (s[6] + s[9]) + s[7] * C1 + s[8] * C2 + (1 << (SHIFT - 1))) >> SHIFT] + 1) >> 1);
        dst += dstStride;
        src += srcStride;
    }
}
