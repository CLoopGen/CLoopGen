#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Consecutive Memory Access Pattern
    // Instead of strided access with spacing of (255 + 1), we reorganize the data to be written consecutively.
    // This improves spatial locality and cache performance.
    INT32 *tab = rgb_ycc_tab;
    for (i = 0; i <= 255; i++) {
        INT32 scale_i = i;
        tab[0] = ((INT32)((0.29899999999999999) * (1L << 16) + 0.5)) * scale_i;
        tab[1] = ((INT32)((0.58699999999999997) * (1L << 16) + 0.5)) * scale_i;
        tab[2] = ((INT32)((0.114) * (1L << 16) + 0.5)) * scale_i + ((INT32)1 << (16 - 1));
        tab[3] = (-((INT32)((0.168735892) * (1L << 16) + 0.5))) * scale_i;
        tab[4] = (-((INT32)((0.331264108) * (1L << 16) + 0.5))) * scale_i;
        tab[5] = (scale_i << (16 - 1)) + ((INT32)128 << 16) + ((INT32)1 << (16 - 1)) - 1;
        tab[6] = (-((INT32)((0.41868758900000003) * (1L << 16) + 0.5))) * scale_i;
        tab[7] = (-((INT32)((0.081312411000000001) * (1L << 16) + 0.5))) * scale_i;
        tab += 8; // Move to next consecutive block for next i
    }
}
