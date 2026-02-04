#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern JLONG *rgb_y_tab;
extern JLONG i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i += 2) {
        JLONG coeff_r = ((JLONG)((0.29899999999999999) * (1L << 16) + 0.5));
        JLONG coeff_g = ((JLONG)((0.58699999999999997) * (1L << 16) + 0.5));
        JLONG coeff_b = ((JLONG)((0.114) * (1L << 16) + 0.5));
        JLONG offset = ((JLONG)1 << (16 - 1));

        rgb_y_tab[i + 0] = coeff_r * i;
        if (i + 1 <= 255) {
            rgb_y_tab[i + 1] = coeff_r * (i + 1);
        }

        rgb_y_tab[i + (1 * (255 + 1))] = coeff_g * i;
        if (i + 1 <= 255) {
            rgb_y_tab[i + 1 + (1 * (255 + 1))] = coeff_g * (i + 1);
        }

        rgb_y_tab[i + (2 * (255 + 1))] = coeff_b * i + offset;
        if (i + 1 <= 255) {
            rgb_y_tab[i + 1 + (2 * (255 + 1))] = coeff_b * (i + 1) + offset;
        }
    }
}
