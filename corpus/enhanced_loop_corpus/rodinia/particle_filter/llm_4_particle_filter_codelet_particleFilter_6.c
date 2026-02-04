#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int Nparticles;
extern double xe;
extern double ye;
extern int x;
extern double *arrayX;
extern double *arrayY;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (Nparticles <= 0) return;
    for (x = 0; x < Nparticles; x++) {
        arrayX[x] = xe;
        arrayY[x] = ye;
    }
}
