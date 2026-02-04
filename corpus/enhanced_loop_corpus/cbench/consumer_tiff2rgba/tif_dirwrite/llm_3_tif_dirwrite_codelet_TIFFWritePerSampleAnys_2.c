#include <stdio.h>

#include <inttypes.h>

extern double v;
extern double *w;
extern int i;
extern int samples;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access from end to start
    for (i = samples - 1; i >= 0; i--)
        w[i] = v;
}
