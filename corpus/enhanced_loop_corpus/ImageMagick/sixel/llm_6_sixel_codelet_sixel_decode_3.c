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
        for (b = 0; b < 6; b++) {
            int red = (r * 51) & 255;
            int green = (g * 51) & 255;
            int blue = (b * 51) & 255;
            sixel_palet[n] = ((int)(((ssize_t)red << 16) + (green << 8) + blue));
            n++;
        }
    }
}
}
