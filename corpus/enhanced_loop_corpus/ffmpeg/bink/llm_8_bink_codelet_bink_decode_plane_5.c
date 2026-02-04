#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int coordmap[64];
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int temp;
for (i = 0; i < 32; i++) {
    temp = i << 3;
    coordmap[temp]     = (i & 7) + (i >> 3) * stride;
    coordmap[temp + 1] = ((i + 1) & 7) + ((i + 1) >> 3) * stride;
    coordmap[temp + 2] = ((i + 2) & 7) + ((i + 2) >> 3) * stride;
    coordmap[temp + 3] = ((i + 3) & 7) + ((i + 3) >> 3) * stride;
    coordmap[temp + 4] = ((i + 4) & 7) + ((i + 4) >> 3) * stride;
    coordmap[temp + 5] = ((i + 5) & 7) + ((i + 5) >> 3) * stride;
    coordmap[temp + 6] = ((i + 6) & 7) + ((i + 6) >> 3) * stride;
    coordmap[temp + 7] = ((i + 7) & 7) + ((i + 7) >> 3) * stride;
}
}
