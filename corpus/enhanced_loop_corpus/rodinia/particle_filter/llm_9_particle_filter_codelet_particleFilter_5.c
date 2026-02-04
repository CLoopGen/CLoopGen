#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern int x;
extern double *weights;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double sum = 0.0;
    for (x = 0; x < Nparticles * 2; x++) {
        if (x < Nparticles) {
            weights[x] = 1.0 / ((double)(Nparticles));
            sum += weights[x] * x;
        } else {
            sum += (sum / ((double)(Nparticles)));
        }
    }
}
