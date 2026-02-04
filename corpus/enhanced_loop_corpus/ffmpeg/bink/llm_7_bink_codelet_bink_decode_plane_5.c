#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int coordmap[64];
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    coordmap[0] = 0 + 0 * stride;
    for (i = 1; i < 64; i++) {
        coordmap[i] = coordmap[i-1] + ((i & 7) - ((i-1) & 7)) + (((i >> 3) - ((i-1) >> 3)) * stride);
    }
}
