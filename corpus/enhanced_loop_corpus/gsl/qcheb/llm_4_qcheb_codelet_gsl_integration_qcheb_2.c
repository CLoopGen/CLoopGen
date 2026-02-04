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
        const size_t j = 6 - i;
        if (fval[i] >= fval[j]) {
            v[i] = fval[i] - fval[j];
        } else {
            v[i] = 0.0;
        }
        fval[i] = fval[i] + fval[j];
    }
}
