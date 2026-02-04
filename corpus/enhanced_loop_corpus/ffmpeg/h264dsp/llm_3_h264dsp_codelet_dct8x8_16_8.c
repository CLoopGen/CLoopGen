#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *coef;
extern int i;
extern int16_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < 8; i++) {
        int16_t *src = coef;
        int16_t *dst = tmp;
        const int idx[] = {0, 8, 16, 24, 32, 40, 48, 56};
        const int offset = i;
        const int a0 = src[offset + idx[0]] + src[offset + idx[7]];
        const int a1 = src[offset + idx[0]] - src[offset + idx[7]];
        const int a2 = src[offset + idx[1]] + src[offset + idx[6]];
        const int a3 = src[offset + idx[1]] - src[offset + idx[6]];
        const int a4 = src[offset + idx[2]] + src[offset + idx[5]];
        const int a5 = src[offset + idx[2]] - src[offset + idx[5]];
        const int a6 = src[offset + idx[3]] + src[offset + idx[4]];
        const int a7 = src[offset + idx[3]] - src[offset + idx[4]];
        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;
        const int b4 = a3 + a5 + (a1 + (a1 >> 1));
        const int b5 = a1 - a7 - (a5 + (a5 >> 1));
        const int b6 = a1 + a7 - (a3 + (a3 >> 1));
        const int b7 = a3 - a5 + (a7 + (a7 >> 1));
        dst[offset + idx[0]] = (int16_t)(b0 + b1);
        dst[offset + idx[1]] = (int16_t)(b4 + (b7 >> 2));
        dst[offset + idx[2]] = (int16_t)(b2 + (b3 >> 1));
        dst[offset + idx[3]] = (int16_t)(b5 + (b6 >> 2));
        dst[offset + idx[4]] = (int16_t)(b0 - b1);
        dst[offset + idx[5]] = (int16_t)(b6 - (b5 >> 2));
        dst[offset + idx[6]] = (int16_t)((b2 >> 1) - b3);
        dst[offset + idx[7]] = (int16_t)((b4 >> 2) - b7);
    }
}
