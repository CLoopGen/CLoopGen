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
    for (x = 0; x < Nparticles; x += 2) {
        if (x + 1 < Nparticles) {
            xe += arrayX[x] * weights[x] + arrayX[x+1] * weights[x+1];
            ye += arrayY[x] * weights[x] + arrayY[x+1] * weights[x+1];
        } else {
            xe += arrayX[x] * weights[x];
            ye += arrayY[x] * weights[x];
        }
    }
}
