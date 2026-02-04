#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern int x;
extern double *weights;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_weight = 0.0;
    for (x = 0; x < Nparticles; x++) {
        temp_weight += 1.0 / ((double)(Nparticles));
        weights[x] = temp_weight;
    }
}
