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
    for (i = 0; i < w * h; i++) {
        int val = t[i];
        if (val != 0) {
            t[i] = (val + 128) >> 8;
        }
    }
}
