#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern double fval[25];
extern double v[12];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride
    for (i = 0; i < 6; i += 2) {
        const size_t j = 12 - i;
        v[i] = fval[i] + fval[j];        // swapped operation order
        fval[i] = fval[i] - fval[j];
        if (i + 1 < 6) {
            const size_t j_next = 12 - (i + 1);
            v[i + 1] = fval[i + 1] + fval[j_next];
            fval[i + 1] = fval[i + 1] - fval[j_next];
        }
    }
}
