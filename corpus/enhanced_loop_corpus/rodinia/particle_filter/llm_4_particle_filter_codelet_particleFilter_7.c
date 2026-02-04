#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern double xe;
extern double ye;
extern int x;
extern double *weights;
extern double *arrayX;
extern double *arrayY;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (x = 0; x < Nparticles; x++) {
    if (weights[x] > 0.0) {
        xe += arrayX[x] * weights[x];
        ye += arrayY[x] * weights[x];
    }
}
}
