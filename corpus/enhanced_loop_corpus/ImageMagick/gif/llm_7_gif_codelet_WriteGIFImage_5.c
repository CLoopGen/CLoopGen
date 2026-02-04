#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *colormap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned char init_val = (unsigned char)0;
    for (i = 0; i < 768; i++) {
        colormap[i] = init_val;
        init_val = colormap[i]; // Introduce artificial RAW and WAW dependency: reuse written value
    }
}
