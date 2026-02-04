#include <stdio.h>

#include <inttypes.h>

extern void **pt;
extern void *tt[8];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolled to handle boundary
    for (i = 0; i < 8; i += 2)
        tt[i] = pt[i];
    for (i = 1; i < 8; i += 2)
        tt[i] = pt[i];
}
