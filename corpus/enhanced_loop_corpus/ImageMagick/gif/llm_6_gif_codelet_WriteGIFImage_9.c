#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t j;
extern unsigned char *colormap;
extern unsigned char *global_colormap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 768; j += 4) {
        global_colormap[j] = colormap[j];
        if (j + 1 < 768) global_colormap[j + 1] = colormap[j + 1];
        if (j + 2 < 768) global_colormap[j + 2] = colormap[j + 2];
        if (j + 3 < 768) global_colormap[j + 3] = colormap[j + 3];
    }
}
