#include <stdio.h>

#include <inttypes.h>

extern double *vec;
extern int n;
extern double scale;
extern int x;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in two passes)
    int i;
    for (i = 0; i < n; i += 2)
        vec[i] *= scale;
    for (i = 1; i < n; i += 2)
        vec[i] *= scale;
}
