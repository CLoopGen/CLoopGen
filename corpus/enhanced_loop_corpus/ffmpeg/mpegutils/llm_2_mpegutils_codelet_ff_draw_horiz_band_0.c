#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int offset[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    for (int i = 0; i < 8; i += 2)
        offset[i] = 0;
    for (int i = 1; i < 8; i += 2)
        offset[i] = 0;
}
