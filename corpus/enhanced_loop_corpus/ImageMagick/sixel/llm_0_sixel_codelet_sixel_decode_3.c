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
for (r = 0; r < 6; r++) {
    for (g = 0; g < 6; g++) {
        b = 0;
        sixel_palet[n++] = ((int)(((ssize_t)((r * 51) & 255) << 16) + (((g * 51) & 255) << 8) + ((b * 51) & 255)));
        b = 1;
        sixel_palet[n++] = ((int)(((ssize_t)((r * 51) & 255) << 16) + (((g * 51) & 255) << 8) + ((b * 51) & 255)));
        b = 2;
        sixel_palet[n++] = ((int)(((ssize_t)((r * 51) & 255) << 16) + (((g * 51) & 255) << 8) + ((b * 51) & 255)));
        b = 3;
        sixel_palet[n++] = ((int)(((ssize_t)((r * 51) & 255) << 16) + (((g * 51) & 255) << 8) + ((b * 51) & 255)));
        b = 4;
        sixel_palet[n++] = ((int)(((ssize_t)((r * 51) & 255) << 16) + (((g * 51) & 255) << 8) + ((b * 51) & 255)));
        b = 5;
        sixel_palet[n++] = ((int)(((ssize_t)((r * 51) & 255) << 16) + (((g * 51) & 255) << 8) + ((b * 51) & 255)));
    }
}
}
