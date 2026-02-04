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
    unsigned char *pal = *palette;
    int *src = sixel_palet;
    for (n = 0; n < (ssize_t)*ncolors; ++n) {
        unsigned int color = src[n];
        pal[4*n + 0] = (color >> 16) & 255;
        pal[4*n + 3] = 255;
        pal[4*n + 1] = (color >> 8) & 255;
        pal[4*n + 2] = color & 255;
    }
}
