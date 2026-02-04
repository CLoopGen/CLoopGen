#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int coordmap[64];
extern  int stride;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp[64];
    for (i = 0; i < 64; i++) {
        temp[i] = (i & 7) + (i >> 3) * stride;
    }
    for (i = 0; i < 64; i++) {
        coordmap[i] = temp[i];
    }
}
