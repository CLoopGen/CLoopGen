#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Strided Memory Access with reversed loop order and base-offset addressing
    INT32 *tab = rgb_ycc_tab;
    const INT32 step = 255 + 1;
    const INT32 c0 = (INT32)(0.29899999999999999 * (1UL << 16) + 0.5);
    const INT32 c1 = (INT32)(0.58699999999999997 * (1UL << 16) + 0.5);
    const INT32 c2 = (INT32)(0.114 * (1UL << 16) + 0.5);
    const INT32 c3 = -(INT32)(0.16874 * (1UL << 16) + 0.5);
    const INT32 c4 = -(INT32)(0.33126 * (1UL << 16) + 0.5);
    const INT32 c5 = (INT32)(0.5 * (1UL << 16) + 0.5);
    const INT32 c6 = -(INT32)(0.41869000000000001 * (1UL << 16) + 0.5);
    const INT32 c7 = -(INT32)(0.081309999999999993 * (1UL << 16) + 0.5);
    const INT32 off2 = (INT32)1 << (16 - 1);
    const INT32 off5 = (INT32)(128 << 16) + (INT32)(1 << (16 - 1)) - 1;

    // Reverse iteration to modify access pattern
    for (i = 255; i >= 0; i--) {
        *(tab + 0 * step + i) = c0 * i;
        *(tab + 1 * step + i) = c1 * i;
        *(tab + 2 * step + i) = c2 * i + off2;
        *(tab + 3 * step + i) = c3 * i;
        *(tab + 4 * step + i) = c4 * i;
        *(tab + 5 * step + i) = c5 * i + off5;
        *(tab + 6 * step + i) = c6 * i;
        *(tab + 7 * step + i) = c7 * i;
    }
}
