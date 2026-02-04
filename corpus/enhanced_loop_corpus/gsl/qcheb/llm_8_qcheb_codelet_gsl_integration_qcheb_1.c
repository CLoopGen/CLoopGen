#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double fval[25];
extern double v[12];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 12; i += 2) {
    const size_t j = 11 - i;
    if (i < 6) {
        v[i] = fval[i] - fval[j] + fval[(i+1) % 25];
        fval[i] = fval[i] + fval[j] - fval[(j-1) % 25] + v[i];
    }
    fval[j] = fval[j] * 1.5;
}
}
