#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access pattern using an array with stride of 4
    int data[60];
    for (; idx < 60; idx += 4) {
        register unsigned int v = data[idx];
        unsigned int g = v & 4278255360U;
        v &= 16711935;
        data[idx] = v;
    }
}
