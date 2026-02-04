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
    for (x = 0; x < Nparticles; x++) {
        if (x % 2 == 0) {
            arrayX[x] = xe;
        } else {
            arrayX[x] = xe + 1.0;
        }
        arrayY[x] = ye;
    }
}
