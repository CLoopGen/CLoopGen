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
    int limit = w * h;
    for (i = 0; i < limit; i += 2) {
        if (i < limit) {
            t[i] = (t[i] + 128) >> 8;
        }
        if (i + 1 < limit) {
            t[i + 1] = (t[i + 1] + 128) >> 8;
        }
    }
}
