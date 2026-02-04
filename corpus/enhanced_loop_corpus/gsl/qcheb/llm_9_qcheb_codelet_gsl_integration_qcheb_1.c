#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double fval[25];
extern double v[12];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 3; i++) {
    const size_t j1 = 12 - i;
    const size_t j2 = 11 - i;
    const size_t j3 = 10 - i;
    v[i]           = (fval[i] - fval[j1]) * 0.5;
    v[i + 3]       = (fval[j2] - fval[j3]) * 0.5;
    fval[i]        = fval[i] + fval[j1] + fval[j2];
    fval[12 - i]   = fval[12 - i] * 2.0;
}
}
