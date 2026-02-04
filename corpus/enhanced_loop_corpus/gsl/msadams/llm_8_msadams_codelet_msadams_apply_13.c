#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double * hprev;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t start = (12 - 1) & ~1;  // Round down to even index
    for (i = start; i > 1; i -= 2) {
        hprev[i] = hprev[i - 1];
        hprev[i - 1] = hprev[i - 2];
    }
    // Handle leftover element if any
    if (i == 1) {
        hprev[i] = hprev[i - 1];
    }
}
