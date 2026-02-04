#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *dfdy;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 15 * 15; i++) {
        if ((i % 2) == 0) {
            dfdy[i] = 0.;
        } else {
            dfdy[i] = 0.;
        }
    }
}
