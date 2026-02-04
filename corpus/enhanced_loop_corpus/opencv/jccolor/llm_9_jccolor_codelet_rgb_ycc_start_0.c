#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= 127; i++) {
    INT32 scaled_i = i << 1;
    INT32 coeff_r = ((INT32)((0.29899999999999999) * (1L << 16) + 0.5));
    INT32 coeff_g1 = ((INT32)((0.58699999999999997) * (1L << 16) + 0.5));
    INT32 coeff_b = ((INT32)((0.114) * (1L << 16) + 0.5));
    INT32 offset = ((INT32)1 << (16 - 1));
    INT32 coeff_cb1 = ((INT32)((0.168735892) * (1L << 16) + 0.5));
    INT32 coeff_cb2 = ((INT32)((0.331264108) * (1L << 16) + 0.5));
    INT32 coeff_cr1 = ((INT32)((0.41868758900000003) * (1L << 16) + 0.5));
    INT32 coeff_cr2 = ((INT32)((0.081312411000000001) * (1L << 16) + 0.5));
    INT32 y_offset = ((INT32)128 << 16);

    rgb_ycc_tab[scaled_i + 0] = coeff_r * scaled_i;
    rgb_ycc_tab[scaled_i + 1 + 0] = coeff_r * (scaled_i + 1);
    rgb_ycc_tab[scaled_i + (1 * (255 + 1))] = coeff_g1 * scaled_i;
    rgb_ycc_tab[scaled_i + 1 + (1 * (255 + 1))] = coeff_g1 * (scaled_i + 1);
    rgb_ycc_tab[scaled_i + (2 * (255 + 1))] = coeff_b * scaled_i + offset;
    rgb_ycc_tab[scaled_i + 1 + (2 * (255 + 1))] = coeff_b * (scaled_i + 1) + offset;

    rgb_ycc_tab[scaled_i + (3 * (255 + 1))] = (-coeff_cb1) * scaled_i;
    rgb_ycc_tab[scaled_i + 1 + (3 * (255 + 1))] = (-coeff_cb1) * (scaled_i + 1);
    rgb_ycc_tab[scaled_i + (4 * (255 + 1))] = (-coeff_cb2) * scaled_i;
    rgb_ycc_tab[scaled_i + 1 + (4 * (255 + 1))] = (-coeff_cb2) * (scaled_i + 1);

    rgb_ycc_tab[scaled_i + (5 * (255 + 1))] = (scaled_i << (16 - 1)) + y_offset + offset - 1;
    rgb_ycc_tab[scaled_i + 1 + (5 * (255 + 1))] = ((scaled_i + 1) << (16 - 1)) + y_offset + offset - 1;

    rgb_ycc_tab[scaled_i + (6 * (255 + 1))] = (-coeff_cr1) * scaled_i;
    rgb_ycc_tab[scaled_i + 1 + (6 * (255 + 1))] = (-coeff_cr1) * (scaled_i + 1);
    rgb_ycc_tab[scaled_i + (7 * (255 + 1))] = (-coeff_cr2) * scaled_i;
    rgb_ycc_tab[scaled_i + 1 + (7 * (255 + 1))] = (-coeff_cr2) * (scaled_i + 1);
}
}
