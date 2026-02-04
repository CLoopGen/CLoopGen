#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *q;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then offset)
    int stride = 2;
    for (i = 0; i < ni; i += stride)
        left[i] = q[i];
    for (i = 1; i < ni; i += stride)
        left[i] = q[i];
}
