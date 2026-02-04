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
    // Variant 1: Strided memory access with stride of 4
    for (i = 0; i < w * h; i += 4) {
        if (i + 0 < w * h) data[i + 0] *= 1LL << 8;
        if (i + 1 < w * h) data[i + 1] *= 1LL << 8;
        if (i + 2 < w * h) data[i + 2] *= 1LL << 8;
        if (i + 3 < w * h) data[i + 3] *= 1LL << 8;
    }
}
