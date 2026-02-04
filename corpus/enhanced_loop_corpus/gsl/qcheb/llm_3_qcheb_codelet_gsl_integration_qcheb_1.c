#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double fval[25];
extern double v[12];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive access pattern using reverse iteration
    for (i = 5; i < 6 && i >= 0; i--) {
        const size_t j = 12 - i;
        v[5 - i] = fval[i] - fval[j];
        fval[5 - i] = fval[i] + fval[j];
    }
}
