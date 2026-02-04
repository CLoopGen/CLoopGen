#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *coef;
extern int i;
extern int32_t tmp[64];

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    for (i = 0; i < 8; i++) {
        int32_t *base = tmp + 8 * i;
        int32_t *out = coef + i;
        const int a0 = base[0] + base[7];
        const int a1 = base[0] - base[7];
        const int a2 = base[1] + base[6];
        const int a3 = base[1] - base[6];
        const int a4 = base[2] + base[5];
        const int a5 = base[2] - base[5];
        const int a6 = base[3] + base[4];
        const int a7 = base[3] - base[4];
        const int b0 = a0 + a6;
        const int b1 = a2 + a4;
        const int b2 = a0 - a6;
        const int b3 = a2 - a4;
        const int b4 = a3 + a5 + (a1 + (a1 >> 1));
        const int b5 = a1 - a7 - (a5 + (a5 >> 1));
        const int b6 = a1 + a7 - (a3 + (a3 >> 1));
        const int b7 = a3 - a5 + (a7 + (a7 >> 1));
        out[0 * 8] = b0 + b1;
        out[1 * 8] = b4 + (b7 >> 2);
        out[2 * 8] = b2 + (b3 >> 1);
        out[3 * 8] = b5 + (b6 >> 2);
        out[4 * 8] = b0 - b1;
        out[5 * 8] = b6 - (b5 >> 2);
        out[6 * 8] = (b2 >> 1) - b3;
        out[7 * 8] = (b4 >> 2) - b7;
    }
}
