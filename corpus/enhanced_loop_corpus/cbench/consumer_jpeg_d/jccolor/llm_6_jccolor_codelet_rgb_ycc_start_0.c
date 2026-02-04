#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 *tab = rgb_ycc_tab;
    const INT32 c0 = (INT32)((0.29899999999999999) * (1L << 16) + 0.5);
    const INT32 c1 = (INT32)((0.58699999999999997) * (1L << 16) + 0.5);
    const INT32 c2 = (INT32)((0.114) * (1L << 16) + 0.5);
    const INT32 c3 = (INT32)((0.16874) * (1L << 16) + 0.5);
    const INT32 c4 = (INT32)((0.33126) * (1L << 16) + 0.5);
    const INT32 c5 = (INT32)((0.5) * (1L << 16) + 0.5);
    const INT32 c6 = (INT32)((0.41869000000000001) * (1L << 16) + 0.5);
    const INT32 c7 = (INT32)((0.081309999999999993) * (1L << 16) + 0.5);
    const INT32 offset = 255 + 1;
    const INT32 half_shift = (INT32)1 << (16 - 1);
    const INT32 y128 = (INT32)128 << 16;

    for (i = 0; i <= 255; i++) {
        INT32 idx = i;
        tab[idx + 0 * offset] = c0 * i;
        tab[idx + 1 * offset] = c1 * i;
        tab[idx + 2 * offset] = c2 * i + half_shift;
        tab[idx + 3 * offset] = (-c3) * i;
        tab[idx + 4 * offset] = (-c4) * i;
        tab[idx + 5 * offset] = c5 * i + y128 + half_shift - 1;
        tab[idx + 6 * offset] = (-c6) * i;
        tab[idx + 7 * offset] = (-c7) * i;
    }
}
