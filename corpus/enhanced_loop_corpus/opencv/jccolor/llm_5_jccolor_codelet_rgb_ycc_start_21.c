#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long JLONG;

extern JLONG *rgb_ycc_tab;
extern JLONG i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i <= 255; i++) {
    const JLONG offset = 255 + 1;
    const JLONG shift = 1L << 16;
    const JLONG half = 1L << (16 - 1);

    if (i % 2 == 0) {
        rgb_ycc_tab[i + 0] = ((JLONG)(0.299 * shift + 0.5)) * i;
        rgb_ycc_tab[i + (1 * offset)] = ((JLONG)(0.587 * shift + 0.5)) * i;
    } else {
        continue;
    }

    rgb_ycc_tab[i + (2 * offset)] = ((JLONG)(0.114 * shift + 0.5)) * i + half;

    if (i > 64) {
        rgb_ycc_tab[i + (3 * offset)] = (-((JLONG)(0.16874 * shift + 0.5))) * i;
        rgb_ycc_tab[i + (4 * offset)] = (-((JLONG)(0.33126 * shift + 0.5))) * i;
    }

    rgb_ycc_tab[i + (5 * offset)] = ((JLONG)(0.5 * shift + 0.5)) * i + ((JLONG)128 << 16) + half - 1;

    if (i < 192) {
        rgb_ycc_tab[i + (6 * offset)] = (-((JLONG)(0.41869 * shift + 0.5))) * i;
        rgb_ycc_tab[i + (7 * offset)] = (-((JLONG)(0.08131 * shift + 0.5))) * i;
    }
}
}
