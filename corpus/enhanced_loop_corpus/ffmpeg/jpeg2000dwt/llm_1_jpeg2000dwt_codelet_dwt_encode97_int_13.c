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
    for (int stride = 0; stride < w * h; stride += 4) {
        for (int offset = 0; offset < 4 && (stride + offset) < w * h; offset++) {
            int i = stride + offset;
            t[i] = (t[i] + ((1 << 8) >> 1)) >> 8;
        }
    }
}
