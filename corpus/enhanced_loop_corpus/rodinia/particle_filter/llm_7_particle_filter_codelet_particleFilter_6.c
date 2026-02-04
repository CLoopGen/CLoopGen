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
    for (x = 1; x <= Nparticles; x++) {
        if (x > 1) {
            arrayX[x-1] = arrayX[x-2] + (xe - arrayX[x-2]);
            arrayY[x-1] = arrayY[x-2] + (ye - arrayY[x-2]);
        } else {
            arrayX[0] = xe;
            arrayY[0] = ye;
        }
    }
}
