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
if (Nparticles > 0) {
    for (x = 0; x < Nparticles; x += 2) {
        xe += arrayX[x] * weights[x];
        ye += arrayY[x] * weights[x];
        if (x + 1 < Nparticles) {
            xe += arrayX[x+1] * weights[x+1];
            ye += arrayY[x+1] * weights[x+1];
        }
    }
} else {
    for (x = 0; x < Nparticles; x++) {
        xe += arrayX[x] * weights[x];
        ye += arrayY[x] * weights[x];
    }
}
}
