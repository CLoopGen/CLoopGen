#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dfdy;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 15 * 15; i += 2) {
        dfdy[i] = 0.;
        if (i + 1 < 15 * 15) {
            dfdy[i + 1] = dfdy[i]; // Introduces RAW dependency: read dfdy[i] after write
        }
    }
}
