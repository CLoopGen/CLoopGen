#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern JLONG *rgb_y_tab;
extern JLONG i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive Memory Access (flattened indexing with sequential write order)
    JLONG coef_r = (JLONG)((0.29899999999999999) * (1L << 16) + 0.5);
    JLONG coef_g = (JLONG)((0.58699999999999997) * (1L << 16) + 0.5);
    JLONG coef_b = (JLONG)((0.114) * (1L << 16) + 0.5);
    JLONG offset = (JLONG)1 << (16 - 1);
    for (i = 0; i <= 255; i++) {
        rgb_y_tab[i]                     = coef_r * i;
        rgb_y_tab[i + (255 + 1)]         = coef_g * i;
        rgb_y_tab[i + 2*(255 + 1)]       = coef_b * i + offset;
    }
}
