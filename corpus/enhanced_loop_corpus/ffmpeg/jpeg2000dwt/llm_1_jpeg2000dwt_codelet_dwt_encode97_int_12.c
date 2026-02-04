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
    for (int stride = 0; stride < w * h; stride += 16) {
        for (int i = stride; i < stride + 16 && i < w * h; i++) {
            t[i] *= 1 << 8;
        }
    }
}
