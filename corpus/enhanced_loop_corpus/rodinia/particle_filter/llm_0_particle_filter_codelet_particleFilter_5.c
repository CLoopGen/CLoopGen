#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern int x;
extern double *weights;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 1; i++) {
    for (x = 0; x < Nparticles; x++) {
        weights[x] = 1 / ((double)(Nparticles));
    }
}
}
