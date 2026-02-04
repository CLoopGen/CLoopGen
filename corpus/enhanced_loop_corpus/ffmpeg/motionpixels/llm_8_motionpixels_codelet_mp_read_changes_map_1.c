#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t *pixels;
extern int w;
extern int color;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    for (i = 0; i < w; i += stride) {
        pixels[i] = color;
        if (i + 1 < w)
            pixels[i + 1] = color;
    }
}
