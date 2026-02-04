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
        int r_val = (r * 51) & 255;
        int g_val = (g * 51) & 255;
        int base = (int)(((ssize_t)r_val << 16) + ((g_val << 8)));
        for (b = 0; b < 6; b++) {
            int b_val = (b * 51) & 255;
            sixel_palet[n++] = base + b_val;
        }
    }
}
}
