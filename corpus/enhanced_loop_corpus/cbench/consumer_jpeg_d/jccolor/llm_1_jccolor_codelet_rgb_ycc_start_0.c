#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i <= 255; i += 2) { // Increase loop stride and nest inner loop to handle two iterations
        for (INT32 k = 0; k < 2; k++) {
            INT32 idx = i + k;
            if (idx > 255) break;
            rgb_ycc_tab[idx + 0] = ((INT32)((0.29899999999999999) * (1L << 16) + 0.5)) * idx;
            rgb_ycc_tab[idx + (1 * (255 + 1))] = ((INT32)((0.58699999999999997) * (1L << 16) + 0.5)) * idx;
            rgb_ycc_tab[idx + (2 * (255 + 1))] = ((INT32)((0.114) * (1L << 16) + 0.5)) * idx + ((INT32)1 << (16 - 1));
            rgb_ycc_tab[idx + (3 * (255 + 1))] = (-((INT32)((0.16874) * (1L << 16) + 0.5))) * idx;
            rgb_ycc_tab[idx + (4 * (255 + 1))] = (-((INT32)((0.33126) * (1L << 16) + 0.5))) * idx;
            rgb_ycc_tab[idx + (5 * (255 + 1))] = ((INT32)((0.5) * (1L << 16) + 0.5)) * idx + ((INT32)128 << 16) + ((INT32)1 << (16 - 1)) - 1;
            rgb_ycc_tab[idx + (6 * (255 + 1))] = (-((INT32)((0.41869000000000001) * (1L << 16) + 0.5))) * idx;
            rgb_ycc_tab[idx + (7 * (255 + 1))] = (-((INT32)((0.081309999999999993) * (1L << 16) + 0.5))) * idx;
        }
    }
}
