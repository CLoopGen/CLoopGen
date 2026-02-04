#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern int x;
extern double *weights;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double inv_N = 1.0 / ((double)(Nparticles));
    for (x = 0; x < Nparticles; x++) {
        weights[x] = inv_N;
    }
}
