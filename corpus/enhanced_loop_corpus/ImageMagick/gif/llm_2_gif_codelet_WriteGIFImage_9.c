#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t j;
extern unsigned char *colormap;
extern unsigned char *global_colormap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    ptrdiff_t stride = 3;
    for (j = 0; j < 768; j += stride) {
        for (ptrdiff_t s = 0; s < stride && (j + s) < 768; s++) {
            global_colormap[j + s] = colormap[j + s];
        }
    }
}
