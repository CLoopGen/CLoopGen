#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *t;
extern int w;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = (w >> 1) + 1;
    for (i = 0; i < w * h; i += stride) {
        t[i % (w * h)] *= 1 << 10;
    }
}
