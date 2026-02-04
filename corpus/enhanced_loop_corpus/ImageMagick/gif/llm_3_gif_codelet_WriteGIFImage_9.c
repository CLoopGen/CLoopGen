#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t j;
extern unsigned char *colormap;
extern unsigned char *global_colormap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Strided access with reverse traversal in chunks of 4
    for (j = 0; j < 192; j++) {
        ptrdiff_t base = j * 4;
        global_colormap[base + 0] = colormap[base + 0];
        global_colormap[base + 1] = colormap[base + 1];
        global_colormap[base + 2] = colormap[base + 2];
        global_colormap[base + 3] = colormap[base + 3];
    }
}
