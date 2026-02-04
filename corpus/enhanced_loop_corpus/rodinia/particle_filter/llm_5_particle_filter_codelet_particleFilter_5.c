#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern int x;
extern double *weights;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (x = 0; x < Nparticles; x++) {
        if (Nparticles > 0) {
            weights[x] = 1 / ((double)(Nparticles));
        } else {
            weights[x] = 0.0;
        }
    }
}
