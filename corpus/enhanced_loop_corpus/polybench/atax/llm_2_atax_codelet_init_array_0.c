#include <stdio.h>

#include <inttypes.h>

extern int n;
extern double x[2100];
extern int i;
extern double fn;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then the odd indices)
    int stride = 2;
    for (i = 0; i < n; i += stride)
        x[i] = 1 + ((i) / fn);
    for (i = 1; i < n; i += stride)
        x[i] = 1 + ((i) / fn);
}
