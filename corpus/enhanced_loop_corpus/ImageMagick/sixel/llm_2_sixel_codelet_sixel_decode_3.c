#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int b;
extern int g;
extern int n;
extern int r;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Memory Access Pattern Modification - Strided Access
    // Instead of incrementing n consecutively, write to every 4th position (strided access)
    // This simulates a scenario where memory is not accessed contiguously.
    int stride = 4;
    for (r = 0; r < 6; r++) {
        for (g = 0; g < 6; g++) {
            for (b = 0; b < 6; b++) {
                sixel_palet[n * stride] = ((int)(((ssize_t)((r * 51) & 255) << 16) + (((g * 51) & 255) << 8) + ((b * 51) & 255)));
                n++;
            }
        }
    }
}
