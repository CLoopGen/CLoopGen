#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= 511; i++) {
    INT32 scaled_i = (i > 255) ? (511 - i) : i;
    INT32 base = scaled_i;
    INT32 coeff_r = ((INT32)(0.29899999999999999 * (1L << 16) + 0.5));
    INT32 coeff_g = ((INT32)(0.58699999999999997 * (1L << 16) + 0.5));
    INT32 coeff_b = ((INT32)(0.114 * (1L << 16) + 0.5));
    INT32 offset = ((INT32)1 << (16 - 1));
    INT32 chroma_offset = ((INT32)128 << 16) + offset - 1;

    rgb_ycc_tab[base + 0 * (255 + 1)] = coeff_r * base;
    rgb_ycc_tab[base + 1 * (255 + 1)] = coeff_g * base;
    rgb_ycc_tab[base + 2 * (255 + 1)] = coeff_b * base + offset;
    
    INT32 cb_factor1 = -((INT32)((0.16874) * (1L << 16) + 0.5));
    INT32 cb_factor2 = -((INT32)((0.33126) * (1L << 16) + 0.5));
    rgb_ycc_tab[base + 3 * (255 + 1)] = cb_factor1 * base;
    rgb_ycc_tab[base + 4 * (255 + 1)] = cb_factor2 * base;
    rgb_ycc_tab[base + 5 * (255 + 1)] = ((INT32)(0.5 * (1L << 16) + 0.5)) * base + chroma_offset;

    INT32 cr_factor1 = -((INT32)((0.41869000000000001) * (1L << 16) + 0.5));
    INT32 cr_factor2 = -((INT32)((0.081309999999999993) * (1L << 16) + 0.5));
    rgb_ycc_tab[base + 6 * (255 + 1)] = cr_factor1 * base;
    rgb_ycc_tab[base + 7 * (255 + 1)] = cr_factor2 * base;
}
}
