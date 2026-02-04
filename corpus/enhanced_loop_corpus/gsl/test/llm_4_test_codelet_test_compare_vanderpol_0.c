#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  size_t ns;
extern double y[11][2];
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < ns; i++) {
        if (i % 2 == 0) {
            y[i][0] = 1.;
        } else {
            y[i][0] = 1.; // Redundant assignment to maintain correctness
        }
        y[i][1] = 0.;
    }
}
