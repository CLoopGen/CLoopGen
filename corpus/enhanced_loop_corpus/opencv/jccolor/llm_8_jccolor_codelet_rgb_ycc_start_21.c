#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern JLONG *rgb_ycc_tab;
extern JLONG i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i += 2) {
        JLONG val = i;
        JLONG val_next = i + 1;
        JLONG coef0 = ((JLONG)((0.29899999999999999) * (1L << 16) + 0.5));
        JLONG coef1 = ((JLONG)((0.58699999999999997) * (1L << 16) + 0.5));
        JLONG coef2 = ((JLONG)((0.114) * (1L << 16) + 0.5));
        JLONG coef3 = ((JLONG)((0.16874) * (1L << 16) + 0.5));
        JLONG coef4 = ((JLONG)((0.33126) * (1L << 16) + 0.5));
        JLONG coef5 = ((JLONG)((0.5) * (1L << 16) + 0.5));
        JLONG coef6 = ((JLONG)((0.41869000000000001) * (1L << 16) + 0.5));
        JLONG coef7 = ((JLONG)((0.081309999999999993) * (1L << 16) + 0.5));
        JLONG offset = (JLONG)1 << (16 - 1);
        JLONG const_term = ((JLONG)128 << 16) + offset - 1;

        rgb_ycc_tab[val + 0] = coef0 * val;
        rgb_ycc_tab[val + (1 * (255 + 1))] = coef1 * val;
        rgb_ycc_tab[val + (2 * (255 + 1))] = coef2 * val + offset;
        rgb_ycc_tab[val + (3 * (255 + 1))] = (-coef3) * val;
        rgb_ycc_tab[val + (4 * (255 + 1))] = (-coef4) * val;
        rgb_ycc_tab[val + (5 * (255 + 1))] = coef5 * val + const_term;
        rgb_ycc_tab[val + (6 * (255 + 1))] = (-coef6) * val;
        rgb_ycc_tab[val + (7 * (255 + 1))] = (-coef7) * val;

        if (val_next <= 255) {
            rgb_ycc_tab[val_next + 0] = coef0 * val_next;
            rgb_ycc_tab[val_next + (1 * (255 + 1))] = coef1 * val_next;
            rgb_ycc_tab[val_next + (2 * (255 + 1))] = coef2 * val_next + offset;
            rgb_ycc_tab[val_next + (3 * (255 + 1))] = (-coef3) * val_next;
            rgb_ycc_tab[val_next + (4 * (255 + 1))] = (-coef4) * val_next;
            rgb_ycc_tab[val_next + (5 * (255 + 1))] = coef5 * val_next + const_term;
            rgb_ycc_tab[val_next + (6 * (255 + 1))] = (-coef6) * val_next;
            rgb_ycc_tab[val_next + (7 * (255 + 1))] = (-coef7) * val_next;
        }
    }
}
