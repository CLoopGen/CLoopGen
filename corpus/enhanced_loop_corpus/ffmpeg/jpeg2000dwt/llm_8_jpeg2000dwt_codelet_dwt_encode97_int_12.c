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
    for (i = 0; i < w * h; i += 2) {
        if (i + 1 < w * h) {
            t[i] *= 1 << 8;
            t[i + 1] *= 1 << 8;
        } else {
            t[i] *= 1 << 8;
        }
    }
}
