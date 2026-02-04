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
    int *indices = (int*)alloca(w * sizeof(int));
    for (int j = 0; j < w; ++j) {
        indices[j] = w - 1 - j; // reverse access pattern
    }
    for (i = 0; i < w; ++i) {
        pixels[indices[i]] = color;
    }
}
