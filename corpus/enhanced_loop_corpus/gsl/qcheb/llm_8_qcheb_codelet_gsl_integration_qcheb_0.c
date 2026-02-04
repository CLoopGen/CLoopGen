#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double fval[25];
extern double v[12];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i++) {
        const size_t j = 24 - i;
        v[i] = fval[i] - fval[j];
        v[11 - i] = fval[11 - i] - fval[i + 13];
        fval[i] = fval[i] + fval[j];
        fval[11 - i] = fval[11 - i] + fval[i + 13];
    }
}
