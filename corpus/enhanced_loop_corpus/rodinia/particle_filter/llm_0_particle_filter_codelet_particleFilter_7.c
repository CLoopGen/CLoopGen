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
int x1;
for (x1 = 0; x1 < Nparticles; x1++) {
    for (x = x1; x <= x1; x++) {
        xe += arrayX[x] * weights[x];
        ye += arrayY[x] * weights[x];
    }
}
}
