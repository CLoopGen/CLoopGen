#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int coordmap[64];
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i += 4) {
    coordmap[i] = (i & 7) + (i / 8) * stride;
    coordmap[i+1] = ((i+1) & 7) + ((i+1) / 8) * stride;
    coordmap[i+2] = ((i+2) & 7) + ((i+2) / 8) * stride;
    coordmap[i+3] = ((i+3) & 7) + ((i+3) / 8) * stride;
}
}
