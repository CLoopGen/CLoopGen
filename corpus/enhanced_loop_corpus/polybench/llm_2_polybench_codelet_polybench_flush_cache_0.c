#include <stdio.h>

#include <inttypes.h>

extern int cs;
extern double *flush;
extern int i;
extern double tmp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < cs; i += 2)
        tmp += flush[i];
}
