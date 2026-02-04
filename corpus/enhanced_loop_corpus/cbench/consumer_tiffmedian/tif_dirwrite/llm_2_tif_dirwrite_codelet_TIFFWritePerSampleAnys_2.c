#include <stdio.h>

#include <inttypes.h>

extern double v;
extern double *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then the rest)
    int stride = 2;
    for (i = 0; i < samples; i += stride)
        w[i] = v;
    for (i = 1; i < samples; i += stride)
        w[i] = v;
}
