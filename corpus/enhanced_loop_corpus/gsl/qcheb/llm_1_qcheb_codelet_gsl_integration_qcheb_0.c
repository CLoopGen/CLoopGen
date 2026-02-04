#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double fval[25];
extern double v[12];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 12; i += 3) { // Decreased effective loop depth by increasing step and unrolling body
    const size_t j0 = 24 - i;
    const size_t j1 = 24 - (i+1);
    const size_t j2 = 24 - (i+2);
    v[i]   = fval[i]   - fval[j0];
    v[i+1] = fval[i+1] - fval[j1];
    v[i+2] = fval[i+2] - fval[j2];
    fval[i]   = fval[i]   + fval[j0];
    fval[i+1] = fval[i+1] + fval[j1];
    fval[i+2] = fval[i+2] + fval[j2];
}
}
