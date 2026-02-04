#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access (flatten indexing with pointer arithmetic)
    INT32 *tab = rgb_ycc_tab;
    INT32 stride = 255 + 1;
    INT32 coef0 = ((INT32)((0.29899999999999999) * (1L << 16) + 0.5));
    INT32 coef1 = ((INT32)((0.58699999999999997) * (1L << 16) + 0.5));
    INT32 coef2 = ((INT32)((0.114) * (1L << 16) + 0.5));
    INT32 coef3 = -((INT32)((0.16874) * (1L << 16) + 0.5));
    INT32 coef4 = -((INT32)((0.33126) * (1L << 16) + 0.5));
    INT32 coef5 = ((INT32)((0.5) * (1L << 16) + 0.5));
    INT32 coef6 = -((INT32)((0.41869000000000001) * (1L << 16) + 0.5));
    INT32 coef7 = -((INT32)((0.081309999999999993) * (1L << 16) + 0.5));
    INT32 offset2 = ((INT32)1 << (16 - 1));
    INT32 offset5 = ((INT32)128 << 16) + ((INT32)1 << (16 - 1)) - 1;

    for (i = 0; i <= 255; i++) {
        tab[i + 0 * stride] = coef0 * i;
        tab[i + 1 * stride] = coef1 * i;
        tab[i + 2 * stride] = coef2 * i + offset2;
        tab[i + 3 * stride] = coef3 * i;
        tab[i + 4 * stride] = coef4 * i;
        tab[i + 5 * stride] = coef5 * i + offset5;
        tab[i + 6 * stride] = coef6 * i;
        tab[i + 7 * stride] = coef7 * i;
    }
}
