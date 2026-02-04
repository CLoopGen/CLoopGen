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
    temp = 2 * i;
    coordmap[temp] = (temp & 7) + ((temp >> 3) * stride);
    coordmap[temp + 1] = ((temp + 1) & 7) + (((temp + 1) >> 3) * stride);
}
}
