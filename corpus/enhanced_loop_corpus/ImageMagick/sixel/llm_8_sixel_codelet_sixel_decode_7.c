#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char **palette;
extern size_t *ncolors;
extern int n;
extern int sixel_palet[1024];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < (ssize_t)*ncolors; ++n) {
        uint32_t color = sixel_palet[n];
        (*palette)[n * 4 + 0] = (color >> 16) & 255;
        (*palette)[n * 4 + 1] = (color >> 8) & 255;
        (*palette)[n * 4 + 2] = color & 255;
        (*palette)[n * 4 + 3] = 255;
    }
}
