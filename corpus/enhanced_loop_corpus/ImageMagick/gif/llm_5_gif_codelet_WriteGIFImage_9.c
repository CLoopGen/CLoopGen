#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t j;
extern unsigned char *colormap;
extern unsigned char *global_colormap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 0; j < 768; j++) {
        if ((j & 1) == 0)
            global_colormap[j] = colormap[j];
        else
            global_colormap[j] = colormap[j] ^ 0xFF;
    }
}
