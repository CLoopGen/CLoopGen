#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern int x;
extern double *weights;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *indices = (int*)malloc(Nparticles * sizeof(int));
    for (int i = 0; i < Nparticles; i++) {
        indices[i] = Nparticles - 1 - i; // reverse access pattern
    }
    for (x = 0; x < Nparticles; x++) {
        weights[indices[x]] = 1 / ((double)(Nparticles));
    }
    free(indices);
}
