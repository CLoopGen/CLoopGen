#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dfdy;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 15 * 15 * 4; i += 4) {
        dfdy[i] = 0.;
        if (i + 1 < 15 * 15 * 4) dfdy[i + 1] = 0.;
        if (i + 2 < 15 * 15 * 4) dfdy[i + 2] = 0.;
        if (i + 3 < 15 * 15 * 4) dfdy[i + 3] = 0.;
    }
}
