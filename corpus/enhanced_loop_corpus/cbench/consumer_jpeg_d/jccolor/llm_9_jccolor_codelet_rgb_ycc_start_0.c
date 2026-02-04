#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i++) {
        const INT32 shift = 16;
        const INT32 round = 0.5;
        const INT32 Y_r = (INT32)(0.29899999999999999 * (1L << shift) + round);
        const INT32 Y_g = (INT32)(0.58699999999999997 * (1L << shift) + round);
        const INT32 Y_b = (INT32)(0.114 * (1L << shift) + round);
        const INT32 U_r = (INT32)(0.16874 * (1L << shift) + round);
        const INT32 U_g = (INT32)(0.33126 * (1L << shift) + round);
        const INT32 V_g = (INT32)(0.41869000000000001 * (1L << shift) + round);
        const INT32 V_b = (INT32)(0.081309999999999993 * (1L << shift) + round);

        rgb_ycc_tab[i + 0] = Y_r * i;
        rgb_ycc_tab[i + (1 * (255 + 1))] = Y_g * i;
        rgb_ycc_tab[i + (2 * (255 + 1))] = Y_b * i + (1 << (shift - 1));
        rgb_ycc_tab[i + (3 * (255 + 1))] = (-U_r) * i;
        rgb_ycc_tab[i + (4 * (255 + 1))] = (-U_g) * i;
        rgb_ycc_tab[i + (5 * (255 + 1))] = (1 << (shift - 1)) * i + (128 << shift) + (1 << (shift - 1)) - 1;
        rgb_ycc_tab[i + (6 * (255 + 1))] = (-V_g) * i;
        rgb_ycc_tab[i + (7 * (255 + 1))] = (-V_b) * i;

        // Additional computational load: simulate auxiliary processing with no side effects
        volatile INT32 dummy = 0;
        for (INT32 j = 0; j < 4; j++) {
            dummy += (Y_r + Y_g + Y_b) * (U_r - V_g);
        }
    }
}
