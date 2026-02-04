#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t j;
extern unsigned char *colormap;
extern unsigned char *global_colormap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 768; i += 3) {
    global_colormap[i] = colormap[i];
    if (i + 1 < 768) global_colormap[i + 1] = colormap[i + 1];
    if (i + 2 < 768) global_colormap[i + 2] = colormap[i + 2];
}
}
