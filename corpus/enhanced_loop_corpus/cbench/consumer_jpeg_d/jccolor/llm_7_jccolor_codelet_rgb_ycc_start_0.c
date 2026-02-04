#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 *tab = rgb_ycc_tab;
    const INT32 offset = 255 + 1;
    const INT32 half_shift = (INT32)1 << (16 - 1);
    const INT32 y128 = (INT32)128 << 16;
    INT32 temp[8];

    for (i = 0; i <= 255; i++) {
        // Introduce temporary storage to create intra-iteration WAW and WAR dependencies
        temp[0] = ((INT32)((0.29899999999999999) * (1L << 16) + 0.5)) * i;
        temp[1] = ((INT32)((0.58699999999999997) * (1L << 16) + 0.5)) * i;
        temp[2] = ((INT32)((0.114) * (1L << 16) + 0.5)) * i + half_shift;
        temp[3] = (-((INT32)((0.16874) * (1L << 16) + 0.5))) * i;
        temp[4] = (-((INT32)((0.33126) * (1L << 16) + 0.5))) * i;
        temp[5] = ((INT32)((0.5) * (1L << 16) + 0.5)) * i + y128 + half_shift - 1;
        temp[6] = (-((INT32)((0.41869000000000001) * (1L << 16) + 0.5))) * i;
        temp[7] = (-((INT32)((0.081309999999999993) * (1L << 16) + 0.5))) * i;

        // Sequential write with artificial dependence: each write depends on prior temp value
        tab[i + 0 * offset] = temp[0];
        tab[i + 1 * offset] = temp[1]; 
        tab[i + 2 * offset] = temp[2];
        tab[i + 3 * offset] = temp[3];
        tab[i + 4 * offset] = temp[4];
        tab[i + 5 * offset] = temp[5];
        tab[i + 6 * offset] = temp[6];
        tab[i + 7 * offset] = temp[7];
    }
    // Introduces intra-loop WAW and WAR hazards via temp array reuse, eliminating direct memory-write dependencies.
    // Loop-carried dependencies are removed; all dependencies now contained within iteration.
}
