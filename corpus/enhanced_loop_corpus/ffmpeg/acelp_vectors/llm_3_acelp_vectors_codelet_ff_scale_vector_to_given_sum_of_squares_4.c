#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern  float *in;
extern  int n;
extern int i;
extern float scalefactor;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse from end to start)
    for (i = n - 1; i >= 0; i--)
        out[i] = in[i] * scalefactor;
}
