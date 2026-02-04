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
    // Variant 1: Strided memory access with stride of 2
    for (x = 0; x < Nparticles; x += 2) {
        arrayX[x] = xe;
        arrayY[x] = ye;
    }
    // Handle odd Nparticles if needed in a second pass (remaining element)
    if (Nparticles % 2 == 1) {
        arrayX[Nparticles - 1] = xe;
        arrayY[Nparticles - 1] = ye;
    }
}
