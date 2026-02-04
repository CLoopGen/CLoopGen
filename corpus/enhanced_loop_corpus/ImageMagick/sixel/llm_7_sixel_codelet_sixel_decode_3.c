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
int temp_n = n;
for (r = 0; r < 6; r++) {
    for (g = 0; g < 6; g++) {
        for (b = 0; b < 6; b++) {
            int pixel = ((int)(((ssize_t)((r * 51) & 255) << 16) + (((g * 51) & 255) << 8) + ((b * 51) & 255)));
            sixel_palet[temp_n++] = pixel;
        }
    }
}
n = temp_n;
}
