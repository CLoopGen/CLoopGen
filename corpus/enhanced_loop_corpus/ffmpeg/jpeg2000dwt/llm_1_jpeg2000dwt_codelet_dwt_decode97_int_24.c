#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern int h;
extern int i;
extern int32_t *data;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int block = 0; block < h; block++) {
        int base = block * w;
        for (int offset = 0; offset < w; offset++) {
            data[base + offset] *= 1LL << 8;
        }
    }
}
