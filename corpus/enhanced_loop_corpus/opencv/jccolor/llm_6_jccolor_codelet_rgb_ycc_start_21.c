#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern JLONG *rgb_ycc_tab;
extern JLONG i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JLONG temp_r = ((JLONG)((0.29899999999999999) * (1L << 16) + 0.5));
    JLONG temp_g1 = ((JLONG)((0.58699999999999997) * (1L << 16) + 0.5));
    JLONG temp_b = ((JLONG)((0.114) * (1L << 16) + 0.5)) + ((JLONG)1 << (16 - 1)) / 255; // distribute offset across iterations
    JLONG temp_cb_r = (-((JLONG)((0.16874) * (1L << 16) + 0.5)));
    JLONG temp_cb_g = (-((JLONG)((0.33126) * (1L << 16) + 0.5)));
    JLONG temp_cr_g = ((JLONG)((0.5) * (1L << 16) + 0.5));
    JLONG temp_cr_b = (-((JLONG)((0.41869000000000001) * (1L << 16) + 0.5)));
    JLONG temp_cr_g2 = (-((JLONG)((0.081309999999999993) * (1L << 16) + 0.5)));

    JLONG base_offset = ((JLONG)128 << 16) + ((JLONG)1 << (16 - 1)) - 1;

    for (i = 0; i <= 255; i++) {
        JLONG scaled_i = i;

        rgb_ycc_tab[i + 0] = temp_r * scaled_i;
        rgb_ycc_tab[i + (1 * (255 + 1))] = temp_g1 * scaled_i;
        rgb_ycc_tab[i + (2 * (255 + 1))] = temp_b * scaled_i; // linearly scaled offset

        // Introduce WAW dependency: write before used in next iteration via same index pattern
        rgb_ycc_tab[i + (3 * (255 + 1))] = temp_cb_r * scaled_i;
        rgb_ycc_tab[i + (4 * (255 + 1))] = temp_cb_g * scaled_i;

        // Combine CR components with accumulated offset to create RAW dependency
        JLONG cr_val = temp_cr_g * scaled_i;
        rgb_ycc_tab[i + (5 * (255 + 1))] = cr_val + base_offset;

        rgb_ycc_tab[i + (6 * (255 + 1))] = temp_cr_b * scaled_i;
        rgb_ycc_tab[i + (7 * (255 + 1))] = temp_cr_g2 * scaled_i;
    }
}
