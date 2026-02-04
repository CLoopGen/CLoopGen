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
xe = 0.0;
ye = 0.0;
for (x = 0; x < Nparticles; x++) {
    double wx = arrayX[x] * weights[x];
    double wy = arrayY[x] * weights[x];
    if (wx != 0.0 || wy != 0.0) {
        xe += wx;
        ye += wy;
    }
}
}
