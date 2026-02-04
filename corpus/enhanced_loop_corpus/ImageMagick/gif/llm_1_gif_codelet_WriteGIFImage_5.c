#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t i;
extern unsigned char *colormap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ssize_t j = 0; j < 256; j++) {
    for (ssize_t k = 0; k < 3; k++) {
        colormap[3 * j + k] = (unsigned char)0;
    }
}
}
