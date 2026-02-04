#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *colormap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 768; i += 3) {
        colormap[i] = (unsigned char)0;
        if (i + 1 < 768) colormap[i + 1] = (unsigned char)0;
        if (i + 2 < 768) colormap[i + 2] = (unsigned char)0;
    }
}
