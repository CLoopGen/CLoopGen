#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *colormap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 256; i++) {
        colormap[i] = (unsigned char)0;
        colormap[i + 256] = (unsigned char)0;
        colormap[i + 512] = (unsigned char)0;
    }
}
