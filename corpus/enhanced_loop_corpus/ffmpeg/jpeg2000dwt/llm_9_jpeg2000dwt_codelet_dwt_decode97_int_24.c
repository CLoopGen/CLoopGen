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
    int stride = (w * h) / 2;
    for (i = 0; i < stride; i++) {
        data[i] *= 1LL << 8;
        data[w * h - 1 - i] *= 1LL << 8;
    }
    // Handle middle element if odd count
    if ((w * h) % 2 == 1) {
        data[stride] *= 1LL << 8;
    }
}
