#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern int x;
extern double *weights;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
if (Nparticles > 0) {
    for (x = 0; x < Nparticles; x += 2) {
        weights[x] = 1 / ((double)(Nparticles));
        if (x + 1 < Nparticles) {
            weights[x + 1] = 1 / ((double)(Nparticles));
        }
    }
}
}
