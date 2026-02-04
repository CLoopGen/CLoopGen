#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t j;
extern unsigned char *colormap;
extern unsigned char *global_colormap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 384; j++) {
        global_colormap[2*j] = colormap[2*j];
        global_colormap[2*j + 1] = colormap[2*j + 1];
    }
}
