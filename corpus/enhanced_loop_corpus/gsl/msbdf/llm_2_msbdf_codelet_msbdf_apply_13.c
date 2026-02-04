#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * hprev;
extern size_t * ordprev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in reverse)
    // We assume the arrays are at least of size 5 for safety.
    // Here, we modify the access pattern to use a stride of 2
    size_t stride = 2;
    for (i = ((5 - 1) / stride) * stride; i > 0; i -= stride) {
        if (i >= 1) {
            hprev[i] = hprev[i - 1];
            ordprev[i] = ordprev[i - 1];
        }
    }
}
