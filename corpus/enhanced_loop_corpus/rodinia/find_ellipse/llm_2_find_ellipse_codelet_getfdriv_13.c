#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *bindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    int stride = 2;
    for (i = 0; i < N; i += stride)
        bindex[i] = i;
    for (i = 1; i < N; i += stride)
        bindex[i] = i;
}
