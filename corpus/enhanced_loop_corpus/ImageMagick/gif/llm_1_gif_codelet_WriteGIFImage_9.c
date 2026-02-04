#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern ssize_t j;
extern unsigned char *colormap;
extern unsigned char *global_colormap;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int block = 0; block < 768; block += 64) {
    for (int j = block; j < block + 64 && j < 768; j++) {
        global_colormap[j] = colormap[j];
    }
}
}
