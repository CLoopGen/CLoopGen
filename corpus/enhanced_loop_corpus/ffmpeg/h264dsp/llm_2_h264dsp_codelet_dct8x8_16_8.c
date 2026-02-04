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
        int16_t *base = coef + i;
        int16_t *dst = tmp + i;
        const int a0 = base[0] + base[56];
        const int a1 = base[0] - base[56];
        const int a2 = base[8] + base[48];
        const int a3 = base[8] - base[48];
        const int a4 = base[16] + base[40];
        const int a5 = base[16] - base[40];
        const int a6 = base[24] + base[32];
        const int a7 = base[24] - base[32];
        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;
        const int b4 = a3 + a5 + (a1 + (a1 >> 1));
        const int b5 = a1 - a7 - (a5 + (a5 >> 1));
        const int b6 = a1 + a7 - (a3 + (a3 >> 1));
        const int b7 = a3 - a5 + (a7 + (a7 >> 1));
        dst[0] = (int16_t)(b0 + b1);
        dst[8] = (int16_t)(b4 + (b7 >> 2));
        dst[16] = (int16_t)(b2 + (b3 >> 1));
        dst[24] = (int16_t)(b5 + (b6 >> 2));
        dst[32] = (int16_t)(b0 - b1);
        dst[40] = (int16_t)(b6 - (b5 >> 2));
        dst[48] = (int16_t)((b2 >> 1) - b3);
        dst[56] = (int16_t)((b4 >> 2) - b7);
    }
}
