#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 *tab = rgb_ycc_tab;
    for (i = 0; i <= 255; i++) {
        INT32 idx = i << 3; // Stride of 8 elements between consecutive writes
        tab[idx + 0] = ((INT32)((0.29899999999999999) * (1L << 16) + 0.5)) * i;
        tab[idx + 1] = ((INT32)((0.58699999999999997) * (1L << 16) + 0.5)) * i;
        tab[idx + 2] = ((INT32)((0.114) * (1L << 16) + 0.5)) * i + ((INT32)1 << (16 - 1));
        tab[idx + 3] = (-((INT32)((0.16874) * (1L << 16) + 0.5))) * i;
        tab[idx + 4] = (-((INT32)((0.33126) * (1L << 16) + 0.5))) * i;
        tab[idx + 5] = ((INT32)((0.5) * (1L << 16) + 0.5)) * i + ((INT32)128 << 16) + ((INT32)1 << (16 - 1)) - 1;
        tab[idx + 6] = (-((INT32)((0.41869000000000001) * (1L << 16) + 0.5))) * i;
        tab[idx + 7] = (-((INT32)((0.081309999999999993) * (1L << 16) + 0.5))) * i;
    }
}
