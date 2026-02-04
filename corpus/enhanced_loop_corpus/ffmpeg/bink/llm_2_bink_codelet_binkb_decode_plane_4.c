#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int coordmap[64];
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i += 8) {
        coordmap[i + 0] = (i & 7) + (i >> 3) * stride;
        coordmap[i + 1] = ((i+1) & 7) + ((i+1) >> 3) * stride;
        coordmap[i + 2] = ((i+2) & 7) + ((i+2) >> 3) * stride;
        coordmap[i + 3] = ((i+3) & 7) + ((i+3) >> 3) * stride;
        coordmap[i + 4] = ((i+4) & 7) + ((i+4) >> 3) * stride;
        coordmap[i + 5] = ((i+5) & 7) + ((i+5) >> 3) * stride;
        coordmap[i + 6] = ((i+6) & 7) + ((i+6) >> 3) * stride;
        coordmap[i + 7] = ((i+7) & 7) + ((i+7) >> 3) * stride;
    }
}
