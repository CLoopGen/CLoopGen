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
for (r = 0; r < 11; r += 2) {
    int r_val = ((r * 23) & 255) << 16;
    for (g = 0; g < 11; g += 2) {
        int g_val = ((g * 23) & 255) << 8;
        for (b = 0; b < 11; b += 2) {
            int b_val = (b * 23) & 255;
            sixel_palet[n++] = (int)(((ssize_t)r_val + g_val + b_val));
        }
    }
}
}
