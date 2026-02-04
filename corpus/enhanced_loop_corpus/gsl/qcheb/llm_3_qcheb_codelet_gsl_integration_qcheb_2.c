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
    const size_t idx1 = i * 2;          
    const size_t idx2 = (6 - i) * 2;    
    v[i] = fval[idx1] - fval[idx2];
    fval[idx1] = fval[idx1] + fval[idx2];
}
}
