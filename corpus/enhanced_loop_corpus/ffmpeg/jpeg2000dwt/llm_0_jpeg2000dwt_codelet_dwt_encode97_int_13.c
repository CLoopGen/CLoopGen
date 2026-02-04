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
    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            int i = row * w + col;
            t[i] = (t[i] + ((1 << 8) >> 1)) >> 8;
        }
    }
}
