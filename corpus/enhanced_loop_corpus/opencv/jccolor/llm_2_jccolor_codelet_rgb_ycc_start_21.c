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
        JLONG idx = i;
        rgb_ycc_tab[idx + 0 * 256] = ((JLONG)((0.29899999999999999) * (1L << 16) + 0.5)) * i;
        rgb_ycc_tab[idx + 1 * 256] = ((JLONG)((0.58699999999999997) * (1L << 16) + 0.5)) * i;
        rgb_ycc_tab[idx + 2 * 256] = ((JLONG)((0.114) * (1L << 16) + 0.5)) * i + ((JLONG)1 << (16 - 1));
        rgb_ycc_tab[idx + 3 * 256] = (-((JLONG)((0.16874) * (1L << 16) + 0.5))) * i;
        rgb_ycc_tab[idx + 4 * 256] = (-((JLONG)((0.33126) * (1L << 16) + 0.5))) * i;
        rgb_ycc_tab[idx + 5 * 256] = ((JLONG)((0.5) * (1L << 16) + 0.5)) * i + ((JLONG)128 << 16) + ((JLONG)1 << (16 - 1)) - 1;
        rgb_ycc_tab[idx + 6 * 256] = (-((JLONG)((0.41869000000000001) * (1L << 16) + 0.5))) * i;
        rgb_ycc_tab[idx + 7 * 256] = (-((JLONG)((0.081309999999999993) * (1L << 16) + 0.5))) * i;
    }
}
