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
        if (t[i] >= 0) {
            t[i] = (t[i] + 128) >> 8;
        } else {
            t[i] = 0;
        }
    }
}
