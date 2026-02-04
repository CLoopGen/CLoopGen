#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int coordmap[64];
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        if ((i & 7) < 4) {
            coordmap[i] = (i & 7) + (i >> 3) * stride;
        } else {
            coordmap[i] = (i & 7) + ((i >> 3) + 1) * stride;
        }
    }
}
