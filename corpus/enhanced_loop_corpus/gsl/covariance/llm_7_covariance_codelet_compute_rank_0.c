#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern size_t i;
extern size_t j;
extern size_t k;
extern double rank;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double local_accum = 0.0;
    for (k = i; k < j; ++k) {
        local_accum += k + 1.;
        rank = local_accum; // WAW dependency introduced: rank is overwritten each iteration
    }
}
