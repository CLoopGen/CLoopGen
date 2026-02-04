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
    // Variant 2: Reverse consecutive memory access (process arrays from end to start)
    for (x = Nparticles - 1; x >= 0; x--) {
        xe += arrayX[x] * weights[x];
        ye += arrayY[x] * weights[x];
    }
}
