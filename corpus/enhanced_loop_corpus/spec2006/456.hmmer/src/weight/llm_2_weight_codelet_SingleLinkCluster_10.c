#include <stdio.h>

#include <inttypes.h>

extern int nseq;
extern int *a;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < nseq; i += 2)
        a[i] = i;
}
