#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern double *out;
extern  double *in;
extern integer len;
extern int i;
extern double coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access
    for (i = len - 1; i >= 0; i--)
        out[i] = coeff * in[i];
}
