#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern int x;
extern double *weights;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    double inv_N = 1.0 / ((double)(Nparticles));
    for (x = 0; x < Nparticles; x += 2) {
        weights[x] = inv_N;
        if (x + 1 < Nparticles) {
            weights[x + 1] = inv_N;
        }
    }
}
