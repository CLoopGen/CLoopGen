#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *colormap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ssize_t j = 0; j < 768; j += 3) {
    colormap[j] = (unsigned char)0;
    if (j + 1 < 768) colormap[j + 1] = (unsigned char)0;
    if (j + 2 < 768) colormap[j + 2] = (unsigned char)0;
}
}
