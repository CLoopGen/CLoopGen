#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dfdy;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t limit = 15 * 15;
    for (i = 0; i < limit; i += 3) {
        dfdy[i] = 0.;
        if (i + 1 < limit) dfdy[i + 1] = 0.;
        if (i + 2 < limit) dfdy[i + 2] = 0.;
    }
}
