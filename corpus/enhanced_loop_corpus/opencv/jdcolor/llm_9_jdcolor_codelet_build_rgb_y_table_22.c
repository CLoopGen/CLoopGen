#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern JLONG *rgb_y_tab;
extern JLONG i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    JLONG coeff_r = ((JLONG)((0.29899999999999999) * (1L << 16) + 0.5));
    JLONG coeff_g = ((JLONG)((0.58699999999999997) * (1L << 16) + 0.5));
    JLONG coeff_b = ((JLONG)((0.114) * (1L << 16) + 0.5));
    JLONG offset = ((JLONG)1 << (16 - 1));
    JLONG base1 = 1 * (255 + 1);
    JLONG base2 = 2 * (255 + 1);

    for (i = 0; i <= 127; i++) {
        JLONG temp_r = coeff_r * i;
        JLONG temp_g = coeff_g * i;
        JLONG temp_b = coeff_b * i + offset;

        rgb_y_tab[i] = temp_r;
        rgb_y_tab[i + 128] = coeff_r * (i + 128);

        rgb_y_tab[i + base1] = temp_g;
        rgb_y_tab[i + 128 + base1] = coeff_g * (i + 128);

        rgb_y_tab[i + base2] = temp_b;
        rgb_y_tab[i + 128 + base2] = coeff_b * (i + 128) + offset;
    }
}
